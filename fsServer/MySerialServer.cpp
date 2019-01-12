#include <netinet/in.h>
#include <strings.h>
#include <unistd.h>
#include <thread>

#include "MySerialServer.h"
#include "ClientHandler.h"

void MySerialServer::open(int port, ClientHandler *cHandler) {
    int sockfd, newsockfd, clilen;
    char buffer[256];
    string remainings = "";
    struct sockaddr_in serv_addr{}, cli_addr{};
    int n;

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
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }
    bzero(buffer, 256);
    // throw first away.
    //n = read(newsockfd, buffer, 255);
    bzero(buffer, 256);
    /* If connection is established then start communicating */
    // keep communicating until out socket get close.
    //close my socket.

    int i=0;
    while (i < 2) {
        thread th(&ClientHandler::handleClient, cHandler, cin, cout);
        th.join();
        i++;
    }

    close(sockfd);
}

void MySerialServer::stop() {}