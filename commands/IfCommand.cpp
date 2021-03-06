//
// Created by nisan on 12/14/18.
//

#include "IfCommand.h"

IfCommand::IfCommand(map<string,bool>& con,vector<string> &params, map<string, string> &binds, map<string, double> &symbols,
                     int pos)
        : ConditionParser(con,params, symbols, binds,
                          pos) {
    this->pos = pos;
}

int IfCommand::doCommand(vector<string> &params) {
    // execute all the commands in the if loop just once.
    if (checkCondition()) {
        for (auto &command: this->myCommands) {
            command->calculate();
        }
    }
    // return how many read.
    return this->endOfLoopIndex;
}

