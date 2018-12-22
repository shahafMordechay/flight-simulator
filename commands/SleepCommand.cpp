//
// Created by nisan on 12/14/18.
//

#include "SleepCommand.h"

int SleepCommand::doCommand(vector<string> &params) {
    // sleep for wanted time
    std::this_thread::sleep_for(std::chrono::milliseconds(atoi(params[pos].c_str())));
    return 1;
}

SleepCommand::SleepCommand(int pos) {
    this->pos = pos;
}
