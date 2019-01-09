#ifndef FSSERVER_CACHEMANAGER_H
#define FSSERVER_CACHEMANAGER_H

#include <map>

using namespace std;

template <class Problem, class Solution>
class CacheManager {
public:
    virtual bool containSolution(Problem *problem)=0;
    virtual Solution* getSolution(Problem *problem)=0;
    virtual void saveSolution(Problem *problem, Solution *solution)=0;
};

#endif //FSSERVER_CACHEMANAGER_H
