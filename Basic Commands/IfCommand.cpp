//
// Created by nisan on 12/14/18.
//

#include "IfCommand.h"

IfCommand::IfCommand():ConditionParser() {
}

int IfCommand::doCommand(vector<string> &params, int pos) {
    // first command in my loop.
    int initialPos = pos;
    // execute all the commands in the if loop just once.
    for (auto &command: this->myCommands) {
        // update index.
        initialPos += command->doCommand(params,pos);
    }
    // return how many read.
    return (initialPos - pos);
}
