//
// Created by nisan on 12/14/18.
//

#ifndef MAINPROJ_CONDITIONPARSER_H
#define MAINPROJ_CONDITIONPARSER_H

#include "Command.h"

class Lexer;

class ConditionParser : public Command {
protected:
    string condition;
    vector<string> text;
    map<string, double> *symbols;
    map<string, string> *binds;
    map<string, bool> *con;
    int pos;
    int endOfLoopIndex;
    list<Expression *> myCommands;

public:
    // only the sons implement.
    virtual int doCommand(vector<string> &, int pos);

    explicit ConditionParser(map<string, bool> &con, vector<string> &, map<string, double> &, map<string, string> &,
                             int pos);

    void makeMeCommands();

    int getCond(int pos);

    //checks if the conditions is met.
    virtual bool checkCondition();

    virtual bool bigger(double, double);

    virtual bool smaller(double, double);

    virtual bool equal(double, double);

    virtual bool notEqual(double, double);

    virtual bool notZero(double);

    virtual bool biggerOrEqual(double, double);

    virtual bool smallerOrEqual(double, double);

    virtual string deleteUnimportant(string condition);

    ~ConditionParser();
};


#endif //MAINPROJ_CONDITIONPARSER_H
