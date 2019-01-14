#ifndef FLIGHTSIMULATOR_ISEARCHER_H
#define FLIGHTSIMULATOR_ISEARCHER_H

#include "../problems/ISearchable.h"

template<class T, class Solution>
class ISearcher {
    virtual Solution search(ISearchable<T> *searchable) = 0;

    virtual int getNumberOfNodesEvaluated() = 0;
};

#endif //FLIGHTSIMULATOR_ISEARCHER_H
