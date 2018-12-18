#ifndef FLIGHTSIMULATOR_EXPRESSION_H
#define FLIGHTSIMULATOR_EXPRESSION_H

using namespace std;

class Expression {
public:
    virtual double calculate() throw() = 0;
};


#endif //FLIGHTSIMULATOR_EXPRESSION_H
