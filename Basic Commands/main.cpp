#include <iostream>
#include "Lexer.h"

int main() {
    auto * myreader = new Lexer();
    list<string> commands = myreader->lexer();
    return 0;
}