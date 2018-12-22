//
// Created by nisan on 12/14/18.
//

#ifndef MAINPROJ_ASSERTIONCOMMAND_H
#define MAINPROJ_ASSERTIONCOMMAND_H


#include "Command.h"

class AssertionCommand: public Command{
    int pos;

public:
    map<string, double> *symbols;
    map<string, string> *binded;
    virtual int doCommand(vector<string>&);

    AssertionCommand(map<string, double > &symbols, map<string, string> &bind, int pos);
};


#endif //MAINPROJ_ASSERTIONCOMMAND_H
