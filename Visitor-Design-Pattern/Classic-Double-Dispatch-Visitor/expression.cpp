#include "expression.h"
#include "expression_visitor.h"

Expression::Expression() {}

DoubleExpression::DoubleExpression(double value)
    : Expression(), m_value(value) {}

double DoubleExpression::get_value() const { return m_value; }

void DoubleExpression::accept(ExpressionVisitor *visitor) {
  visitor->visit(this);
}

AdditionExpression::AdditionExpression(Expression *left, Expression *right)
    : Expression(), m_left(left), m_right(right) {}

Expression *AdditionExpression::left_exp() const { return m_left.get(); }

Expression *AdditionExpression::right_exp() const { return m_right.get(); }

void AdditionExpression::accept(ExpressionVisitor *visitor) {
  visitor->visit(this);
}

SubtractionExpression::SubtractionExpression(Expression *left,
                                             Expression *right)
    : Expression(), m_left(left), m_right(right) {}

Expression *SubtractionExpression::left_exp() const { return m_left.get(); }

Expression *SubtractionExpression::right_exp() const { return m_right.get(); }

void SubtractionExpression::accept(ExpressionVisitor *visitor) {
  visitor->visit(this);
}
