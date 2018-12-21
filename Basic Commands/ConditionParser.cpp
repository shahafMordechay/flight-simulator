//
// Created by nisan on 12/14/18.
//

#include "ConditionParser.h"
#include "Lexer.h"

ConditionParser::ConditionParser(vector<string> &params, map<string, double> &symbols, map<string, string> &binds,
                                 int pos) {
    this->text = params;
    this->pos = getCond(pos);
    this->symbols = &symbols;
    this->binds = &binds;
    this->myLex = new Lexer();
    this->myCommands = list<Command *>();
    makeMeCommands();
    mapFunc[">"] = &ConditionParser::bigger;
    mapFunc["<"] = &ConditionParser::smaller;
    mapFunc["=="] = &ConditionParser::equal;
    mapFunc["!="] = &ConditionParser::notEqual;
    mapFunc[""] = &ConditionParser::notZero;
    mapFunc[">="] = &ConditionParser::biggerOrEqual;
    mapFunc["<="] = &ConditionParser::smallerOrEqual;

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
            return (this->*mapFunc.at(Operand))(varValue, compareTo);
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
            return (this->*mapFunc.at(""))(ExpVal, 0);
        }
        // keep operand.
        string Operand = this->condition[i];
        i++;
        // check if next 1 its a var.
        if (this->symbols->find(this->condition[i]) != this->symbols->end()) {
            // get value.
            double varVal = this->symbols->at(this->condition[i]);
            // return wanted func
            return (this->*mapFunc.at(Operand))(ExpVal, varVal);
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
            return (this->*mapFunc.at(Operand))(ExpVal, secExpVal);
        }
    }
}

int ConditionParser::getCond(int pos) {
    // get the condition
    while (this->text[pos] != "lineEnd") {
        this->condition.emplace_back(this->text[pos]);
        pos++;
    }
    // skip line end indicator.
    pos++;
    // delete unwanted char from cond.
    if (this->condition[condition.size() - 1] == "{")
        // take it out.
        this->condition.pop_back();
    return pos;
}

int ConditionParser::doCommand(vector<string> &, int pos) {
    return 0;
}

bool ConditionParser::checkOperand(string c) {
    return ((c == "<") || (c == ">") || (c == "==") || (c == "!=") || (c == ">=") || (c == "<="));
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

bool ConditionParser::notZero(double only, double junk) {
    return (only != 0);
}

void ConditionParser::makeMeCommands() {
    commandsFactory *loopCommands = new commandsFactory(*this->symbols, *this->binds, this->text);
    //still in the loop.
    while (this->text[pos] != "}") {
        while (this->text[pos] != "lineEnd") {
            CommandExpression *loopCommand = loopCommands->makeCommand(text[pos], pos + 1);
        }
    }
    pos++;
    delete (loopCommands);
}

bool ConditionParser::biggerOrEqual(double first, double second) {
    return (bigger(first, second) || equal(first, second));
}

bool ConditionParser::smallerOrEqual(double first, double second) {
    return (smaller(first, second) || equal(first, second));
}
