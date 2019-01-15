
#ifndef FLIGHTSIMULATOR_MYCLIENTHANDLER_H
#define FLIGHTSIMULATOR_MYCLIENTHANDLER_H

#include <vector>

#include "GenClientHandler.h"
#include "../problems/Matrix.h"

class MyClientHandler : public GenClientHandler<Matrix, string> {
public:
    MyClientHandler(Solver<Matrix, string> solver) : GenClientHandler(&solver) {}

    void handleClient(istream &input, ostream &output) {
        vector<string> matrixVector;
        char line[ROW_SIZE];
        input.getline(line, ROW_SIZE);

        while (line[0] != '\0' && string(line) != "end") {

            matrixVector.emplace_back(line);

            input.getline(line, ROW_SIZE);
        }

        if (!matrixVector.empty()) {
            string exit = matrixVector.back();
            matrixVector.pop_back();
            string entrance = matrixVector.back();
            matrixVector.pop_back();
            Matrix matrix(matrixVector, entrance, exit);

            if (!cachMan->containSolution(&matrix)) {
                string solution = solver->solve(matrix);
                output << solution << endl;
                cachMan->saveSolution(&matrix, &solution);

            } else {
                string solution = *cachMan->getSolution(&matrix);
                output << solution << endl;
            }
        }
    }
};


#endif //FLIGHTSIMULATOR_MYCLIENTHANDLER_H
