#ifndef FSSERVER_SERVERSIDE_H
#define FSSERVER_SERVERSIDE_H

namespace server_side {
    class Server {
    public:
        virtual void open(int port)=0;
        virtual void stop()=0;
    };
}

#endif //FSSERVER_SERVERSIDE_H
