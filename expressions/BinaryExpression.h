#ifndef FLIGHTSIMULATOR_BINARYEXPRESSION_H
#define FLIGHTSIMULATOR_BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression {
protected:
    Expression *left;
    Expression *right;

public:
    BinaryExpression(Expression *left, Expression *right);

    virtual ~BinaryExpression();
};


#endif //FLIGHTSIMULATOR_BINARYEXPRESSION_H
