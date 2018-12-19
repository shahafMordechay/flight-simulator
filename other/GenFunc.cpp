//
// Created by shahaf on 12/19/18.
//

#include <locale.h>
#include <queue>
#include <stack>

#include "GenFunc.h"

// true if sign is an operator, false otherwise
bool isOperator(char sign) {
    return sign == '+' || sign == '-' || sign == '*' || sign == '/';
}

// return the precedence of given sign
int getPrecedence(char sign) {
    if (sign == '*' || sign == '/') {
        return 2;
    } else if (sign == '+' || sign == '-') {
        return 1;
    } else {
        return 0;
    }
}

// convert infix math expression to postfix
queue<string> GenFunc::shuntingYard(string &mathExp) {
    queue<string> postfix;
    stack<char> signStack;

    string num = "";
    // iterate over string expression and create postfix expression
    for (char token : mathExp) {

        // read number
        if (isdigit(token)) {
            num += token;

        // push '(' to stack
        }  else if (token == '('){
            signStack.push(token);

        // pop operators from stack and push to queue
        } else if (isOperator(token) || token == ')') {

            // push number that comes before operator to queue
            if (!num.empty()) {
                postfix.push(num);
                num = "";
            }

            // this operator precedence
            int thisPrecedence = getPrecedence(token);

            /* pop operators from stack to queue while this precedence is lower than
               stack top operator precedence */
            while (!signStack.empty()
                    && getPrecedence(signStack.top()) > thisPrecedence) {

                string s(1, signStack.top());
                postfix.push(s);
                signStack.pop();
            }

            // if operator is ')' than pop '(' from stack
            if (token == ')') {
                signStack.pop();

            // push operator to stack
            } else {
                signStack.push(token);
            }
        }
    } // end of for loop

    // push last number to queue
    postfix.push(num);

    // push all remaining operators from stack to queue
    while (!signStack.empty()) {
        string s(1, signStack.top());
        postfix.push(s);
        signStack.pop();
    }

    return postfix;
}

Expression* GenFunc::expFromPostfix(string &mathExp) {
    queue<string> postfix = shuntingYard(mathExp);
    stack<string> stc;


}