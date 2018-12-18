//
// Created by nisan on 12/18/18.
//

#ifndef MAINPROJ_COMMANDEXPRESSION_H
#define MAINPROJ_COMMANDEXPRESSION_H


#include "Command.h"
#include "Expression.h"

class CommandExpression: public Expression {
public:
    int varStart;
    vector<string> params;
    Command *myCommand;
    int numOfParams;
    virtual double calculate() throw();
    void setStart(int start);
    bool isOperand(string val);
    CommandExpression(Command*,vector<string> &params, int numOfParams);
};


#endif //MAINPROJ_COMMANDEXPRESSION_H
