//
// Created by nisan on 1/12/19.
//

#ifndef FLIGHTSIMULATOR_DFS_H
#define FLIGHTSIMULATOR_DFS_H


#include <stack>
#include "Searcher.h"
#include "Entry.h"

template<class Solution>
class DFS : public Searcher<class Entry, string> {
    //pr queue.
    stack<State<Entry> *> movingDeep;
public:
    State<Entry> *popOpenList() override {
        this->evaluatedNodes++;
        State<Entry> *top = this->movingDeep.top();
        this->movingDeep.pop();
        return top;
    }

    int openListSize() override {
        return (int) (this->movingDeep.size());
    }

    virtual bool exists(State<Entry> *wanted) {
        // make copy of my queue.
        stack<State<Entry> *> copy = this->movingDeep;
        // while still contains elements keep pop.
        while (!copy.empty()) {
            // if exists.
            if (*wanted == *(copy.top()))
                return true;
            copy.pop();
        }
        //no element equals.
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
        //push start point.
        this->movingDeep.push(searchable->getInitialState());
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
                    this->movingDeep.push(son);
                }
            }
            //set father as the node worked on before.
            if (!this->movingDeep.empty())
                this->movingDeep.top()->setCameFrom(current);
        }
        // clean queue before answer.
        deletePtrs();
        // no possible solution.
        return NULL;
    }

    DFS() {
        this->movingDeep = stack<State<Entry> *>();
    }

    void deletePtrs() {
        while (openListSize() > 0)
            this->movingDeep.pop();
    }
};


#endif //FLIGHTSIMULATOR_DFS_H
