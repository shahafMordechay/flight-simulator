//
// Created by nisan on 12/18/18.
//

#include <algorithm>
#include "CommandExpression.h"

double CommandExpression::calculate() throw() {
    // if wanted num of params is known
    if (this->numOfParams != -1) {
        string params[this->numOfParams];
        for (int i = 0; i < this->numOfParams; i++) {
            int j = 0;
            while (!isOperand(this->params[varStart + j]) && isOperand(this->params[varStart + j + 1])) {
                params[i] += this->params[varStart];
                j++;
            }
        }
        return (this->myCommand->doCommand(this->params, varStart));
    }
}

CommandExpression::CommandExpression(Command *c, vector<string> &params, int numOfParams) {
    // my command
    this->myCommand = c;
    // command params
    this->params = params;
    //start point
    this->varStart = 0;
    //num of params to my command.
    this->numOfParams = numOfParams;

}

void CommandExpression::setStart(int start) {
    this->varStart = start;
}

bool CommandExpression::isOperand(string val) {
    return (val == "+" || val == "-" || val == "*" || val == "/");
}
