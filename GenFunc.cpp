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