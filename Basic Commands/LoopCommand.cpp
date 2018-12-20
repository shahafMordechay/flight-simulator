//
// Created by nisan on 12/8/18.
//

#include "LoopCommand.h"

int LoopCommand::doCommand(vector<string> &params) {
    // initial pos set.
    int initialPos = pos;
    // while condition is met execute.
    while (checkCondition()) {
        for (auto &command: this->myCommands) {
            //update index.
            initialPos += command->doCommand(params);
        }
    }
    // return the difference.
    return (initialPos - pos);
}

LoopCommand::LoopCommand(vector<string> &params, map<string, double> &symbols, int pos) : ConditionParser(params,
                                                                                                          symbols,
                                                                                                          pos + 1) {
    this->pos = pos;
}
