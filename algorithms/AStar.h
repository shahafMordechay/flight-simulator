//
// Created by nisan on 1/12/19.
//

#ifndef FLIGHTSIMULATOR_ASTAR_H
#define FLIGHTSIMULATOR_ASTAR_H


#include <vector>
#include "Searcher.h"
#include "Entry.h"

template<class Solution>
class AStar : public Searcher<class Entry, string> {

    //pr queue.
    vector<State<Entry> *> Astar;
    State<Entry> *goal{};
public:
    AStar() {
    }

    ~AStar() {
        while (!this->Astar.empty())
            this->Astar.pop_back();
        delete (this->Astar);
        delete (this->goal);
    }

    State<Entry> *popOpenList() override {
        State<Entry> *front = this->Astar.front();
        // iterate over vector.
        int i = 0;
        int j = 0;
        for (State<Entry> *entry : this->Astar) {
            // other entry in my queue that is better.
            if (estCost(entry) < estCost(front)) {
                // make it my top.
                front = entry;
                // better position.
                j = i;
            }
            i++;
        }
        // erase best from my queue.
        State<Entry> *tmp = this->Astar.back();
        this->Astar.back() = this->Astar.at(j);
        this->Astar.at(j) = tmp;
        this->Astar.pop_back();

        // return best.
        return front;

    }

    int openListSize() override {
        return (int) this->Astar.size();
    }

    bool exists(State<Entry> *wanted) {
        for (State<Entry> *pos : this->Astar) {
            if (pos->getState() == wanted->getState())
                return true;
        }
        return false;
    }

    string backTrace(State<Entry> *target) {
        string mySol = "";
        while (target->getCameFrom() != nullptr) {
            // concat string
            mySol = target->getState().fromWhere(target->getCameFrom()->getState()) + ", " + mySol;
            this->waySum += target->getCost();
            // go back.
            target = target->getCameFrom();
        }
        // cut last ", "
        mySol = mySol.substr(0, mySol.length() - 2);
        // clean queue before answer.
        deletePtrs();
        return mySol;
    }

    string search(ISearchable<Entry> *searchable) {
        this->evaluatedNodes = 0;
        this->waySum = 0;
        this->goal = searchable->getGoalState();
        // make entry free.
        searchable->getInitialState()->setCost(0);
        //push start point.
        this->Astar.push_back(searchable->getInitialState());
        //already visited.
        map<State<Entry>, Entry> closed;
        //still entries to check.
        while (openListSize() > 0) {
            //get first in the line.
            State<Entry> *current = popOpenList();
            this->evaluatedNodes++;
            // mark as visited
            closed.insert({*current, current->getState()});
            // target state.
            if (*current == *(searchable->getGoalState()))
                return backTrace(current);
            // get all possible directions.
            list<State<Entry> *> mySons = searchable->getAllPossibleStates(*current);
            for (State<Entry> *son: mySons) {
                // if not visited yet
                if ((closed.find(*son) == closed.end())) {
                    // push to my queue. if not there.
                    if (!exists(son)) {
                        son->setCameFrom(current);
                        this->Astar.push_back(son);
                        // already in queue.
                    } else {
                        // check if better path.
                        State<Entry> *best = popOpenList();
                        if (estCost(son) < estCost(best)) {
                            best->setCameFrom(son);
                        }
                        this->Astar.push_back(best);
                    }
                }

            }

        }
        // clean queue before answer.
        deletePtrs();
        // no possible solution.
        return NULL;
    }


// estimation.
    double estCost(State<Entry> *enter) {
        return getDistance(enter) + abs(enter->getState().getRow() - this->goal->getState().getRow()) +
               abs(enter->getState().getCol() - this->goal->getState().getCol());
    }

    void deletePtrs() {
        while (!Astar.empty())
            this->Astar.pop_back();
        this->goal = nullptr;
    }

    int getDistance(State<Entry> *node) {
        State<Entry> *cpy = node;
        int cost = (int) cpy->getCost();
        while (cpy->getCameFrom() != nullptr) {
            cpy = cpy->getCameFrom();
            cost += (int) cpy->getCost();
        }
        return cost;
    }
};


#endif //FLIGHTSIMULATOR_ASTAR_H
