//
// Created by nisan on 12/8/18.
//

#ifndef MAINPROJ_COMMAND_H
#define MAINPROJ_COMMAND_H

#include <cstring>
#include <string>
#include <string.h>
#include <list>
#include <vector>
#include <map>
#include <unistd.h>
#include <thread>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
using namespace std;
class Command {
public:
    virtual int doCommand(vector<string>&)=0;
};


#endif //MAINPROJ_COMMAND_H
