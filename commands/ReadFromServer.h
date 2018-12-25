//
// Created by nisan on 12/21/18.
//

#ifndef MAINPROJ_READFROMSERVER_H
#define MAINPROJ_READFROMSERVER_H

#include <map>
#include <string.h>
#include <stddef.h>
#include <vector>
#include "Command.h"

using namespace std;

class ReadFromServer {
public:
    static void updateValues(map<string, string>
                             &varsAndPaths,
                             vector<pair<string, double>> &simulatorData, map<string, double>
                             &myData);

    static void updateValMap(const char *input, vector<pair<string, double>> &simulatorData);

    static void changeSymbolT(map<string, bool> &con, vector<string> &params, int pos, map<string, string> &binded,
                              map<string, double> &symbols, double value);

    static string setMgs(string name,map<string, bool> &con, map<string, string> &paths, map<string, double> &val);
};


#endif //MAINPROJ_READFROMSERVER_H
