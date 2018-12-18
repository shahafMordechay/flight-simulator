#ifndef FLIGHTSIMULATOR_MINUS_H
#define FLIGHTSIMULATOR_MINUS_H


#include "BinaryExpression.h"

class Minus : public BinaryExpression {
public:
    double calculate() override;
};


#endif //FLIGHTSIMULATOR_MINUS_H
