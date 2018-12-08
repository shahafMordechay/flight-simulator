//
// Created by nisan on 12/8/18.
//

#ifndef MAINPROJ_OPENSERVERCOMMAND_H
#define MAINPROJ_OPENSERVERCOMMAND_H


#include "Command.h"
#include <thread>

class OpenServerCommand : public Command {
public:
    virtual void doCommand(vector<string>);
    void openServer(string port, string freq);
    OpenServerCommand();
};


#endif //MAINPROJ_OPENSERVERCOMMAND_H
