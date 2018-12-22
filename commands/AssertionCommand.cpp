//
// Created by nisan on 12/14/18.
//

#include "AssertionCommand.h"

int AssertionCommand::doCommand(vector<string> &params) {
    // count num of params
    int counter = 0;
    if (params[pos] == "bind") {
        counter++;
        string directory = params[pos + counter];
        // var name is 2 steps before this one.
        // bind them together.
        if (directory[0] == '\"') {
            // throw " ".
            directory = directory.substr(1, directory.length() - 2);
        }
        counter++;
        // pos -2 is the index of the var name.
        this->binded->insert({params[pos - 2], directory});
    }
        // if want to assert an expression inside
    else {

        string Exp;
        // read the full expression.
        while (params[pos + counter] != "lineEnd") {
            // check if existing var.
            if (this->symbols->find(params[pos + counter]) != this->symbols->end()) {
                // concat the value instead of the var name.
                Exp += to_string(this->symbols->at(params[pos + counter]));
                counter++;
            } else {
                Exp += params[pos + counter];
                counter++;
            }
        }
        // give me the value of the string.
        double value = MathExpCalc::evaluate(Exp);
        // update the var in the table.
        this->symbols->at(params[pos - 2]) = value;

    }
    // how many read.
    return counter;
}

AssertionCommand::AssertionCommand(map<string, double> &symbol, map<string, string> &bind, int pos) {
    this->symbols = &symbol;
    this->binded = &bind;
    this->pos = pos;
}

