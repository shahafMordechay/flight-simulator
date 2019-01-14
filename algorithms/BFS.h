//
// Created by nisan on 1/12/19.
//

#ifndef FLIGHTSIMULATOR_BFS_H
#define FLIGHTSIMULATOR_BFS_H

#include <queue>
#include <unordered_set>
#include "Entry.h"
#include "Searcher.h"

template<class Solution>
class BFS : public Searcher<class Entry, string> {
    //pr queue.
    queue<State<Entry>*> movingBreath;
public:
    BFS() {
        this->movingBreath = queue<State<Entry>*>();
    }

    State<Entry>* popOpenList() {
        this->evaluatedNodes++;
        State<Entry>* front = this->movingBreath.front();
        this->movingBreath.pop();
        return front;
    }

    int openListSize() {
        return (int) this->movingBreath.size();
    }

    bool exists(State<Entry> *wanted) {
        // make copy of my queue.
        queue<State<Entry>*> copy = this->movingBreath;
        // while still contains elements keep pop.
        while (!copy.empty()) {
            // if exists.
            if (*wanted == *(copy.front()))
                return true;
            copy.pop();
        }
        //no element equals.
        return false;
    }

    string backTrace(State<Entry>* target) {
        string mySol = "";
        while (target->getCameFrom() != nullptr) {
            // concat string
            mySol = target->getState().fromWhere(target->getCameFrom()->getState()) + ", " + mySol;
            // go back.
            target = target->getCameFrom();
        }
        // cut last ", "
        mySol = mySol.substr(0, mySol.length() - 2);
        return mySol;
    }

    string search(ISearchable<Entry> *searchable) {
        //push first.
        this->movingBreath.push(searchable->getInitialState());
        //already visited.
        map<State<Entry>,Entry> closed;
        //still entries to check.
        while (openListSize() > 0) {
            //get first in the line.
            State<Entry>* current = popOpenList();
            // mark as visited
            closed.insert({*current,current->getState()});
            // target state.
            if (*current == *(searchable->getGoalState()))
                return backTrace(current);
            // get all possible directions.
            list<State<Entry>*> mySons = searchable->getAllPossibleStates(*current);
            for (State<Entry>* son: mySons) {
                // if not visited yet and not in my pr queue.
                if ((closed.find(*son) == closed.end()) && (!exists(son)) && (son->getCost() != -1)) {
                    // set father
                    son->setCameFrom(current);
                    // push to my queue.
                    this->movingBreath.push(son);

                }
            }
        }
        // no possible solution.
        return NULL;
    }
};


#endif //FLIGHTSIMULATOR_BFS_H
