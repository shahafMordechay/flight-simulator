//
// Created by nisan on 12/14/18.
//

#include <netdb.h>
#include "ConnectCommand.h"

int ConnectCommand::doCommand(vector<string> &params, int pos) {
    // check params validity.
    if ((params[pos] != "127.0.0.1") && (params[pos + 1] != "5402"))
        __throw_bad_exception();
    string host = params[pos];
    for (int i = 0; i < params[pos].length() ; i++) {
        host[i] = params[pos][i];
    }
    host[params[pos].length()] = '\0';
    string port = params[pos + 1];
    // open new thread and try connect to the simulator.
    thread t2(&ConnectCommand::connectToServer,this, host, port);
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
    // convert to char*
    char host [hostId.length() +1];
    for (int i = 0; i < hostId.length() ; i++) {
        host[i] = hostId[i];
    }
    host[hostId.length()] = '\0';
    server = gethostbyname(host);
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
    bcopy(server->h_name, (char *) &serv_addr.sin_addr.s_addr, static_cast<size_t>(server->h_length));
    // port num.
    serv_addr.sin_port = htons(static_cast<uint16_t>(atoi(port.c_str())));

    /* Now connect to the server */
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    /* Now ask for a message from the user, this message
       * will be read by server
    */

    bzero(buffer, 256);
    fgets(buffer, 255, stdin);

    /* Send message to the server */
    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
}



