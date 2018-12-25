//
// Created by nisan on 12/14/18.
//

#ifndef MAINPROJ_IFCOMMAND_H
#define MAINPROJ_IFCOMMAND_H


#include "ConditionParser.h"

class IfCommand : public ConditionParser {
    int pos;

public:
    virtual int doCommand(vector<string> &);

    IfCommand(map<string,bool>&,vector<string> &, map<string, string> &, map<string, double> &, int pos);
};


#endif //MAINPROJ_IFCOMMAND_H
