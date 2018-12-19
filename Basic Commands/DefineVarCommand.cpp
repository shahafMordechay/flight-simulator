//
// Created by nisan on 12/14/18.
//

#include "DefineVarCommand.h"

int DefineVarCommand::doCommand(vector<string>&params) {
    string varName = params[pos];
    // first set as '0';
    this->symbolTable->insert({varName,0});
    // read 1 string.
    return 1;
}

DefineVarCommand::DefineVarCommand(map<string, double> &symbol, int pos) {
    this->symbolTable = &symbol;
    this->pos = pos;

}
