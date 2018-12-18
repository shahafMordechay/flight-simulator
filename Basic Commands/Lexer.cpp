//
// Created by nisan on 12/8/18.
//

#include "Lexer.h"
#include "OpenServerCommand.h"
#include "LoopCommand.h"
#include "DefineVarCommand.h"
#include "IfCommand.h"
#include "SleepCommand.h"
#include "ConnectCommand.h"
#include "AssertionCommand.h"
#include "Expression.h"
#include "CommandExpression.h"

Lexer::Lexer() {
    this->commands = map<string, CommandExpression *>();
    this->symbolTable = map<string, double>();
    this->bindedMap = map<string, string>();
}

vector<string> Lexer::lexer() {
    vector<string> words;
    // can be any other name.
    this->reader.open("commands.txt");
    string line;
    while (getline(reader, line)) {
        while (!line.empty()) {
            //push string to back of the vector and check if not the last string in the line.
            if (line.find(SEPARATOR) != string::npos) {
                words.push_back(line.substr(0, line.find(SEPARATOR)));
                // next string in the line.
                line = line.substr(words.back().length() + 1);
            }
                // last string in the line.
            else {
                words.push_back(line);
                // indicate no more strings in input line.
                words.emplace_back("lineEnd");
                line = "";
            }
        }
    }
    // return vector of strings separated line by line with the string "lineEnd"
    this->addCommand(words);
    return words;
}

void Lexer::parser(vector<string> input) {
    // initialize current readed index.
    int move = 0;
    // still strings in the list.
    while (input.size() > move) {
        CommandExpression *current = this->commands.at(input[move]);
        // if valid command
        if (current != NULL) {
            move++;
            // set real start of command.
            current->setStart(move);
            // move index forward.
            move += (int) current->calculate();
        }
    }


}

void Lexer::addCommand(vector<string> &params) {
    this->commands.insert(
            {"openDataServer", new CommandExpression(new OpenServerCommand(this->symbolTable), params, 2)});
    this->commands.insert({"connect", new CommandExpression(new ConnectCommand(), params, 2)});
    this->commands.insert({"while", new CommandExpression(new LoopCommand(), params, -1)});
    this->commands.insert({"var", new CommandExpression(new DefineVarCommand(this->symbolTable), params, -1)});
    this->commands.insert({"if", new CommandExpression(new IfCommand(), params,-1)});
    this->commands.insert({"sleep", new CommandExpression(new SleepCommand(), params,-1)});
    this->commands.insert(
            {"=", new CommandExpression(new AssertionCommand(this->symbolTable, this->bindedMap), params,-1)});
}



