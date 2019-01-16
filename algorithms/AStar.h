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
        this->Astar = vector<State<Entry> *>();
    }

    State<Entry> *popOpenList() override {
        State<Entry> *front = this->Astar.front();
        // iterate over vector.
        int i = 0;
        int j = 0;
        for (State<Entry> *entry : this->Astar) {
            // other entry in my queue that is better.
            if ((estCost(front) + getDistance(front)) >
            (estCost(entry) + getDistance(entry))) {
                // make it my top.
                front = entry;
                // better position.
                j = i;
            }
            i++;
        }
        // erase best from my queue.
        this->Astar.erase(this->Astar.begin() + j);
        // shrink it.
        this->Astar.shrink_to_fit();
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
                        State<Entry> *best = popOpenList();
                        if (estCost(son) + getDistance(son) <
                            estCost(best) + getDistance(best)) {
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
        return "-1";
    }


// estimation.
    double estCost(State<Entry> *enter) {
        return abs(enter->getState().getRow() - this->goal->getState().getRow()) +
               abs(enter->getState().getCol() - this->goal->getState().getCol());
    }

    void deletePtrs() {
        this->Astar.clear();
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
