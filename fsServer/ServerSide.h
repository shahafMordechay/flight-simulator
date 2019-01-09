#ifndef FSSERVER_SERVERSIDE_H
#define FSSERVER_SERVERSIDE_H

#include "ClientHandler.h"

namespace server_side {
    class Server {
    public:
        virtual void open(int port, ClientHandler *cHandler)=0;
        virtual void stop()=0;
    };
}

#endif //FSSERVER_SERVERSIDE_H
