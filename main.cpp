#include <iostream>
#include <string.h>
#include <queue>
#include "expressions/MathExpCalc.h"
#include "commands/Lexer.h"
using namespace std;

int main(int argc, char *argv[]) {
    auto *myreader = new Lexer(argc, argv);
    myreader->parser(myreader->lexer(), 0);
    delete(myreader);
    return 0;
}