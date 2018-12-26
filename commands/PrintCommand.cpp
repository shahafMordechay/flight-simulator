//
// Created by nisan on 12/14/18.
//

#include "PrintCommand.h"

int PrintCommand::doCommand(vector<string> &params) {
    int howmany = 0;
    string toPrint;
    // print just string
    if (params[pos][0] == '\"') {
        while (params[pos + howmany] != "lineEnd") {
            toPrint += params[pos + howmany];
            howmany++;
            if (params[pos + howmany] != "lineEnd") {
                toPrint += " ";
            }
        }
        // cut ".
        toPrint = toPrint.substr(1, toPrint.length() - 2);
        printf("%s\n", toPrint.c_str());
        // existing var
    } else if (*this->symbolTable->find(params[pos]) != *this->symbolTable->end()) {
        howmany++;
        printf("%lf\n", this->symbolTable->at(params[pos]));
    } else {
        throw "no such var";
    }
    return howmany;
}

PrintCommand::PrintCommand(map<string, double> &symbol, int pos) {
    this->symbolTable = &symbol;
    this->pos = pos;
}
