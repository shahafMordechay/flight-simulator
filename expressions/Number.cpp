#include "Number.h"

Number::Number(double num) {
    this->num = num;
}

Number::Number(string num) {
    this->num = stod(num);
}

double Number::calculate() {
    return this->num;
}



