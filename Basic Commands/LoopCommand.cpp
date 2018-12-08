//
// Created by nisan on 12/8/18.
//

#include "LoopCommand.h"

void LoopCommand::doCommand(string params[]) {
    for (auto &command:this->myCommands) {
        command->doCommand(params);
    }
}

LoopCommand::LoopCommand() {
    this->myCommands = list<Command *>();
}
