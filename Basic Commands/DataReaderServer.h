//
// Created by nisan on 12/8/18.
//

#ifndef MAINPROJ_DATAREADERSERVER_H
#define MAINPROJ_DATAREADERSERVER_H


#include "Command.h"

class DataReaderServer: public Command {
public:
    virtual void doCommand();
    DataReaderServer();

};


#endif //MAINPROJ_DATAREADERSERVER_H
