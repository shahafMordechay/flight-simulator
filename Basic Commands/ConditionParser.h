//
// Created by nisan on 12/14/18.
//

#ifndef MAINPROJ_CONDITIONPARSER_H
#define MAINPROJ_CONDITIONPARSER_H


#include "Command.h"

class ConditionParser : public Command{
public:
    list<Command*> myCommands;
    // only the sons implement.
    virtual int doCommand(vector<string>&, int pos) = 0;
    ConditionParser();
    //checks if the conditions is met.
    virtual bool checkCondition(vector<string> cond);
};


#endif //MAINPROJ_CONDITIONPARSER_H
