//
// Created by nisan on 12/8/18.
//

#include "Lexer.h"

Lexer::Lexer() {
    this->commands = map<string, Expression *>();
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
    return words;
}

void Lexer::parser(vector<string> input) {
    // create new factory.
     commandsFactory myFactory =  commandsFactory(this->symbolTable, this->bindedMap, input);
    // initialize current readed index.
    int move = 0;
    // still strings in the list.
    while (input.size() > move) {
        //generate specific command.
        Expression *current = myFactory.makeCommand(input[move], move + 1);
        // if valid command.
        if (current != NULL) {
            move++;
            // move index forward.
            move += (int) current->calculate();
            //line end.
            move++;
        }
    }
}




