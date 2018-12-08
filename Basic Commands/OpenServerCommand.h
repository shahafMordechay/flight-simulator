//
// Created by nisan on 12/8/18.
//

#ifndef MAINPROJ_OPENSERVERCOMMAND_H
#define MAINPROJ_OPENSERVERCOMMAND_H


#include "Command.h"

class OpenServerCommand : public Command {
public:
    virtual void doCommand(string []);

    OpenServerCommand();
};


#endif //MAINPROJ_OPENSERVERCOMMAND_H
