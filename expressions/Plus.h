#ifndef FLIGHTSIMULATOR_PLUS_H
#define FLIGHTSIMULATOR_PLUS_H


#include "BinaryExpression.h"

class Plus : public BinaryExpression{
public:
    Plus(Expression* left, Expression* right) : BinaryExpression(left, right){};
    double calculate() override;
};


#endif //FLIGHTSIMULATOR_PLUS_H
