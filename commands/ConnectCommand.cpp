//
// Created by nisan on 12/14/18.
//

#include <netdb.h>
#include "ConnectCommand.h"

int ConnectCommand::doCommand(vector<string> &params) {
    // check params validity.
    if ((params[pos] != "127.0.0.1") && (params[pos + 1] != "5402"))
        __throw_bad_exception();
    string host = params[pos];
    string port = params[pos + 1];
    // open new thread and try connect to the simulator.
    thread t2(&ConnectCommand::connectToServer, this, host, port);
    // continue with my program.
    t2.detach();
    // return num of params read.
    return 2;
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

    /* Now connect to the server */
    while (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        // keep trying.
    }
    // keep updating the vars in the simulator consistently.
    while (true) {
        for (auto &add: *this->binds) {
            // create string as requasted
            string setCommand = "set " + add.second + " " + to_string(this->vars->at(add.first));
            // change val in the simulator.
            n = write(sockfd, setCommand.c_str(), setCommand.length());
            // unsuccesfull update.
            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }
        }
    }
}

ConnectCommand::ConnectCommand(map<string, string> &binds, map<string, double> &vars, int pos) {
    this->pos = pos;
    this->vars = &vars;
    this->binds = &binds;
}



