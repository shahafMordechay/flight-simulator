//
// Created by nisan on 12/14/18.
//

#ifndef MAINPROJ_PRINTCOMMAND_H
#define MAINPROJ_PRINTCOMMAND_H


#include "Command.h"
#include <map>

class PrintCommand: public Command {
    int pos;
    map<string, double> *symbolTable;

public:
    virtual int doCommand(vector<string>&);
    PrintCommand(map<string, double> &, int pos);
};


#endif //MAINPROJ_PRINTCOMMAND_H
