#ifndef FLIGHTSIMULATOR_EXPRESSION_H
#define FLIGHTSIMULATOR_EXPRESSION_H

#include <string>

using namespace std;
class Expression {
public:
    virtual double calculate() = 0;
    virtual ~Expression(){};
};


#endif //FLIGHTSIMULATOR_EXPRESSION_H
