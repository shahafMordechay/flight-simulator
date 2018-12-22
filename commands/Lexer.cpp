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
        // skip tabs
        while (line[0] == '\t') {
            line = line.substr(1);
        }
        while (!line.empty()) {
            //push string to back of the vector and check if not the last string in the line.
            if (line.find(SEPARATOR) != string::npos) {
                string tmp;
                // make tmp string.
                tmp = (line.substr(0, line.find(SEPARATOR)));
                int len = tmp.length();
                // if the string includes '='
                if (tmp.find(ASSERTSEPAR) != string::npos) {
                    // '=' is in the middle.
                    if (tmp[0] != '=') {
                        // string before.
                        string name = tmp.substr(0, tmp.find(ASSERTSEPAR));
                        words.emplace_back(name);
                        // cut var name.
                        tmp = tmp.substr(name.length());
                        // take assert command.
                        words.emplace_back("=");
                        tmp = tmp.substr(1);
                        if (tmp != "") {
                            words.emplace_back(tmp);
                        }
                    }
                        // '=' is the first token.
                    else if (tmp[0] == '=') {
                        // enter '='.
                        words.emplace_back("=");
                        // delete '='.
                        tmp = tmp.substr(1);
                        if (len > 1)
                            words.emplace_back(tmp);

                    }
                    line = line.substr(len + 1);
                }
                    // no assertion inside.
                else {
                    // enter the string
                    words.emplace_back(line.substr(0, line.find(SEPARATOR)));
                    // next string in the line.
                    line = line.substr(words.back().length() + 1);
                }
            }
                // no spaces between var name to assertion command.
            else if (line.find(ASSERTSEPAR) != string::npos) {
                // take var name.
                string var = line.substr(0, line.find(ASSERTSEPAR));
                if (var != "") {
                    words.emplace_back(var);
                }
                // skip name and '='
                line = line.substr(var.length() + 1);
                // enter '='
                words.emplace_back("=");
                words.emplace_back(line);
                // delete all
                words.emplace_back("lineEnd");
                line = "";
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

void Lexer::parser(vector<string> input, int offset) {
    // create new factory.
    commandsFactory myFactory = commandsFactory(this->symbolTable, this->bindedMap, input);
    // still strings in the list.
    while (input.size() > offset) {
        //generate specific command.
        Expression *current = myFactory.makeCommand(input[offset], offset + 1);
        // if valid command.
        if (current != NULL) {
            offset++;
            // move index forward.
            offset += (int) current->calculate();
            //line end.
            if (input[offset] == "lineEnd")
                offset++;
        }
            // existing var
        else {
            // skip var name.
            offset++;
        }
    }
}




