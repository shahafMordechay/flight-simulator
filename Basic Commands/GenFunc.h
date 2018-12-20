//
// Created by nisan on 12/20/18.
//

#ifndef MAINPROJ_GENFUNC_H
#define MAINPROJ_GENFUNC_H


#include <queue>
#include <string>
#include "Expression.h"

class GenFunc {
public:
    static queue<string> shuntingYard(string &mathExp);     // convert infix math expression to postfix
    static Expression* expFromPostfix(string &mathExp);
    static double evaluate(string &mathExp);

};


#endif //MAINPROJ_GENFUNC_H
