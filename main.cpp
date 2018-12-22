#include <iostream>
#include <string.h>
#include <queue>
#include "expressions/MathExpCalc.h"
#include "commands/Lexer.h"

using namespace std;

int main() {
    auto * myreader = new Lexer();
    myreader->parser(myreader->lexer(),0);
    return 0;
}