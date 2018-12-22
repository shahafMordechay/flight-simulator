//
// Created by shahaf on 12/19/18.
//

#ifndef FLIGHTSIMULATOR_GENERALFUNCTIONS_H
#define FLIGHTSIMULATOR_GENERALFUNCTIONS_H

#include <queue>

#include "Expression.h"

using namespace std;

class MathExpCalc {
public:
    static queue<string> shuntingYard(string &mathExp);
    static Expression* expFromPostfix(queue<string> postfix);
    static double evaluate(string &mathExp);
};


#endif //FLIGHTSIMULATOR_GENERALFUNCTIONS_H
