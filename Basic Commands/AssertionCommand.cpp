//
// Created by nisan on 12/14/18.
//

#include "AssertionCommand.h"


int AssertionCommand::doCommand(vector<string> &params) {
    if (params[pos] == "bind") {
        string directory = params[pos + 1];
        // var name is 2 steps before this one.
        // bind them together.
        if(directory[0] == '\"'){
            // throw " ".
            directory = directory.substr(1,directory.length()-2);
        }
        this->binded->insert({params[pos - 2], directory});
        return 2;
    }
    // if want to assert existing var into this.
    else if(this->symbols->find(params[pos]) != this->symbols->end()){

    }

}

AssertionCommand::AssertionCommand(map<string, double> &symbol, map<string, string> &bind,int pos) {
    this->symbols = &symbol;
    this->binded = &bind;
    this->pos = pos;
}

