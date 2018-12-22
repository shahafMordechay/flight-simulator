//
// Created by nisan on 12/13/18.
//

#include "DataReaderFromServer.h"

void DataReaderFromServer::operator()(vector<string> params) {
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
    serv_addr.sin_port = htons(static_cast<uint16_t>(atoi(params[0].c_str())));

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd,atoi(params[1].c_str()));
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    /* If connection is established then start communicating */
    bzero(buffer,256);
    n = static_cast<int>(read(newsockfd, buffer, 255 ));

    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
}
// getting a ref to my map of vars in order to change its values if needed.
DataReaderFromServer::DataReaderFromServer(map<string, double > &vars){
    this->symbolTable = vars;
}
