#ifndef FLIGHTSIMULATOR_PLUS_H
#define FLIGHTSIMULATOR_PLUS_H


#include "BinaryExpression.h"

class Plus : public BinaryExpression{
public:
    double calculate() override;
};


#endif //FLIGHTSIMULATOR_PLUS_H
