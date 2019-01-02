//
// Created by shahaf on 1/2/19.
//

#ifndef FSSERVER_MYTESTCLIENTHANDLER_H
#define FSSERVER_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

class MyTestClientHandler :  public ClientHandler{
    Solver<string, string> *solver;
    CacheManager<string, string> *cachMan;
public:
    void handleClient(istream input, ostream output) override;
};


#endif //FSSERVER_MYTESTCLIENTHANDLER_H
