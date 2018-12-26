//
// Created by nisan on 12/8/18.
//
#include "OpenServerCommand.h"
#include "../expressions/Expression.h"
#include "ReadFromServer.h"

int OpenServerCommand::doCommand(vector<string> &params) {
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
    if (((MathExpCalc::evaluate(first) != 5400)) ||
        ((MathExpCalc::evaluate(second) != 10)))
        __throw_bad_exception();
    //stop running main thread untill connection.
    *this->indicator = true;
    // new thread that opens a server.
    thread t1(&OpenServerCommand::openServer, this, MathExpCalc::evaluate(first),
              MathExpCalc::evaluate(second));
    t1.detach();
    return num;
}

OpenServerCommand::OpenServerCommand(map<string, double> &vars, map<string, bool> &con, map<string, string> &bind,
                                     int pos,
                                     bool &indi) {
    this->vars = &vars;
    this->con = &con;
    this->varsAndPaths = &bind;
    this->pos = pos;
    this->indicator = &indi;
    this->pathToVal = vector<pair<string, double>>();
    // enter all possible paths from xml file.
    this->pathToVal.emplace_back("/instrumentation/airspeed-indicator/indicated-speed-kt", 0);
    this->pathToVal.emplace_back("/instrumentation/altimeter/indicated-altitude-ft", 0);
    this->pathToVal.emplace_back("/instrumentation/altimeter/pressure-alt-ft", 0);
    this->pathToVal.emplace_back("/instrumentation/attitude-indicator/indicated-pitch-deg", 0);
    this->pathToVal.emplace_back("/instrumentation/attitude-indicator/indicated-roll-deg", 0);
    this->pathToVal.emplace_back("/instrumentation/attitude-indicator/internal-pitch-deg", 0);
    this->pathToVal.emplace_back("/instrumentation/attitude-indicator/internal-roll-deg", 0);
    this->pathToVal.emplace_back("/instrumentation/encoder/indicated-altitude-ft", 0);
    this->pathToVal.emplace_back("/instrumentation/encoder/pressure-alt-ft", 0);
    this->pathToVal.emplace_back("/instrumentation/gps/indicated-altitude-ft", 0);
    this->pathToVal.emplace_back("/instrumentation/gps/indicated-ground-speed-kt", 0);
    this->pathToVal.emplace_back("/instrumentation/gps/indicated-vertical-speed", 0);
    this->pathToVal.emplace_back("/instrumentation/heading-indicator/indicated-heading-deg", 0);
    this->pathToVal.emplace_back("/instrumentation/magnetic-compass/indicated-heading-deg", 0);
    this->pathToVal.emplace_back("/instrumentation/slip-skid-ball/indicated-slip-skid", 0);
    this->pathToVal.emplace_back("/instrumentation/turn-indicator/indicated-turn-rate", 0);
    this->pathToVal.emplace_back("/instrumentation/vertical-speed-indicator/indicated-speed-fpm", 0);
    this->pathToVal.emplace_back("/controls/flight/aileron", 0);
    this->pathToVal.emplace_back("/controls/flight/elevator", 0);
    this->pathToVal.emplace_back("/controls/flight/rudder", 0);
    this->pathToVal.emplace_back("/controls/flight/flaps", 0);
    this->pathToVal.emplace_back("/controls/engines/current-engine/throttle", 0);
    this->pathToVal.emplace_back("/engines/engine/rpm", 0);
}

void OpenServerCommand::openServer(int port, int freq) {
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
    n = read(newsockfd, buffer, 255);
    bzero(buffer, 256);
    /* If connection is established then start communicating */
    while (true) {
        int i = 0;
        int start;
        if (remainings != "") {
            start = remainings.length() - 1;
        } else {
            start = 0;
        }
        remainings = "";
        string normal;
        n = (read(newsockfd, buffer + start, 255 - start));
        while (buffer[i] != '\n') {
            normal += buffer[i];
            i++;
        }
        // skip /n
        i++;
        // concat /n
        normal += '\n';
        // there are more vals than in 1 cycle.
        if (buffer[i]) {
            for (i; i < 256; i++) {
                // save remaining values.
                remainings += buffer[i];
            }
            // clear
            bzero(buffer, 256);
            for (int j = 0; j < remainings.length(); j++) {
                // move remaining to the front
                buffer[j] = remainings[j];
            }
        } else {
            bzero(buffer, 256);

        }
        //update my table
        ReadFromServer::updateValMap(normal.c_str(), this->pathToVal);
        //check if need to update vars.
        ReadFromServer::updateValues(*this->varsAndPaths, *this->con, this->pathToVal, *this->vars);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        // main can run
        *this->indicator = false;
    }
}

OpenServerCommand::~OpenServerCommand() {
    delete (this->con);
    delete (this->vars);
    delete (this->varsAndPaths);

}




