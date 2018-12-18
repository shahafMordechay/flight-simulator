//
// Created by nisan on 12/14/18.
//

#ifndef MAINPROJ_ASSERTIONCOMMAND_H
#define MAINPROJ_ASSERTIONCOMMAND_H


#include "Command.h"

class AssertionCommand: public Command{
public:
    map<string, double> *symbols;
    map<string, string> *binded;
   virtual int doCommand(vector<string>&, int pos);
   AssertionCommand(map<string, double > &symbols, map<string, string> &bind);
};


#endif //MAINPROJ_ASSERTIONCOMMAND_H
