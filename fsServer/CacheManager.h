#ifndef FSSERVER_CACHEMANAGER_H
#define FSSERVER_CACHEMANAGER_H

#include <map>

using namespace std;

class CacheManager {
public:
    virtual bool containSolution(const string &problem)=0;
    virtual string getSolution(const string &problem)=0;
    virtual void saveSolution(const string problem, const string solution)=0;
    virtual void writeSolutions()=0;
};

#endif //FSSERVER_CACHEMANAGER_H
