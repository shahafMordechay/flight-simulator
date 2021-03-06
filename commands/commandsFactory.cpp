//
// Created by nisan on 12/19/18.
//
#include "commandsFactory.h"

commandsFactory::commandsFactory(map<string, bool> &con, map<string, double> &symbols, map<string, string> &binds,
                                 vector<string> &text,
                                 bool &indi, bool &cone, bool &ove, bool &closeServer, bool &serverClosed) {
    this->indicator = &indi;
    this->params = &text;
    this->bind = &binds;
    this->symbol = &symbols;
    this->con = &con;
    this->over = &ove;
    this->connectedOno = &cone;
    this->over_2 = &closeServer;
    this->serverOno = &serverClosed;
    this->commands = map<string, int>();
    commands.insert({"while", -1});
    commands.insert({"if", -1});
    commands.insert({"sleep", 1});
    commands.insert({"openDataServer", 2});
    commands.insert({"connect", 2});
    commands.insert({"var", 1});
    commands.insert({"=", -1});
    commands.insert({"print", 1});
}

CommandExpression *commandsFactory::assertion(int pos, int numOfParams) {
    return new CommandExpression(new AssertionCommand(*con, *symbol, *bind, pos), *params, numOfParams, pos);
}


CommandExpression *commandsFactory::definevar(int pos, int numOfParams) {
    return new CommandExpression(new DefineVarCommand(*this->symbol, *this->con, pos), *params, numOfParams, pos);
}

CommandExpression *commandsFactory::ifcommand(int pos, int numOfParams) {
    return new CommandExpression(new IfCommand(*con, *params, *bind, *symbol, pos), *params, numOfParams, pos);
}

CommandExpression *commandsFactory::loopcommand(int pos, int numOfParams) {
    return new CommandExpression(new LoopCommand(*con, *params, *bind, *symbol, pos), *params, numOfParams, pos);
}

CommandExpression *commandsFactory::openservercommand(int pos, int numOfParams) {
    return new CommandExpression(
            new OpenServerCommand(*this->symbol, *this->con, *this->bind, pos, *this->indicator, *this->over_2,
                                  *this->serverOno),
            *params,
            numOfParams, pos);
}

CommandExpression *commandsFactory::printcommand(int pos, int numOfParams) {
    return new CommandExpression(new PrintCommand(*this->symbol, pos), *params, numOfParams, pos);
}

CommandExpression *commandsFactory::connectcommand(int pos, int numOfParams) {
    return new CommandExpression(
            new ConnectCommand(*this->bind, *this->symbol, *this->con, pos, *this->connectedOno, *this->over), *params,
            numOfParams,
            pos);
}

CommandExpression *commandsFactory::sleepcommand(int pos, int numOfParams) {
    return new CommandExpression(new SleepCommand(pos), *params, numOfParams, pos);
}

CommandExpression *commandsFactory::makeCommand(string c, int pos) {
    if (c == "while")
        return loopcommand(pos, this->commands.at(c));
    else if (c == "if")
        return ifcommand(pos, this->commands.at(c));
    else if (c == "sleep")
        return sleepcommand(pos, this->commands.at(c));
    else if (c == "print")
        return printcommand(pos, this->commands.at(c));
    else if (c == "=")
        return assertion(pos, this->commands.at(c));
    else if (c == "connect")
        return connectcommand(pos, this->commands.at(c));
    else if (c == "openDataServer")
        return openservercommand(pos, this->commands.at(c));
    else if (c == "var")
        return definevar(pos, this->commands.at(c));
        // existing var to change.
    else
        return NULL;


}

