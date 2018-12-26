#include "Mult.h"

double Mult::calculate() {
    return this->left->calculate() * this->right->calculate();
}

Mult::~Mult() {

}
