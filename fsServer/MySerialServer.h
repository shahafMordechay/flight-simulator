//
// Created by shahaf on 1/2/19.
//

#ifndef FSSERVER_MYSERIALSERVER_H
#define FSSERVER_MYSERIALSERVER_H

#include "ServerSide.h"

using namespace server_side;

class MySerialServer : public Server {
public:
    MySerialServer();
    void open(int port)override;
    void stop()override;
};


#endif //FSSERVER_MYSERIALSERVER_H
