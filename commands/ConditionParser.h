//
// Created by nisan on 12/14/18.
//

#ifndef MAINPROJ_CONDITIONPARSER_H
#define MAINPROJ_CONDITIONPARSER_H

#include "Command.h"

class Lexer;

class ConditionParser : public Command {
    vector<string> condition;
    vector<string> text;
    map<string, double> *symbols;
    map<string, string> *binds;
    int pos;
    int endOfLoopIndex;
    list<Command *> myCommands;
    map<string, bool (ConditionParser::*)(double, double)> mapFunc;
    Lexer *myLex;

public:
    // only the sons implement.
    virtual int doCommand(vector<string> &, int pos);

    explicit ConditionParser(vector<string> &, map<string, double> &, map<string, string> &, int pos);

    void makeMeCommands();

    int getCond(int pos);

    //checks if the conditions is met.
    virtual bool checkCondition();

    virtual bool checkOperand(string c);

    virtual bool bigger(double, double);

    virtual bool smaller(double, double);

    virtual bool equal(double, double);

    virtual bool notEqual(double, double);

    virtual bool notZero(double, double);

    virtual bool biggerOrEqual(double, double);

    virtual bool smallerOrEqual(double, double);
};


#endif //MAINPROJ_CONDITIONPARSER_H
