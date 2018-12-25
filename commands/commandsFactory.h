//
// Created by nisan on 12/19/18.
//

#ifndef MAINPROJ_COMMANDSFACTORY_H
#define MAINPROJ_COMMANDSFACTORY_H

#include "CommandExpression.h"
#include "../expressions/Expression.h"
#include "Command.h"
#include "AssertionCommand.h"
#include "DefineVarCommand.h"
#include "ConditionParser.h"
#include "IfCommand.h"
#include "LoopCommand.h"
#include "OpenServerCommand.h"
#include "PrintCommand.h"
#include "ConnectCommand.h"
#include "SleepCommand.h"

class commandsFactory {
    bool *indicator;
    map<string, double> *symbol;
    map<string, string> *bind;
    map<string,bool> *con;
    vector<string> *params;
    map<string, int> commands;

public:
    commandsFactory(map<string,bool>&con,map<string, double> &symbols, map<string, string> &binds, vector<string> &text,
                    bool &indi);

    CommandExpression *assertion(int pos, int numOfParams);

    CommandExpression *definevar(int pos, int numOfParams);

    CommandExpression *ifcommand(int pos, int numOfParams);

    CommandExpression *loopcommand(int pos, int numOfParams);

    CommandExpression *openservercommand(int pos, int numOfParams);

    CommandExpression *connectcommand(int pos, int numOfParams);

    CommandExpression *printcommand(int pos, int numOfParams);

    CommandExpression *sleepcommand(int pos, int numOfParams);

    CommandExpression *makeCommand(string c, int pos);


};


#endif //MAINPROJ_COMMANDSFACTORY_H
