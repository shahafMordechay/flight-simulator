//
// Created by nisan on 12/8/18.
//

#ifndef MAINPROJ_LEXER_H
#define MAINPROJ_LEXER_H
#define SEPARATOR " "
#define ASSERTSEPAR "="
#define WHILE "while"
#define IF "if"
#include <fstream>
#include "Command.h"
#include "../expressions/Expression.h"
#include "CommandExpression.h"
#include <map>
#include <string>
#include <list>
#include <vector>
#include "commandsFactory.h"

using namespace std;

class Lexer {
    fstream reader;
    map<string, Expression*> commands;
    map<string, double> symbolTable;
    map<string, string> bindedMap;

public:
    Lexer();
    vector<string> lexer();
    void parser(vector<string>,int);



};


#endif //MAINPROJ_LEXER_H
