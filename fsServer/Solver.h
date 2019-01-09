#ifndef FSSERVER_SOLVER_H
#define FSSERVER_SOLVER_H

#include <string>

using namespace std;

template <class Problem, class Solution>
class Solver {
public:
    virtual Solution solve(Problem &problem)=0;
};
#endif //FSSERVER_SOLVER_H
