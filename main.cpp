#include <iostream>
#include "fsServer/StringReverser.h"
#include "fsServer/MyTestClientHandler.h"
#include "fsServer/ServerSide.h"
#include "fsServer/MySerialServer.h"
#include "fsServer/SearchSolver.h"
#include "algorithms/Entry.h"
#include "algorithms/AStar.h"
#include "fsServer/MyClientHanlder.h"
#include "fsServer/MyParallelServer.h"

using namespace server_side;

int main(int argc, char **argv) {
    ISearcher<Entry, string> *Astar = new AStar<string>();
    Solver<Matrix, string> *searchSolver = new SearchSolver<Entry, string>(Astar);
    ClientHandler *clientHandler = new MyClientHandler(searchSolver);
    Server *server = new MyParallelServer();
    server->open(atoi(argv[1]), clientHandler);
    return 0;
}