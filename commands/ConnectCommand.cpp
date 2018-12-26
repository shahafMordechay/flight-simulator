//
// Created by nisan on 12/14/18.
//

#include <netdb.h>
#include <mutex>
#include "ConnectCommand.h"
#include "../GenFunc.h"
#include "ReadFromServer.h"

int ConnectCommand::doCommand(vector<string> &params) {
    // check params validity.
    int num = 0;
    string line;
    string first;
    string second;
    // check if complicated.
    while (params[pos + num] != "lineEnd") {
        num++;
        line += params[pos + num];
    }
    //coma.
    if (line.find(',') != std::string::npos) {
        //first par.
        first = line.substr(0, line.find(','));
        //sec par.
        second = line.substr(line.find(',') + 1);
    } else {
        // normal.
        num = 2;
        first = params[pos];
        second = params[pos + 1];
    }
    if (((first != "127.0.0.1")) ||
        ((MathExpCalc::evaluate(second) != 5402)))
        __throw_bad_exception();
    // open new thread and try connect to the simulator.
    thread t2(&ConnectCommand::connectToServer, this, first, second);
    // continue with my program.
    t2.detach();
    // return num of params read.
    return num;
}

void ConnectCommand::connectToServer(string hostId, string port) {
    int sockfd, n;
    struct sockaddr_in serv_addr{};
    struct hostent *server;
    char buffer[256];
    server = gethostbyname(hostId.c_str());
    /* Create a socket point */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    // port num.
    serv_addr.sin_port = htons((atoi(port.c_str())));

    // keep trying to connect.
    while (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    }
    // keep updating the vars in the simulator consistently.
    while (this->conne) {
        // if some var value is changed write it.
        for (auto &var : *this->changedOrNot) {
            // if changed
            if (var.second) {
                // make msg.
                string msg = ReadFromServer::setMgs(var.first, *this->changedOrNot, *this->binds, *this->vars);
                n = write(sockfd, msg.c_str(), msg.length());
                // unsuccesfull update.
                if (n < 0) {
                    perror("ERROR writing to socket");
                    exit(1);
                }
            }
        }
    }
    free(server);
}

ConnectCommand::ConnectCommand(map<string, string> &binds, map<string, double> &vars, map<string, bool> &con, int pos,
                               bool &conne) {
    this->pos = pos;
    this->vars = &vars;
    this->conne = &conne;
    this->binds = &binds;
    this->changedOrNot = &con;
}




