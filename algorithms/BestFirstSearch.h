#ifndef FLIGHTSIMULATOR_BESTFIRSTSEARCH_H
#define FLIGHTSIMULATOR_BESTFIRSTSEARCH_H

#include "Entry.h"
#include <queue>
#include "Searcher.h"
template <class Solution>
class BestFirstSearch: public Searcher<class Entry, Solution>{
    priority_queue<State<Entry>> movingBest;

    virtual State<Entry> popOpenList() {
        this->evaluatedNodes++;
        State<Entry> front = this->movingBreath.front();
        this->movingBreath.pop();
        return front;
    }

    virtual int openListSize() {
        return (int) this->movingBest.size();
    }

    virtual bool exists(State<Entry> wanted) {
        // make copy of my queue.
        queue<State<Entry>> copy = this->movingDeep;
        // while still contains elements keep pop.
        while (!copy.empty()) {
            // if exists.
            if (wanted.isSameState(copy.front()))
                return true;
            copy.pop();
        }
        //no element equals.
        return false;
    }

    string backTrace(State<Entry> target) {
        string mySol = "";
        while (target.getCameFrom() != NULL) {
            // concat string
            mySol = target.getState().fromWhere(target.getCameFrom()->getState()) + ", " + mySol;
            // go back.
            target = *target.getCameFrom();
        }
        // cut last ", "
        mySol = mySol.substr(0, mySol.length() - 3);
        return mySol;
    }

public:
    BestFirstSearch() {
        this->movingBest = priority_queue<State<Entry>>();
    }

    virtual string search(ISearchable<Solution> searchable) {

        //push first
        this->movingBest.push(searchable.getInitialState());

        //already visited set
        unordered_set<State<Entry>> closed;

        //still entries to check
        while (openListSize() > 0) {

            //get first in the queue
            State<Entry> current = popOpenList();

            // mark as visited
            closed.insert(current);

            // current is target
            if (current.isSameState(searchable.getGoalState())) {
                return backTrace(current);
            }

            // all possible states from current
            list<State<Entry>> successors = searchable.getAllPossibleStates(current);


            for (State<Entry> successor : successors) {
                if (closed.find(successor) == closed.end() && !exists(successor)) {
                    successor.setCameFrom(&current);
                    this->movingBest.push(successor);
                } else if (successor.getCost() > current.getCost() + 1) {
                    if (!exists(successor)) {
                        successor.setCameFrom(&current);
                        this->movingBest.push(successor);
                    } else {
                        successor.setCost(current.getCost() + 1);
                    }
                }
            }
        }
    }
};



#endif //FLIGHTSIMULATOR_BESTFIRSTSEARCH_H
