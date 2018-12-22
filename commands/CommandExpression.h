//
// Created by nisan on 12/18/18.
//

#ifndef MAINPROJ_COMMANDEXPRESSION_H
#define MAINPROJ_COMMANDEXPRESSION_H


#include "Command.h"
#include "../expressions/Expression.h"

class CommandExpression: public Expression {
    vector<string> params;
    Command *myCommand;
    int numOfParams;
    int pos;

public:
    virtual double calculate() throw();
    bool isOperand(string val);

    CommandExpression(Command*,vector<string> &params, int numOfParams,int pos);
};


#endif //MAINPROJ_COMMANDEXPRESSION_H
