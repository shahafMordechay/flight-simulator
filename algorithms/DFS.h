//
// Created by nisan on 1/12/19.
//

#ifndef FLIGHTSIMULATOR_DFS_H
#define FLIGHTSIMULATOR_DFS_H


#include <stack>
#include <queue>
#include "Searcher.h"
#include "Entry.h"

template<class Solution>
class DFS : public Searcher<class Entry, string> {
    //pr queue.
    vector<State<Entry> *> movingDeep;
public:
    State<Entry> *popOpenList() override {
        State<Entry> *top = this->movingDeep.back();
        this->movingDeep.pop_back();
        return top;
    }

    int openListSize() override {
        return (int) (this->movingDeep.size());
    }

    virtual bool exists(State<Entry> *wanted) {
        // make copy of my queue.
        vector<State<Entry> *> copy = this->movingDeep;
        // while still contains elements keep pop.
        while (!copy.empty()) {
            // if exists.
            if (wanted->getState() == (copy.back())->getState())
                return true;
            copy.pop_back();
        }
        //no element equals.
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

    string search(ISearchable<Entry> *searchable) override {
        this->evaluatedNodes = 0;
        this->waySum = 0;
        //push start point.
        this->movingDeep.push_back(searchable->getInitialState());
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
                // if not visited yet and not in my pr queue.
                if ((closed.find(*son) == closed.end()) && (!exists(son))) {
                    // push to my queue.
                    this->movingDeep.push_back(son);
                }
            }
            //set father as the node worked on before.
            if (!this->movingDeep.empty())
                this->movingDeep.back()->setCameFrom(current);
        }
        // clean queue before answer.
        deletePtrs();
        // no possible solution.
        return NULL;
    }

    DFS() {
    }

    ~DFS() {
        while (!this->movingDeep.empty())
            this->movingDeep.pop_back();
        delete (this->movingDeep);
    }

    void deletePtrs() {
        while (openListSize() > 0)
            this->movingDeep.pop_back();
    }
};


#endif //FLIGHTSIMULATOR_DFS_H
