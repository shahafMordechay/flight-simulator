//
// Created by nisan on 12/8/18.
//

#include "LoopCommand.h"

int LoopCommand::doCommand(vector<string> &params) {
    while (this->checkCondition()) {
        for (auto &command: this->myCommands) {
            command->doCommand(params);
        }
    }
}

LoopCommand::LoopCommand(vector<string> &params, int pos) : ConditionParser(params, pos + 1) {
    this->pos = pos;
}
