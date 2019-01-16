
#ifndef FLIGHTSIMULATOR_SEARCHSOLVER_H
#define FLIGHTSIMULATOR_SEARCHSOLVER_H

#include "../problems/ISearchable.h"
#include "../algorithms/ISearcher.h"
#include "Solver.h"
#include "../problems/Matrix.h"


template <class T, class Solution>
class SearchSolver : public Solver<Matrix, Solution> {
ISearcher<T, Solution> *searcher;

public:
    SearchSolver(ISearcher<T, Solution> *iSearcher) {
        this->searcher = iSearcher;
    }

    Solution solve(Matrix *problem) {
        Solution solution = this->searcher->search(problem);
        return solution;

    }
};

#endif //FLIGHTSIMULATOR_SEARCHSOLVER_H
