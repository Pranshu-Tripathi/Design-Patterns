#include "expression.h"

Expression::Expression() {}

DoubleExpression::DoubleExpression(double value)
    : Expression(), m_value(value) {}

double DoubleExpression::get_value() const { return m_value; }

AdditionExpression::AdditionExpression(Expression *left, Expression *right)
    : Expression(), m_left(left), m_right(right) {}

Expression *AdditionExpression::left_exp() const { return m_left.get(); }

Expression *AdditionExpression::right_exp() const { return m_right.get(); }
