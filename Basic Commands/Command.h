//
// Created by nisan on 12/8/18.
//

#ifndef MAINPROJ_COMMAND_H
#define MAINPROJ_COMMAND_H

#include <string>
#include <list>
#include <vector>
using namespace std;
class Command;

class Command {
public:
    virtual void doCommand(vector<string>) = 0;
};


#endif //MAINPROJ_COMMAND_H
