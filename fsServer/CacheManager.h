//
// Created by shahaf on 1/2/19.
//

#ifndef FSSERVER_CACHEMANAGER_H
#define FSSERVER_CACHEMANAGER_H

template <class Problem, class Solution>
class CacheManager {
public:
    virtual bool haveSolution(Problem problem)=0;
    virtual Solution getSolution(Problem problem)=0;
    virtual void saveSolution(Problem problem)=0;
};

#endif //FSSERVER_CACHEMANAGER_H
