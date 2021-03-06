//
//

#ifndef FSSERVER_GENCLIENTHANDLER_H
#define FSSERVER_GENCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "FileCacheManager.h"

#define ROW_SIZE 256
#define PROBLEMS "saved_problems.txt"
#define SOLUTIONS "saved_solutions.txt"

template <class Problem, class Solution>
class GenClientHandler : public ClientHandler {
protected:
    Solver<Problem, Solution> *solver;
    CacheManager *cachMan;

public:
    GenClientHandler(Solver<Problem, Solution> *solver) {
        this->solver = solver;
        this->cachMan = new FileCacheManager(PROBLEMS, SOLUTIONS);
    }

    virtual void handleClient(int socket)=0;

    virtual ~GenClientHandler() {
        free(this->cachMan);
    }
};

#endif //FSSERVER_GENCLIENTHANDLER_H