//
// Created by shahaf on 12/22/18.
//

#ifndef FLIGHTSIMULATOR_GENFUNC_H
#define FLIGHTSIMULATOR_GENFUNC_H

#include <string>

using namespace std;

class GenFunc {
public:
    static bool isOperator(char sign);
    static bool isNumber(string &str);
};


#endif //FLIGHTSIMULATOR_GENFUNC_H
