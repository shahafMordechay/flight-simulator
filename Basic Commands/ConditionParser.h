//
// Created by nisan on 12/14/18.
//

#ifndef MAINPROJ_CONDITIONPARSER_H
#define MAINPROJ_CONDITIONPARSER_H


#include "Command.h"
#include "Lexer.h"

class ConditionParser : public Command {
public:
    vector<string> condition;
    vector<string> text;
    map<string, double> *symbols;
    int pos;
    list<Command *> myCommands;
    map<string, void *> operands = {(">", bigger(double, double)), ("<", smaller(double, double)),
                                    ("==", equal(double, double)), ("!=", notEqual(double, double)),
                                    ("", notZero(double))};
    Lexer myLex;

    // only the sons implement.
    virtual int doCommand(vector<string> &, int pos);

    explicit ConditionParser(vector<string> &, map<string, double> &, int pos);

    void getCond();

    //checks if the conditions is met.
    virtual bool checkCondition();

    virtual bool checkOperand(string c);

    virtual bool bigger(double, double);

    virtual bool smaller(double, double);

    virtual bool equal(double, double);

    virtual bool notEqual(double, double);

    virtual bool notZero(double);
};


#endif //MAINPROJ_CONDITIONPARSER_H
