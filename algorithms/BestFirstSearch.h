//
// Created by nisan on 1/12/19.
//

#ifndef FLIGHTSIMULATOR_BESTFIRSTSEARCH_H
#define FLIGHTSIMULATOR_BESTFIRSTSEARCH_H

#include "Searcher.h"
#include "Entry.h"
#include "Searcher.h"
#include <queue>

template<class Solution>
class BestFirstSearch : public Searcher<class Entry, Solution> {
    vector<State<Entry> *> movingBest;
    //pr queue.
public:
    BestFirstSearch() {
        this->movingBest = vector<State<Entry> *>();
    }

    State<Entry> *popOpenList() override {
        this->evaluatedNodes++;
        State<Entry> *front = this->movingBest.front();
        // iterate over vector.
        int i = 0;
        int j = 0;
        for (State<Entry> *entry : this->movingBest) {
            // other entry in my queue that is better.
            if (front->getCost() > entry->getCost()) {
                // make it my top.
                front = entry;
                // better position.
                j = i;
            }
            i++;
        }
        // erase best from my queue.
        this->movingBest.erase(this->movingBest.begin() + j);
        // shrink it.
        this->movingBest.shrink_to_fit();
        // return best.
        return front;
    }

    int openListSize() override {
        return (int) (this->movingBest.size());
    }

    virtual bool exists(State<Entry> *wanted) {
        for (State<Entry> *pos : this->movingBest) {
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

    string search(ISearchable<Entry> *searchable) override {
        this->evaluatedNodes = 0;
        // make entry free.
        searchable->getInitialState()->setCost(0);
        //push start point.
        this->movingBest.push_back(searchable->getInitialState());
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
                    this->movingBest.push_back(son);
                }
            }

        }
        // clean queue before answer.
        deletePtrs();
        // no possible solution.
        return NULL;
    }


    void deletePtrs() {
        this->movingBest.clear();
    }
};


#endif //FLIGHTSIMULATOR_BESTFIRSTSEARCH_H
