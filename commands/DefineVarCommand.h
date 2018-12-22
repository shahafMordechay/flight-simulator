//
// Created by nisan on 12/14/18.
//

#ifndef MAINPROJ_DEFINEVARCOMMAND_H
#define MAINPROJ_DEFINEVARCOMMAND_H


#include "Command.h"
#include <map>

class DefineVarCommand: public Command {
    int pos;
    map<string, double> *symbolTable;

public:
    virtual int doCommand(vector<string>&);
    DefineVarCommand(map<string, double>&symbols,int pos);
};


#endif //MAINPROJ_DEFINEVARCOMMAND_H
