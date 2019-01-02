#ifndef FSSERVER_CLIENTHANDLER_H
#define FSSERVER_CLIENTHANDLER_H

#include <iostream>

using namespace std;

class ClientHandler {
public:
    virtual void handleClient(istream input, ostream output)=0;
};

#endif //FSSERVER_CLIENTHANDLER_H
