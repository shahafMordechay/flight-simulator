#include <iostream>
#include "StringReverser.h"
#include "MyTestClientHandler.h"

int main() {
    Solver<string, string> *solver = new StringReverser();
    ClientHandler *ch = new MyTestClientHandler<string, string>(solver);
    ch->handleClient(cin, cout);
    return 0;
}