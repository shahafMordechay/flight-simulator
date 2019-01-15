#ifndef FSSERVER_MYSERIALSERVER_H
#define FSSERVER_MYSERIALSERVER_H

#include "ServerSide.h"
#include "ClientHandler.h"

using namespace server_side;

class MySerialServer : public Server {
    void start(int port, ClientHandler *cHandler)override;
public:
    void open(int port, ClientHandler *cHandler)override;
    void stop()override;
};


#endif //FSSERVER_MYSERIALSERVER_H
