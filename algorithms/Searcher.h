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
    int evaluatedNodes;
public:
    Searcher();
    virtual int openListSize() = 0;

    virtual Solution search(ISearchable<T> *searchable) = 0;

    virtual State<T> popOpenList() = 0;

    int getNumberOfNodesEvaluated();

};


#endif //FLIGHTSIMULATOR_SEARCHER_H
