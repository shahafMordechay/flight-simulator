//
// Created by shahaf on 12/22/18.
//

#ifndef FLIGHTSIMULATOR_GENFUNC_H
#define FLIGHTSIMULATOR_GENFUNC_H

#include <string>
#include <map>
using namespace std;

class GenFunc {
public:
    static bool isOperator(char sign);
    static bool isNumber(string &str);
    static string replaceByVal(string var,map<string,double >&symbols);
    static bool isSimulatorVar(map<string,string> &paths, string var);
    static string getPath(map<string,string> &paths, string var);

};


#endif //FLIGHTSIMULATOR_GENFUNC_H
