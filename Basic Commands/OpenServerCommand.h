//
// Created by nisan on 12/8/18.
//

#ifndef MAINPROJ_OPENSERVERCOMMAND_H
#define MAINPROJ_OPENSERVERCOMMAND_H


#include "Command.h"
#include <thread>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <map>

class OpenServerCommand : public Command {
public:
    map<string, double> vars;
    virtual void doCommand(vector<string>);
    OpenServerCommand(map<string, double > &var);
};


#endif //MAINPROJ_OPENSERVERCOMMAND_H
