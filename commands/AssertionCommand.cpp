//
// Created by nisan on 12/14/18.
//

#include "AssertionCommand.h"
#include "../GenFunc.h"
#include "Lexer.h"
#include "ReadFromServer.h"

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
            // bind to local var.
        else {
            // bind to local.
            this->binded->insert({{params[pos - 2], 0}, directory});
        }
        counter++;
        // pos -2 is the index of the var name.
        this->binded->insert({{params[pos - 2], 0}, directory});
    }
        // if want to assert an expression inside
    else {
        string Exp;
        // read the full expression.
        while (params[pos + counter] != "lineEnd") {
            // check if its a var and replace by value.
            Exp += GenFunc::replaceByVal(params[pos + counter], *this->symbols);
            counter++;
        }
        // give me the value of the string.
        double value = MathExpCalc::evaluate(Exp);
        // if not binded to path.
        if (this->binded->find(params[pos - 2]) == this->binded->end())
            this->symbols->at(params[pos - 2]) = value;
        //binded to path.
        else {
            ReadFromServer::changeSymbolT(*this->con, params, pos, *this->binded, *this->symbols, value);
        }
    }
    // how many read.
    return counter;
}

AssertionCommand::AssertionCommand(map<string, bool> &con, map<string, double> &symbol, map<string, string> &bind,
                                   int pos) {
    this->con = &con;
    this->symbols = &symbol;
    this->binded = &bind;
    this->pos = pos;
}




