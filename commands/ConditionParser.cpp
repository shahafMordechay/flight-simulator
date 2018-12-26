//
// Created by nisan on 12/14/18.
//

#include "ConditionParser.h"
#include "Lexer.h"
#include "../GenFunc.h"

ConditionParser::ConditionParser(map<string, bool> &con, vector<string> &params, map<string, double> &symbols,
                                 map<string, string> &binds,
                                 int pos) {
    this->text = params;
    this->pos = getCond(pos);
    this->symbols = &symbols;
    this->binds = &binds;
    this->con = &con;
    this->myCommands =  list<Expression *>();
    makeMeCommands();

}

// condition interpeter.
bool ConditionParser::checkCondition() {
    // replace with real values.
    string translated = GenFunc::replaceByVal(this->condition, *this->symbols);
    // check if complex.
    translated = deleteUnimportant(translated);
    // check if exist.
    int startIndex = translated.find("<=");
    // if its really there.
    if (startIndex != translated.npos) {
        string firstExp = translated.substr(0, startIndex);
        string secondExp = translated.substr(startIndex + 2, translated.length() - 1);
        double first = MathExpCalc::evaluate(firstExp);
        double second = MathExpCalc::evaluate(secondExp);
        return smallerOrEqual(first, second);

    }
    startIndex = translated.find(">=");
    // if its really there.
    if (startIndex != translated.npos) {
        string firstExp = translated.substr(0, startIndex);
        string secondExp = translated.substr(startIndex + 2, translated.length() - 1);
        double first = MathExpCalc::evaluate(firstExp);
        double second = MathExpCalc::evaluate(secondExp);
        return biggerOrEqual(first, second);

    }
    startIndex = translated.find("==");
    // if its really there.
    if (startIndex != translated.npos) {
        string firstExp = translated.substr(0, startIndex);
        string secondExp = translated.substr(startIndex + 2, translated.length() - 1);
        double first = MathExpCalc::evaluate(firstExp);
        double second = MathExpCalc::evaluate(secondExp);
        return equal(first, second);

    }
    startIndex = translated.find("!=");
    // if its really there.
    if (startIndex != translated.npos) {
        string firstExp = translated.substr(0, startIndex);
        string secondExp = translated.substr(startIndex + 2, translated.length() - 1);
        double first = MathExpCalc::evaluate(firstExp);
        double second = MathExpCalc::evaluate(secondExp);
        return notEqual(first, second);

    }
    startIndex = translated.find(">");
    // if its really there.
    if (startIndex != translated.npos) {
        string firstExp = translated.substr(0, startIndex);
        string secondExp = translated.substr(startIndex + 1, translated.length() - 1);
        double first = MathExpCalc::evaluate(firstExp);
        double second = MathExpCalc::evaluate(secondExp);
        return bigger(first, second);

    }
    startIndex = translated.find("<");
    if (startIndex != translated.npos) {
        string firstExp = translated.substr(0, startIndex);
        string secondExp = translated.substr(startIndex + 1, translated.length() - 1);
        double first = MathExpCalc::evaluate(firstExp);
        double second = MathExpCalc::evaluate(secondExp);
        return smaller(first, second);

    } else {
        return notZero(MathExpCalc::evaluate(translated));
    }
}

int ConditionParser::getCond(int pos) {
    // get the condition
    while (this->text[pos] != "lineEnd") {
        // concat until the end.
        this->condition += (this->text[pos]);
        pos++;
    }
    // skip line end indicator.
    pos++;
    // delete unwanted char from cond.
    if (this->condition[condition.length() - 1] == '{')
        // take it out.
        this->condition.pop_back();
    return pos;
}

int ConditionParser::doCommand(vector<string> &, int pos) {
    return 0;
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

void ConditionParser::makeMeCommands() {
    bool indi = false;
    auto *loopCommands = new commandsFactory(*this->con, *this->symbols, *this->binds, this->text, indi);
    //still in the loop.
    while (this->text[pos] != "}") {
        // check if loop in loop
        if ((this->text[pos] == "while") || (this->text[pos] == "if")) {
            Expression *myOne = loopCommands->makeCommand(this->text[pos], pos + 1);
            this->myCommands.emplace_back(myOne);
            pos++;
            // skip all inside loop commands.
            while (this->text[pos] != "}")
                pos++;
            // skip end line indicator.
            pos++;
        } else {
            // make new command.
            try {
                Expression *myOne = loopCommands->makeCommand(this->text[pos], pos + 1);
                if (myOne != NULL)
                    this->myCommands.emplace_back(myOne);
            } catch (exception) {} //invalid command.
            pos++;
        }
    }
    this->endOfLoopIndex = pos + 2;
    delete (loopCommands);
}

bool ConditionParser::biggerOrEqual(double first, double second) {
    return (bigger(first, second) || equal(first, second));
}

bool ConditionParser::smallerOrEqual(double first, double second) {
    return (smaller(first, second) || equal(first, second));
}

string ConditionParser::deleteUnimportant(string condition) {
    if (condition[0] == '(') {
        condition = condition.substr(1, condition.length() - 2);
        return condition;
    }
    return condition;
}

ConditionParser::~ConditionParser() {
    for (auto &command: this->myCommands) {
        delete (command);
    }
}
