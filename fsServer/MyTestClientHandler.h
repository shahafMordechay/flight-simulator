#ifndef FSSERVER_MYTESTCLIENTHANDLER_H
#define FSSERVER_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "GenClientHandler.h"

class MyTestClientHandler :  public GenClientHandler<string, string> {
public:
    MyTestClientHandler(Solver<string, string> *solver) : GenClientHandler(solver){}

    void handleClient(istream &input, ostream &output) override{
        char line[ROW_SIZE];
        input.getline(line, ROW_SIZE);

        while (line[0] != '\0' && string(line) != "end") {
            string problem(line);
            if (!cachMan->containSolution(problem)) {
                string solution = solver->solve(problem);
                output << solution << endl;
                cachMan->saveSolution(problem, solution);

            } else {
                string solution = cachMan->getSolution(problem);
                output << solution << endl;
            }
            input.getline(line, ROW_SIZE);
        }

        this->cachMan->writeSolutions();
    }
};


#endif //FSSERVER_MYTESTCLIENTHANDLER_H
