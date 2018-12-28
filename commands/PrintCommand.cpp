//
// Created by nisan on 12/14/18.
//

#include "PrintCommand.h"

int PrintCommand::doCommand(vector<string> &params) {
    int howmany = 0;
    string toPrint;
    // print just string
    while (params[pos + howmany] != "lineEnd") {
        // existing var.
        if (*this->symbolTable->find(params[pos + howmany]) != *this->symbolTable->end()) {
            toPrint += to_string(this->symbolTable->at(params[pos + howmany]));
            howmany++;
            //its a string.
        } else {
            // skip /".
            // while last char of str isnt end of string.
            while (params[pos + howmany][params[pos + howmany].length() - 1] != '\"') {
                toPrint += params[pos + howmany];
                toPrint += " ";
                howmany++;
            }
            // end of string.
            toPrint += params[pos + howmany];
            // cut unwanted.
            toPrint = toPrint.substr(1, toPrint.length() - 2);
            howmany++;
        }
    }
    printf("%s\n", toPrint.c_str());
    // = inside the string
    if(toPrint.find('=') != string::npos)
        howmany--;
    return howmany;
}

PrintCommand::PrintCommand(map<string, double> &symbol, int pos) {
    this->symbolTable = &symbol;
    this->pos = pos;
}

