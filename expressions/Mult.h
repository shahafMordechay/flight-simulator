#ifndef FLIGHTSIMULATOR_MULT_H
#define FLIGHTSIMULATOR_MULT_H


#include "BinaryExpression.h"

class Mult : public BinaryExpression {
public:
    double calculate() override;
};


#endif //FLIGHTSIMULATOR_MULT_H
