//
// Created by nisan on 12/8/18.
//

#include "Lexer.h"
#include "OpenServerCommand.h"
#include "connect.h"

Lexer::Lexer() {
    this->commands = map<string, Command*>();
    this->symbolTable = map<string, double>();
    addRelevantCommands();

}

list<string> Lexer::lexer() {
    list<string> input = list<string>();
    // can be any other name.
    this->reader.open("commands.txt");
    string line;
    while (getline(reader, line)) {
        while (!line.empty()) {
            //push string to back of the list and check if not the last string in the line.
            if(line.find(SEPARATOR)!= string::npos) {
                input.push_back(line.substr(0, line.find(SEPARATOR)));
                // next string in the line.
                line = line.substr(input.back().length() + 1);
            }
            // last string in the line.
            else{
                input.push_back(line);
                line = "";
            }
        }
    }
    return input;
}

void Lexer::parser() {

}

void Lexer::addRelevantCommands() {
    this->commands.insert({"openDataServer", new OpenServerCommand()});
    this->commands.insert({"connect", new connect()});


}
