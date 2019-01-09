//
//

#ifndef FSSERVER_GENCLIENTHANDLER_H
#define FSSERVER_GENCLIENTHANDLER_H

#endif //FSSERVER_GENCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "FileCacheManager.h"

template <class Problem, class Solution>
class GenClientHandler : public ClientHandler {
protected:
    Solver<Problem, Solution> *solver;
    CacheManager<Problem, Solution> *cachMan;

public:
    GenClientHandler(Solver<Problem, Solution> *solver) {
        this->solver = solver;
        this->cachMan = new FileCacheManager<Problem, Solution>();
    }

    virtual ~GenClientHandler() {
        free(this->cachMan);
    }
};