//
// Created by nisan on 12/18/18.
//

#include <algorithm>
#include "CommandExpression.h"

double CommandExpression::calculate() throw() {
        return (this->myCommand->doCommand(this->params));
    }

CommandExpression::CommandExpression(Command *c, vector<string> &params, int numOfParams, int pos) {
    // my command
    this->myCommand = c;
    // command params
    this->params = params;
    //num of params to my command.
    this->numOfParams = numOfParams;
    // start position of command.
    this->pos = pos;

}

bool CommandExpression::isOperand(string val) {
    return (val == "+" || val == "-" || val == "*" || val == "/");
}

