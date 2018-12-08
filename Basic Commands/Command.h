//
// Created by nisan on 12/8/18.
//

#ifndef MAINPROJ_COMMAND_H
#define MAINPROJ_COMMAND_H

#include <string>
#include <list>
using namespace std;
class Command;

class Command {
public:
    virtual void doCommand(string []) = 0;
};


#endif //MAINPROJ_COMMAND_H
