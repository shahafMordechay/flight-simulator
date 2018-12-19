//
// Created by nisan on 12/14/18.
//

#ifndef MAINPROJ_CONDITIONPARSER_H
#define MAINPROJ_CONDITIONPARSER_H


#include "Command.h"

class ConditionParser : public Command{
public:
    vector<string> condition;
    vector<string>text;
    int pos;
    list<Command*> myCommands;

    // only the sons implement.
    virtual int doCommand(vector<string>&, int pos);
    explicit ConditionParser(vector<string>&,int pos);
    void getCond();
    //checks if the conditions is met.
    virtual bool checkCondition();
};


#endif //MAINPROJ_CONDITIONPARSER_H
