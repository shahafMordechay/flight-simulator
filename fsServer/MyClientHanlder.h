
#ifndef FLIGHTSIMULATOR_MYCLIENTHANLDER_H
#define FLIGHTSIMULATOR_MYCLIENTHANLDER_H

#include <unistd.h>
#include <sys/socket.h>
#include "GenClientHandler.h"
#include "../problems/Matrix.h"

class MyClientHandler : public GenClientHandler<Matrix, string> {

public:
    MyClientHandler(Solver<Matrix, string> *solver) : GenClientHandler(solver){}

    void handleClient(int socket) {
        vector<string> matrixVector;
        char line[ROW_SIZE];

        while (read(socket, line, ROW_SIZE) > 0 && string(line).substr(0, 3) != "end") {

            string temp = line, splitted = "";
            for (int i = 0; i < temp.length(); ++i) {
                bool isWhiteSpace = (temp[i] == '\r' || temp[i] == '\n');

                if (!isWhiteSpace) {
                    splitted += temp[i];
                }

                if (isWhiteSpace && splitted == "end") {
                    break;
                } else if (isWhiteSpace && splitted != "") {
                    matrixVector.emplace_back(splitted);
                    splitted = "";
                }
            }

            if (splitted == "end") {
                break;
            }
        }

        if (!matrixVector.empty()) {
            string exit = matrixVector.back();
            matrixVector.pop_back();
            string entrance = matrixVector.back();
            matrixVector.pop_back();
            Matrix matrix(matrixVector, entrance, exit);

            if (!cachMan->containSolution(to_string(matrix))) {
                string solution = solver->solve(&matrix);
                send(socket, solution.c_str(), solution.length(), 0);
                cachMan->saveSolution(to_string(matrix), solution);

            } else {
                string solution = cachMan->getSolution(to_string(matrix));
                send(socket, solution.c_str(), solution.length(), 0);
            }
        }
    }
};

#endif //FLIGHTSIMULATOR_MYCLIENTHANLDER_H
