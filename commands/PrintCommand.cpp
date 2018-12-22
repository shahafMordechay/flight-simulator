//
// Created by nisan on 12/14/18.
//

#include "PrintCommand.h"

int PrintCommand::doCommand(vector<string> &params) {
    // print just string
    if (params[pos][0] == '\"') {
        string whatToPrint = params[pos].substr(1, params[pos].length() - 2);
        printf("%s\n", &whatToPrint);
        // existing var
    } else if (*this->symbolTable->find(params[pos]) != *this->symbolTable->end()) {
        printf("%lf\n", this->symbolTable->at(params[pos]));
    } else {
        throw "no such var";
    }
    return 1;
}

PrintCommand::PrintCommand(map<string, double> &symbol, int pos) {
    this->symbolTable = &symbol;
    this->pos = pos;
}
