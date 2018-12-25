//
// Created by nisan on 12/8/18.
//

#ifndef MAINPROJ_OPENSERVERCOMMAND_H
#define MAINPROJ_OPENSERVERCOMMAND_H


#include "Command.h"

class OpenServerCommand : public Command {
public:
    int pos;
    bool *indicator;
    map<string, double> *vars;
    vector<pair<string, double>> pathToVal;
    map<string, string> *varsAndPaths;
    map<string, bool> *con;

    virtual int doCommand(vector<string> &);

    OpenServerCommand(map<string, double> &var, map<string, bool> &con, map<string, string> &bind, int pos, bool &indi);

    void openServer(int, int);

};


#endif //MAINPROJ_OPENSERVERCOMMAND_H
