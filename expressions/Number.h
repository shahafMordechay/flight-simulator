#ifndef FLIGHTSIMULATOR_NUMBER_H
#define FLIGHTSIMULATOR_NUMBER_H

#include "Expression.h"

class Number : public Expression {
    double num;
public:
    Number(double num);
    Number(string num);
    double calculate() override;
};


#endif //FLIGHTSIMULATOR_NUMBER_H
