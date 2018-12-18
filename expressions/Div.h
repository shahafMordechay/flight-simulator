#ifndef FLIGHTSIMULATOR_DIV_H
#define FLIGHTSIMULATOR_DIV_H


#include "BinaryExpression.h"

class Div : public BinaryExpression {
public:
    double calculate() override;
};


#endif //FLIGHTSIMULATOR_DIV_H
