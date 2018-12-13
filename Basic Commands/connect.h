//
// Created by nisan on 12/8/18.
//

#ifndef MAINPROJ_CONNECT_H
#define MAINPROJ_CONNECT_H


#include "Command.h"

class connect : public Command {
    string add;
public:
    virtual void doCommand(vector<string>);
    connect();
};


#endif //MAINPROJ_CONNECT_H
