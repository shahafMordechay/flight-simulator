//
// Created by shahaf on 1/2/19.
//

#ifndef FSSERVER_FILECACHEMANAGER_H
#define FSSERVER_FILECACHEMANAGER_H

#include <map>

#include "CacheManager.h"

using namespace std;

class FileCacheManager : public CacheManager<class Problem, class Solution> {
     map<Problem, Solution> solutions;
public:
    FileCacheManager();
    bool haveSolution(Problem problem)override;
    Solution getSolution(Problem problem)override;
    void saveSolution(Problem problem)override;
};


#endif //FSSERVER_FILECACHEMANAGER_H
