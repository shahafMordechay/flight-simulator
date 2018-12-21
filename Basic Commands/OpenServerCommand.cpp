//
// Created by nisan on 12/8/18.
//

#include "OpenServerCommand.h"
#include "Expression.h"

int OpenServerCommand::doCommand(vector<string> &params) {
    // new thread that opens a server.
    thread t1(&OpenServerCommand::openServer, this, atoi(params[pos].c_str()), atoi(params[pos+1].c_str()));
    t1.detach();
    return 2;
}

OpenServerCommand::OpenServerCommand(map<string, double> &vars, int pos) {
    this->vars = &vars;
    this->pos = pos;
}

void OpenServerCommand::openServer(int port, int freq) {
    int sockfd, newsockfd, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr{}, cli_addr{};
    int  n;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    /* If connection is established then start communicating */
    while(true) {
        bzero(buffer, 256);
        n = static_cast<int>(read(newsockfd, buffer, 255));
        printf("%s",buffer);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
    }
}



