#include <iostream>
#include "Lexer.h"

int main() {
    auto * myreader = new Lexer();
    myreader->parser(myreader->lexer());
    return 0;
}