//
// Created by nisan on 12/14/18.
//

#include "ConditionParser.h"

ConditionParser::ConditionParser(vector<string> &params, map<string, double> &symbols, int pos) {
    this->pos = pos;
    this->text = params;
    this->symbols = &symbols;
    this->myLex = Lexer();
    this->myCommands = list<Command *>();
    getCond();

}

// condition interpeter.
bool ConditionParser::checkCondition() {
    // condition index.
    int i = 0;
    // its a var.
    if (this->symbols->find(this->condition[i]) != this->symbols->end()) {
        // get value.
        double varValue = this->symbols->at(condition[i]);
        i++;
        // check if operand.
        if (checkOperand(this->condition[i])) {
            //keep operand.
            string Operand = this->condition[i];
            i++;
            string Exp;
            while (this->condition.size() > i) {
                //concat until the end.
                Exp += this->condition[i];
                i++;
            }
            // eval compared to expression.
            double compareTo = GenFunc::evaluate(Exp);
            // check if condition is met.
            return this->operands.at(Operand)(varValue, compareTo);
        }
    }
        // its not a var
    else {
        // expression.
        string Exp;
        while (checkOperand(this->condition[i]) || this->condition.size() > i) {
            // concat until operand or until the end.
            Exp += this->condition[i];
            i++;
        }
        // eval expression.
        double ExpVal = GenFunc::evaluate(Exp);
        // no operand.
        if (i == this->condition.size()) {
            // no operand check just true false.
            return this->operands.at("")(ExpVal);
        }
        // keep operand.
        string Operand = this->condition[i];
        i++;
        // check if next 1 its a var.
        if (this->symbols->find(this->condition[i]) != this->symbols->end()) {
            // get value.
            double varVal = this->symbols->at(this->condition[i]);
            // return wanted func
            return this->operands.at(Operand)(ExpVal, varVal);
        }
            // not a var.
        else {
            // make sec exp.
            string secExp;
            while (this->condition.size() > i) {
                // concat until the end.
                secExp += this->condition[i];
                i++;
            }
            // get value of second.
            double secExpVal = GenFunc::evaluate(secExp);
            // return wanted func result.
            return this->operands.at(Operand)(ExpVal, secExpVal);
        }
    }
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

bool ConditionParser::checkOperand(string c) {
    return ((c == "<") || (c == ">") || (c == "==") || (c == "!="));
}

bool ConditionParser::bigger(double first, double second) {
    return ((first - second) > 0);
}

bool ConditionParser::smaller(double first, double second) {
    return ((first - second) < 0);
}

bool ConditionParser::equal(double first, double second) {
    return ((first - second) == 0);
}

bool ConditionParser::notEqual(double first, double second) {
    return ((first - second) != 0);
}

bool ConditionParser::notZero(double only) {
    return (only != 0);
}
