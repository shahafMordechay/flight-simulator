#ifndef FLIGHTSIMULATOR_DIV_H
#define FLIGHTSIMULATOR_DIV_H


#include "BinaryExpression.h"

class Div : public BinaryExpression {
public:
    Div(Expression* left, Expression* right) : BinaryExpression(left, right){};
    double calculate() override;
    virtual ~Div();
};


#endif //FLIGHTSIMULATOR_DIV_H
