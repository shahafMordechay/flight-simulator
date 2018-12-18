//
// Created by nisan on 12/14/18.
//

#ifndef MAINPROJ_DEFINEVARCOMMAND_H
#define MAINPROJ_DEFINEVARCOMMAND_H


#include "Command.h"
#include <map>

class DefineVarCommand: public Command {
public:
    int varStart;
    map<string, double> *symbolTable;
    virtual int doCommand(vector<string>&, int pos);
    DefineVarCommand(map<string, double>&symbols);
};


#endif //MAINPROJ_DEFINEVARCOMMAND_H
