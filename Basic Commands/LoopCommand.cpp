//
// Created by nisan on 12/8/18.
//

#include "LoopCommand.h"

int LoopCommand::doCommand(vector<string> &params, int pos) {
    while(this->checkCondition(params)){
        for(auto &command: this->myCommands){

        }
    }
}

LoopCommand::LoopCommand():ConditionParser() {
}
