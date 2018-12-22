//
// Created by nisan on 12/21/18.
//

#ifndef MAINPROJ_READFROMSERVER_H
#define MAINPROJ_READFROMSERVER_H

#include <map>
#include <string.h>
#include <stddef.h>
#include <vector>

using namespace std;

class ReadFromServer {
public:
    static void updateValues(map<string, string>
                             &varsAndPaths,
                             vector<pair<string, double>> &simulatorData, map<string, double>
                             &myData);

    static void updateValMap(char input[256], vector<pair<string, double>> &simulatorData);

};


#endif //MAINPROJ_READFROMSERVER_H
