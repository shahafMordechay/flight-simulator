//
// Created by shahaf on 12/19/18.
//

#ifndef FLIGHTSIMULATOR_GENERALFUNCTIONS_H
#define FLIGHTSIMULATOR_GENERALFUNCTIONS_H


#include "../expressions/Expression.h"

class GenFunc {
public:
    static queue<string> shuntingYard(string &mathExp);     // convert infix math expression to postfix
    static Expression* expFromPostfix(string &mathExp);
    static double evaluate(string &mathExp);
};


#endif //FLIGHTSIMULATOR_GENERALFUNCTIONS_H
