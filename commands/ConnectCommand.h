//
// Created by nisan on 12/14/18.
//

#ifndef MAINPROJ_CONNECTCOMMAND_H
#define MAINPROJ_CONNECTCOMMAND_H


#include "Command.h"
#include "CommandExpression.h"

class ConnectCommand : public Command{
    int pos;
    bool *conne;
    bool *finished;
    map<string, double> *vars;
    map<string, string> *binds;
    map<string, bool > *changedOrNot;
public:
    virtual int doCommand(vector<string>&);
    void connectToServer(string, string);
    ConnectCommand(map<string, string> &binds,map<string, double> &vars,map<string,bool > &con,int pos, bool &connected,bool &fish);
};


#endif //MAINPROJ_CONNECTCOMMAND_H
