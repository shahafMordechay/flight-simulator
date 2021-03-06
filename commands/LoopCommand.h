//
// Created by nisan on 12/8/18.
//

#ifndef MAINPROJ_LOOPCOMMAND_H
#define MAINPROJ_LOOPCOMMAND_H


#include "Command.h"
#include "ConditionParser.h"

class LoopCommand : public ConditionParser {
    int pos;

public:
    virtual int doCommand(vector<string> &);

    LoopCommand(map<string, bool> &con, vector<string> &, map<string, string> &, map<string, double> &, int pos);


};


#endif //MAINPROJ_LOOPCOMMAND_H
