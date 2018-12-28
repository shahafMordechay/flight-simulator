//
// Created by nisan on 12/21/18.
//

#include "ReadFromServer.h"
#include "ConnectCommand.h"
#include "../GenFunc.h"
#include <mutex>

mutex globalMu;

void
ReadFromServer::updateValues(map<string, string> &varsAndPaths, map<string, bool> &con,
                             vector<pair<string, double>> &simulatorData,
                             map<string, double> &myData) {
    //for every path from simulator check if existing in bind table.
    for (auto &path: simulatorData) {
        // check binds table.
        for (auto &var: varsAndPaths) {
            // equal paths. and old val
            if ((path.first == var.second) && !(con.at(var.first))) {
                // change val in my table.
                myData.at(var.first) = path.second;
                break;
            }
        }
    }
    globalMu.unlock();


}

void ReadFromServer::updateValMap(const char *input, vector<pair<string, double>> &simulatorData) {
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

void ReadFromServer::changeSymbolT(map<string, bool> &con, vector<string> &params, int pos, map<string, string> &binded,
                                   map<string, double> &symbols, double value) {
    // update the var in the table.
    for (auto &varName: symbols) {
        if (varName.first == params[pos - 2]) {
            //change val.
            globalMu.lock();
            symbols.at(varName.first) = value;
            // if binded to simulator.
            if (GenFunc::isSimulatorVar(binded, varName.first)) {
                con.at(varName.first) = true;
                // if binded.
            } else if (binded.find(varName.first) != binded.end()) {
                for (auto &path : binded) {
                    // if binded not to the simulator.
                    if ((path.first == varName.first) && (path.second[0] != '/'))
                        symbols.at(path.second) = value;

                }
            }
            globalMu.unlock();

        }
    }


}

string
ReadFromServer::setMgs(string name, map<string, bool> &con, map<string, string> &paths, map<string, double> &val) {
    globalMu.lock();
    string msg = "set " + paths.at(name)
                 + " " + to_string(val.at(name)) + "\r\n";
    globalMu.unlock();
    return msg;
}


