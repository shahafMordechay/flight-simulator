//
// Created by nisan on 1/12/19.
//

#ifndef FLIGHTSIMULATOR_SEARCHER_H
#define FLIGHTSIMULATOR_SEARCHER_H

#include "ISearcher.h"
#include "../problems/ISearchable.h"
#include <string>
#include <map>
#include <algorithm>

template<class T, class Solution>
class Searcher : public ISearcher<T, Solution> {
protected:
    int evaluatedNodes{};
    int waySum{};
public:
    Searcher() {
        this->evaluatedNodes = 0;
    }

    virtual int openListSize() = 0;

    virtual Solution search(ISearchable<T> *searchable) = 0;

    virtual State<T>* popOpenList() = 0;

    int getNumberOfNodesEvaluated() {
        return this->evaluatedNodes;

    }
    int getWaySum(){
        return this->waySum;
    }

    virtual void deletePtrs()=0;

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
        mySol = mySol.substr(0, mySol.length() - 2) + "\n";
        // clean queue before answer.
        deletePtrs();
        return mySol;
    }
};


#endif //FLIGHTSIMULATOR_SEARCHER_H
