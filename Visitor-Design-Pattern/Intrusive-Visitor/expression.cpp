#include "expression.h"

Expression::Expression() {}

DoubleExpression::DoubleExpression(double value)
    : Expression(), m_value(value) {}

void DoubleExpression::print(std::ostringstream &print_exp) {
  print_exp << m_value;
}

AdditionExpression::AdditionExpression(Expression *left, Expression *right)
    : Expression(), m_left(left), m_right(right) {}

void AdditionExpression::print(std::ostringstream &print_exp) {
  print_exp << "( ";
  m_left->print(print_exp);
  print_exp << " + ";
  m_right->print(print_exp);
  print_exp << " ) ";
}
