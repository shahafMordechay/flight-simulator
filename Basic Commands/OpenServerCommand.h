//
// Created by nisan on 12/8/18.
//

#ifndef MAINPROJ_OPENSERVERCOMMAND_H
#define MAINPROJ_OPENSERVERCOMMAND_H


#include "Command.h"

class OpenServerCommand : public Command {
public:
    int pos;
    map<string, double> *vars;
    virtual int doCommand(vector<string>&);
    OpenServerCommand(map<string, double > &var, int pos);
    void openServer(int, int);
};


#endif //MAINPROJ_OPENSERVERCOMMAND_H
