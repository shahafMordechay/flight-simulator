//
// Created by nisan on 12/14/18.
//

#ifndef MAINPROJ_PRINTCOMMAND_H
#define MAINPROJ_PRINTCOMMAND_H


#include "Command.h"
#include <map>

class PrintCommand: public Command {
public:
    map<string, double> symbolTable;
    virtual int doCommand(vector<string>&, int pos);
    PrintCommand(map<string, double> &);
};


#endif //MAINPROJ_PRINTCOMMAND_H
