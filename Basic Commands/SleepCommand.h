//
// Created by nisan on 12/14/18.
//

#ifndef MAINPROJ_SLEEPCOMMAND_H
#define MAINPROJ_SLEEPCOMMAND_H


#include "Command.h"

class SleepCommand: public Command {
public:
    int pos;
    int doCommand(vector<string>&);
    SleepCommand(int pos);

};


#endif //MAINPROJ_SLEEPCOMMAND_H
