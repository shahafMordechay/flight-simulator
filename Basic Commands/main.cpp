#include <iostream>
#include "Lexer.h"

int main() {
    auto * myreader = new Lexer();
    myreader->parser(myreader->lexer(),0);
    return 0;
}