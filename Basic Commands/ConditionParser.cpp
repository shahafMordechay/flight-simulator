//
// Created by nisan on 12/14/18.
//

#include "ConditionParser.h"

ConditionParser::ConditionParser(vector<string> &params, int pos) {
    this->pos = pos;
    this->text = params;
    this->myCommands = list<Command *>();
    getCond();

}
// condition interpeter.
bool ConditionParser::checkCondition() {
    return false;
}

void ConditionParser::getCond() {
    // get the condition
    while (this->text[pos] != "endLine") {
        this->condition.emplace_back(this->text[pos]);
        pos++;
    }
    // skip line end indicator.
    pos++;
    // delete unwanted char from cond.
    if (this->condition[condition.size() - 1] == "{")
        // take it out.
        this->condition.pop_back();
}

int ConditionParser::doCommand(vector<string> &, int pos) {
    return 0;
}
