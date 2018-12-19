//
// Created by nisan on 12/14/18.
//

#ifndef MAINPROJ_CONNECTCOMMAND_H
#define MAINPROJ_CONNECTCOMMAND_H


#include "Command.h"
#include "CommandExpression.h"

class ConnectCommand : public Command{
public:
    int pos;
    virtual int doCommand(vector<string>&);
    void connectToServer(string, string);
    ConnectCommand(int pos);
};


#endif //MAINPROJ_CONNECTCOMMAND_H
