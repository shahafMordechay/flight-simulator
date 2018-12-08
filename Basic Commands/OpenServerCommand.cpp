//
// Created by nisan on 12/8/18.
//

#include "OpenServerCommand.h"


void OpenServerCommand::doCommand(vector<string> params) {
    if (params.size() != 2) {
        __throw_bad_exception();
    }
    string port = params[0];
    string freq = params[1];
    // new thread.
    thread(&OpenServerCommand::openServer, port, freq);
}

OpenServerCommand::OpenServerCommand() {

}

void OpenServerCommand::openServer(string port, string freq) {

}

