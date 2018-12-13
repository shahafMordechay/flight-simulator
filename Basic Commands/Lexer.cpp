//
// Created by nisan on 12/8/18.
//

#include "Lexer.h"
#include "OpenServerCommand.h"
#include "connect.h"
#include "LoopCommand.h"

Lexer::Lexer() {
    this->commands = map<string, Command *>();
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
            if (line.find(SEPARATOR) != string::npos) {
                input.push_back(line.substr(0, line.find(SEPARATOR)));
                // next string in the line.
                line = line.substr(input.back().length() + 1);
            }
                // last string in the line.
            else {
                input.push_back(line);
                // indicate no more strings in input line.
                input.emplace_back("lineEnd");
                line = "";
            }
        }
    }
    // return list of strings separated line by line with the string "lineEnd"
    return input;
}

void Lexer::parser(list<string> input) {
    Command *currentCommand = nullptr;
    // indicate if reads variable.
    bool readVar = false;
    // unknown size vector of strings.
    vector<string> parameters;
    int pos = 0;
    for (auto &string: input) {
        if (string != "lineEnd") {
            // the string is a legal command and exists in my map.
            if ((this->commands.find(string) != this->commands.end()) || currentCommand != nullptr) {
                if (currentCommand == nullptr) {
                    currentCommand = this->commands.at(string);
                }
                    //command params
                else {
                    parameters.push_back(string);
                }
            }
                // check if its var initialization.
            else if (string == "var") {
                readVar = true;
            }
                // initialize var.
            else if (readVar) {
                parameters.push_back(string);

            }

        }
            // run command with params.
        else if (currentCommand) {
            currentCommand->doCommand(parameters);
            //clean vector.
            parameters.clear();
            //null
            currentCommand = nullptr;
        }
            // initialize variable.
        else if (readVar) {
            //convert to string array.
            initializeVar(parameters);
            //ended var
            parameters.clear();
            readVar = false;
        }
    }

}

void Lexer::addRelevantCommands() {
    this->commands.insert({"openDataServer",new OpenServerCommand(this->symbolTable)});
    this->commands.insert({"while", new LoopCommand()});

}

void Lexer::initializeVar(vector<string> params) {

}

