//
// Created by shahaf on 12/19/18.
//

#include <locale.h>
#include <stack>
#include <list>

#include "MathExpCalc.h"
#include "Number.h"
#include "Plus.h"
#include "Minus.h"
#include "Mult.h"
#include "Div.h"
#include "../GenFunc.h"

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
queue<string> MathExpCalc::shuntingYard(string &mathExp) {
    queue<string> postfix;
    stack<char> signStack;

    string num = "";
    // iterate over string expression and create postfix expression
    for (int i = 0; i < mathExp.length(); i++) {

        // read number or add '-' to number start
        if (isdigit(mathExp[i]) || mathExp[i] == '.' || (mathExp[i] == '-' && !isdigit(mathExp[i - 1]))) {
            num += mathExp[i];

        // push '(' to stack
        }  else if (mathExp[i] == '('){
            signStack.push(mathExp[i]);

        // pop operators from stack and push to queue
        } else if (GenFunc::isOperator(mathExp[i]) || mathExp[i] == ')') {

            // push number that comes before operator to queue
            if (!num.empty()) {
                postfix.push(num);
                num = "";
            }

            // this operator precedence
            int thisPrecedence = getPrecedence(mathExp[i]);

            /* pop operators from stack to queue while this precedence is lower than
               stack top operator precedence */
            while (!signStack.empty()
                    && getPrecedence(signStack.top()) > thisPrecedence) {

                string s(1, signStack.top());
                postfix.push(s);
                signStack.pop();
            }

            // if operator is ')' than pop '(' from stack
            if (mathExp[i] == ')') {
                signStack.pop();

            // push operator to stack
            } else {
                signStack.push(mathExp[i]);
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

// build expression from postfix math expression queue
Expression* MathExpCalc::expFromPostfix(queue<string> postfix) {
    stack<Expression*> expStack;

    // build expression from polish notation
    while (!postfix.empty()) {

        // front in queue is a number
        if (GenFunc::isNumber(postfix.front())) {
            Number* number = new Number(postfix.front());
            expStack.push(number);
            postfix.pop();

        // front in queue is an operator
        } else {
            Expression* num2 = expStack.top();
            expStack.pop();
            Expression* num1 = expStack.top();
            expStack.pop();

            switch (postfix.front()[0]) {
                case '+': {
                    Plus* plus = new Plus(num1, num2);
                    expStack.push(plus);
                    postfix.pop();
                    break;
                }
                case '-': {
                    Minus* minus = new Minus(num1, num2);
                    expStack.push(minus);
                    postfix.pop();
                    break;
                }
                case '*': {
                    Mult* mult = new Mult(num1, num2);
                    expStack.push(mult);
                    postfix.pop();
                    break;
                }
                case '/': {
                    Div* div = new Div(num1, num2);
                    expStack.push(div);
                    postfix.pop();
                    break;
                }
                default:
                    break;
            }
        }
    }// end of while

    Expression* result = expStack.top();
    return result;
}

// convert given math expression to postfix, build an expression and calculates
double MathExpCalc::evaluate(string &mathExp) {
    queue<string> postfix = shuntingYard(mathExp);
    Expression* resultExp = expFromPostfix(postfix);
    return resultExp->calculate();
}