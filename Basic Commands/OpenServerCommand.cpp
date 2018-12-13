//
// Created by nisan on 12/8/18.
//

#include "OpenServerCommand.h"
#include "DataReaderFromServer.h"


void OpenServerCommand::doCommand(vector<string> params) {
    if (params.size() != 2) {
        __throw_bad_exception();
    }
    DataReaderFromServer serverReader = DataReaderFromServer(this->vars);
    // new thread that opens a server.
    thread t1(serverReader, params);
    t1.join();

}

OpenServerCommand::OpenServerCommand(map<string, double > &vars) {
    this->vars = vars;
}


