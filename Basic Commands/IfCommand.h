//
// Created by nisan on 12/14/18.
//

#ifndef MAINPROJ_IFCOMMAND_H
#define MAINPROJ_IFCOMMAND_H


#include "ConditionParser.h"

class IfCommand: public ConditionParser {
public:
    int pos;
    virtual int doCommand(vector<string>&);
    IfCommand(vector<string>&,int pos);
};


#endif //MAINPROJ_IFCOMMAND_H
