//
// Created by shahaf on 12/22/18.
//

#include "GenFunc.h"

// true if sign is an operator, false otherwise
bool GenFunc::isOperator(char sign) {
    return sign == '+' || sign == '-' || sign == '*' || sign == '/';
}

// true if given string is a number, false otherwise
bool GenFunc::isNumber(string &str) {
    bool hasOneDigit = false;
    for (int i = 0; i < str.length(); ++i) {
        if (!isdigit(str[i]) && str[i] != '.' && (str.length() == 1 || i != 0 || str[0] != '-')) {
            return false;
        }

        if (hasOneDigit && str[i] == '.') {
            return false;
        }

        if (str[i] == '.') {
            hasOneDigit = true;
        }
    }

    return true;
}

string GenFunc::replaceByVal(string vari, map<string, double> &symbols) {
    // check for existing var.
    for (auto &var : symbols) {
        // check if exist.
        int startIndex = vari.find(var.first);
        // if its really there.
        if (startIndex != vari.npos) {
            vari.erase(startIndex, var.first.length());
            vari.insert(startIndex, to_string(var.second));
        }
    }
    // return the string.
    return vari;
}
