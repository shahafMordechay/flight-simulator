//
// Created by nisan on 12/13/18.
//

#ifndef MAINPROJ_DATAREADERFROMSERVER_H
#define MAINPROJ_DATAREADERFROMSERVER_H
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <vector>
#include <map>
using namespace std;
class DataReaderFromServer {
    //reference to my symbol table.
    map<std::string, double> symbolTable;

public:
    void operator()(vector<string>);
    DataReaderFromServer(map<string, double > &vars);


};


#endif //MAINPROJ_DATAREADERFROMSERVER_H
