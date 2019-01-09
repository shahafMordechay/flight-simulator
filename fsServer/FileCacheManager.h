#ifndef FSSERVER_FILECACHEMANAGER_H
#define FSSERVER_FILECACHEMANAGER_H

#include <unordered_map>
#include "CacheManager.h"

using namespace std;

template <class Problem, class Solution>
class FileCacheManager : public CacheManager<Problem, Solution> {
    unordered_map<Problem*, Solution*> solutions;
public:

    bool containSolution(Problem *problem) {
        return !(solutions.find(problem) == solutions.end());

    }

    Solution* getSolution(Problem *problem) {
        if (containSolution(problem)) {
            return this->solutions.at(problem);
        }

        return nullptr;
    }

    void saveSolution(Problem *problem, Solution *solution) {
        pair<Problem*, Solution*> tempPair(problem, solution);
        solutions.insert(tempPair);
    }

};


#endif //FSSERVER_FILECACHEMANAGER_H
