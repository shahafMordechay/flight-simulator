//
// Created by nisan on 12/14/18.
//

#include "PrintCommand.h"

int PrintCommand::doCommand(vector<string> &params) {
    int read = 0;
    //check if its a valid var
    if (this->symbolTable.find(params[pos]) != this->symbolTable.end()) {
        // print val
        printf("%lf", this->symbolTable.at(params[pos]));
        read++;
        // normal string.
    } else {
        printf("%s", reinterpret_cast<char *>(&params[pos]));

    }
    // how many should step.
    return read;
}

PrintCommand::PrintCommand(map<string, double> &symbol, int pos) {
    this->symbolTable = symbol;
    this->pos = pos;
}
