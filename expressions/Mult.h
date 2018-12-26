#ifndef FLIGHTSIMULATOR_MULT_H
#define FLIGHTSIMULATOR_MULT_H


#include "BinaryExpression.h"

class Mult : public BinaryExpression {
public:
    Mult(Expression* left, Expression* right) : BinaryExpression(left, right){};
    double calculate() override;

    virtual ~Mult();
};


#endif //FLIGHTSIMULATOR_MULT_H
