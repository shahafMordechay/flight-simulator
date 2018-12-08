//
// Created by nisan on 12/8/18.
//

#ifndef MAINPROJ_LOOPCOMMAND_H
#define MAINPROJ_LOOPCOMMAND_H


#include "Command.h"

class LoopCommand: public Command{
    list<Command*> myCommands;
public:
    virtual void doCommand(string []);
    LoopCommand();

};


#endif //MAINPROJ_LOOPCOMMAND_H
