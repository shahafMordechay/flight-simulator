//
// Created by nisan on 12/21/18.
//

#include "ReadFromServer.h"

void ReadFromServer::updateValues(map<string, string> &varsAndPaths, vector<pair<string, double>> &simulatorData,
                                  map<string, double> &myData) {
    //for every path from simulator check if existing in bind table.
    for (auto &path: simulatorData) {
        // check binds table.
        for (auto &var: varsAndPaths) {
            // equal paths.
            if (path.first == var.first) {
                // change val in my table.
                myData.at(var.second) = path.second;
            }
        }
    }

}

void ReadFromServer::updateValMap(char input[256], vector<pair<string, double>> &simulatorData) {
    double vals[23];
    char *running = strdupa(input);
    const char separator[] = ",";
    for (int i = 0; i < 23; i++) {
        vals[i] = atof(strsep(&running, separator));
    }
    int index = 0;
    // update my vector
    for (auto &path: simulatorData) {
        path.second = vals[index];
        index++;
    }
}
