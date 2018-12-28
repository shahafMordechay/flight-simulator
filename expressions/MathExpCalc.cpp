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

// replace '-+' or '+-' to '-' and '--' to '+'. erase '+' if needed.
void minusPlusCombHandling(string &mathExp) {

    auto current = mathExp.begin();
    auto next = ++mathExp.begin();
    for (; next < mathExp.end(); current++, next++) {
        if (*current == '-') {

            // current and next are '-'
            if (*next == '-') {

                // erase '+' if comes after an operator
                if (current > mathExp.begin() && GenFunc::isOperator(*(--current))) {
                    mathExp.erase(next);
                    current += 2;
                    next++;
                    // replace '--' to '+'
                } else {
                    *next = '+';
                }
                mathExp.erase(current);

                // current is '-' next is '+'
            } else if (*next == '+') {
                mathExp.erase(next);
            }

            // current is '+' next is '-'
        } else if (*current == '+' && *next == '-') {
            mathExp.erase(current);
        }
    }

    // erase '+' from string start
    if (mathExp[0] == '+') {
        mathExp.erase(mathExp.begin());
    }
}

// convert infix math expression to postfix
queue<string> MathExpCalc::shuntingYard(string &mathExp) {
    minusPlusCombHandling(mathExp);

    queue<string> postfix;
    stack<char> signStack;

    string num = "";
    // iterate over string expression and create postfix expression
    for (int i = 0; i < mathExp.length(); i++) {

        // read number or add '-' to number start
        if (isdigit(mathExp[i]) || mathExp[i] == '.'
            || (mathExp[i] == '-' && !isdigit(mathExp[i - 1]) && mathExp[i - 1] != ')')) {

            num += mathExp[i];

            // push '(' to stack
        } else if (mathExp[i] == '(') {
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
                   && getPrecedence(signStack.top()) >= thisPrecedence) {

                if (signStack.top() == '(' && mathExp[i] == ')') {
                    signStack.pop();
                    break;
                }

                string s(1, signStack.top());
                postfix.push(s);
                signStack.pop();
            }

            if (mathExp[i] != ')') {
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
Expression *MathExpCalc::expFromPostfix(queue<string> postfix) {
    stack<Expression *> expStack;
    // build expression from polish notation
    while (!postfix.empty()) {

        // front in queue is a number
        if (GenFunc::isNumber(postfix.front())) {
            Number* number = new Number(postfix.front());
            expStack.push(number);
            postfix.pop();

            // front in queue is an operator
        } else {
            Expression *num2 = expStack.top();
            expStack.pop();
            Expression *num1 = expStack.top();
            expStack.pop();

            switch (postfix.front()[0]) {
                case '+': {
                    Plus *plus = new Plus(num1, num2);
                    expStack.push(plus);
                    postfix.pop();
                    break;
                }
                case '-': {
                    Minus *minus = new Minus(num1, num2);
                    expStack.push(minus);
                    postfix.pop();
                    break;
                }
                case '*': {
                    Mult *mult = new Mult(num1, num2);
                    expStack.push(mult);
                    postfix.pop();
                    break;
                }
                case '/': {
                    Div *div = new Div(num1, num2);
                    expStack.push(div);
                    postfix.pop();
                    break;
                }
                default:
                    break;
            }
        }
    }// end of while

    Expression *result = expStack.top();
    while (!expStack.empty()) {
        expStack.pop();
    }

    return result;
}

// convert given math expression to postfix, build an expression and calculates
double MathExpCalc::evaluate(string &mathExp) {
    queue<string> postfix = shuntingYard(mathExp);
    Expression *resultExp = expFromPostfix(postfix);
    double res = resultExp->calculate();
    free(resultExp);
    return res;
}