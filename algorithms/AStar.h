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
        this->evaluatedNodes++;
        State<Entry> *front = this->Astar.front();
        // iterate over vector.
        int i = 0;
        int j = 0;
        for (State<Entry> *entry : this->Astar) {
            // other entry in my queue that is better.
            if ((front->getCost() + estCost(front)) > (entry->getCost() + estCost(entry))) {
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
            if (*pos == *wanted)
                return true;
        }
        return false;
    }

    string backTrace(State<Entry> *target) {
        string mySol = "";
        while (target->getCameFrom() != nullptr) {
            // concat string
            mySol = target->getState().fromWhere(target->getCameFrom()->getState()) + ", " + mySol;
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
            // mark as visited
            closed.insert({*current, current->getState()});
            // target state.
            if (*current == *(searchable->getGoalState()))
                return backTrace(current);
            // get all possible directions.
            list<State<Entry> *> mySons = searchable->getAllPossibleStates(*current);
            for (State<Entry> *son: mySons) {
                // if not visited yet and not in my pr queue.
                if ((closed.find(*son) == closed.end()) && (!exists(son)) && (son->getCost() != -1)) {
                    // push to my queue.
                    son->setCameFrom(current);
                    this->Astar.push_back(son);
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
        return abs(enter->getState().getRow() - this->goal->getState().getRow()) +
               abs(enter->getState().getCol() - this->goal->getState().getCol());
    }

    void deletePtrs() {
        this->Astar.clear();
        this->goal = nullptr;
    }


};


#endif //FLIGHTSIMULATOR_ASTAR_H
