//
// Created by nisan on 12/19/18.
//
#include "commandsFactory.h"

commandsFactory::commandsFactory(map<string, double> &symbols, map<string, string> &binds, vector<string> &text) {
    this->params = &text;
    this->bind = &binds;
    this->symbol = &symbols;
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
    return new CommandExpression(new AssertionCommand(*symbol, *bind, pos), *params, numOfParams);
}


CommandExpression *commandsFactory::definevar(int pos, int numOfParams) {
    return new CommandExpression(new DefineVarCommand(*this->symbol, pos), *params, numOfParams);
}

CommandExpression *commandsFactory::ifcommand(int pos, int numOfParams) {
    return new CommandExpression(new IfCommand(*params, pos), *params, numOfParams);
}

CommandExpression *commandsFactory::loopcommand(int pos, int numOfParams) {
    return new CommandExpression(new LoopCommand(*params, pos), *params, numOfParams);
}

CommandExpression *commandsFactory::openservercommand(int pos, int numOfParams) {
    return new CommandExpression(new OpenServerCommand(*this->symbol, pos), *params, numOfParams);
}

CommandExpression *commandsFactory::printcommand(int pos, int numOfParams) {
    return new CommandExpression(new PrintCommand(*this->symbol, pos), *params, numOfParams);
}

CommandExpression *commandsFactory::connectcommand(int pos, int numOfParams) {
    return new CommandExpression(new ConnectCommand(pos), *params, numOfParams);
}

CommandExpression *commandsFactory::sleepcommand(int pos, int numOfParams) {
    return new CommandExpression(new SleepCommand(pos), *params, numOfParams);
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
    else
        throw "Invalid Syntax";

}

