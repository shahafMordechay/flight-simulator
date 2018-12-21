#ifndef FLIGHTSIMULATOR_MINUS_H
#define FLIGHTSIMULATOR_MINUS_H


#include "BinaryExpression.h"

class Minus : public BinaryExpression {
public:
    Minus(Expression* left, Expression* right) : BinaryExpression(left, right){};
    double calculate() override;
};


#endif //FLIGHTSIMULATOR_MINUS_H
