#include "BinaryExpression.h"
#include "Number.h"

BinaryExpression::BinaryExpression(Expression *left, Expression *right) {
    this->left = left;
    this->right = right;
}

BinaryExpression::~BinaryExpression() {
    free (this->left);
    free (this->right);
}
