
#ifndef FLIGHTSIMULATOR_MYPARALLELSERVER_H
#define FLIGHTSIMULATOR_MYPARALLELSERVER_H

#include <thread>
#include <vector>
#include "ServerSide.h"

using namespace server_side;

class MyParallelServer : public Server {
    vector<thread> threadList;

    void start(int port, ClientHandler *cHandler)override;
public:
    void open(int port, ClientHandler *cHandler)override;
    void stop()override;
};

#endif //FLIGHTSIMULATOR_MYPARALLELSERVER_H
