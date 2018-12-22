//
// Created by nisan on 12/14/18.
//

#include "IfCommand.h"

IfCommand::IfCommand(vector<string> &params, map<string, string> &binds, map<string, double> &symbols, int pos)
        : ConditionParser(params, symbols, binds,
                          pos) {
    this->pos = pos;
}

int IfCommand::doCommand(vector<string> &params) {
    // execute all the commands in the if loop just once.
    if (checkCondition()) {
        for (auto &command: this->myCommands) {
            command->doCommand(params);
        }
    }
    // return how many read.
    return this->endOfLoopIndex;
}
