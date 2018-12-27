//
// Created by nisan on 12/14/18.
//

#include "DefineVarCommand.h"

int DefineVarCommand::doCommand(vector<string> &params) {
    string varName = params[pos];
    // initialize with zero.
    this->symbolTable->insert({varName, 0});
    this->con->insert({varName, 0});
    return 1;
}

DefineVarCommand::DefineVarCommand(map<string, double> &symbol, map<string, bool> &con, int pos) {
    this->symbolTable = &symbol;
    this->pos = pos;
    this->con = &con;

}


