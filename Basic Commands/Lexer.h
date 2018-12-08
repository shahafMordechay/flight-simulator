//
// Created by nisan on 12/8/18.
//

#ifndef MAINPROJ_LEXER_H
#define MAINPROJ_LEXER_H
#define SEPARATOR " "
#include <fstream>
#include "Command.h"
#include <map>
#include <string>
#include <list>
#include <vector>

using namespace std;

class Lexer {
public:
    fstream reader;
    map<string, Command*> commands;
    map<string, double> symbolTable;
    Lexer();
    list<string> lexer();
    void parser(list<string>);
    void addRelevantCommands();
    void initializeVar(vector<string>);


};


#endif //MAINPROJ_LEXER_H
