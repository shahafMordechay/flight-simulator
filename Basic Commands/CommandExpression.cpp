//
// Created by nisan on 12/18/18.
//

#include <algorithm>
#include "CommandExpression.h"

double CommandExpression::calculate() throw() {
    // if wanted num of params is known
   // if (this->numOfParams != -1) {
    //    string params[this->numOfParams];
     //   for (int i = 0; i < this->numOfParams; i++) {
      //      int j = 0;
      //      while (!isOperand(this->params[ + j]) && isOperand(this->params[ + j + 1])) {
      //          params[i] += this->params[0];
      //          j++;
     //       }
     //   }
        return (this->myCommand->doCommand(this->params));
    }

CommandExpression::CommandExpression(Command *c, vector<string> &params, int numOfParams) {
    // my command
    this->myCommand = c;
    // command params
    this->params = params;
    //num of params to my command.
    this->numOfParams = numOfParams;

}

bool CommandExpression::isOperand(string val) {
    return (val == "+" || val == "-" || val == "*" || val == "/");
}
