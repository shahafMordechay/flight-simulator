
#ifndef FLIGHTSIMULATOR_SEARCHSOLVER_H
#define FLIGHTSIMULATOR_SEARCHSOLVER_H


#include "../algorithms/ISearcher.h"
#include "Solver.h"

template <class T>
class SearchSolver : Solver<ISearchable<T>, T>{
    ISearcher<T> searcher;

    SearchSolver(ISearcher<T> iSearcher) {
        this->searcher = iSearcher;
    }

    T solve(ISearchable<T> &problem) {
        this->searcher.search(*problem);
    }
};


#endif //FLIGHTSIMULATOR_SEARCHSOLVER_H
