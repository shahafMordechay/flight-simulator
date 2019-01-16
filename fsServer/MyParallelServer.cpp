#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>
#include <thread>
#include <list>

#include "MyParallelServer.h"
#include "ClientHandler.h"

#define WAIT_FOR_CLIENT 5
#define WAIT_IN_MILISEC 0

void MyParallelServer::open(int port, ClientHandler *cHandler) {
    thread th(&MyParallelServer::start, this, port, cHandler);
    th.join();
}

void startHandleClient(int socket, ClientHandler *cHandler) {
    cHandler->handleClient(socket);
}

void MyParallelServer::start(int port, ClientHandler *cHandler) {
    int s = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(port);
    serv.sin_family = AF_INET;
    if (bind(s, (sockaddr *)&serv, sizeof(serv)) < 0)	{
        cerr << "failure on bind" << endl;
    }

    int new_sock;
    listen(s, 5);
    struct sockaddr_in client;
    socklen_t clilen = sizeof(client);

    timeval timeout;
    timeout.tv_sec = WAIT_FOR_CLIENT;
    timeout.tv_usec = WAIT_IN_MILISEC;

    while ((new_sock = accept(s, (struct sockaddr*)&client, &clilen)) >= 0) {
        thread th(startHandleClient, new_sock, cHandler);
        this->threadList.push_back(move(th));
        setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
    }

    for (int i = 0; i < this->threadList.size(); ++i) {
        this->threadList.at(i).join();
    }

    if (new_sock < 0)	{
        if (errno == EWOULDBLOCK)	{
            cout << "timeout!" << endl;
        }	else	{
            perror("failure on opening socket");
        }
    }

    close(new_sock);
    close(s);
}

void MyParallelServer::stop() {}