//
// Created by nisan on 12/8/18.
//

#include "LoopCommand.h"

int LoopCommand::doCommand(vector<string> &params) {
    // while condition is met execute.
    while (checkCondition()) {
        for (auto &command: this->myCommands) {
            command->doCommand(params);
        }
    }
    return this->endOfLoopIndex;
}

LoopCommand::LoopCommand(vector<string> &params, map<string, string> &binds, map<string, double> &symbols, int pos)
        : ConditionParser(params,
                          symbols, binds,
                          pos) {
    this->pos = pos;
}
