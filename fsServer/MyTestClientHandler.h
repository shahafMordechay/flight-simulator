#ifndef FSSERVER_MYTESTCLIENTHANDLER_H
#define FSSERVER_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "GenClientHandler.h"

#define ROW_SIZE 256

template <class Problem, class Solution>
class MyTestClientHandler :  public GenClientHandler<string, string> {
public:
    MyTestClientHandler(Solver<Problem, Solution> *solver) : GenClientHandler(solver){}
    void handleClient(istream &input, ostream &output) override{
        char line[ROW_SIZE];
        input.getline(line, ROW_SIZE);

        while (line[0] != '\0' && string(line) != "end") {
            string str(line);
            cout << solver->solve(str) << endl;
            input.getline(line, ROW_SIZE);
        }
    }
};


#endif //FSSERVER_MYTESTCLIENTHANDLER_H
