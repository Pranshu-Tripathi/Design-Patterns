#include "expression.h"
#include "visitor.h"

Expression::Expression() {}

void Expression::accept(VisitorBase &visitor) {
  if (auto exp_vis = dynamic_cast<Visitor<Expression> *>(&visitor)) {
    exp_vis->visit(*this);
  }
}

DoubleExpression::DoubleExpression(double value)
    : Expression(), m_value(value) {}

double DoubleExpression::get_value() const { return m_value; }

void DoubleExpression::accept(VisitorBase &visitor) {
  if (auto dbl_vis = dynamic_cast<Visitor<DoubleExpression> *>(&visitor)) {
    dbl_vis->visit(*this);
  }
}

AdditionExpression::AdditionExpression(Expression *left, Expression *right)
    : Expression(), m_left(left), m_right(right) {}

Expression *AdditionExpression::left_exp() const { return m_left.get(); }

Expression *AdditionExpression::right_exp() const { return m_right.get(); }

void AdditionExpression::accept(VisitorBase &visitor) {
  if (auto add_exp = dynamic_cast<Visitor<AdditionExpression> *>(&visitor)) {
    add_exp->visit(*this);
  }
}

SubtractionExpression::SubtractionExpression(Expression *left,
                                             Expression *right)
    : Expression(), m_left(left), m_right(right) {}

Expression *SubtractionExpression::left_exp() const { return m_left.get(); }

Expression *SubtractionExpression::right_exp() const { return m_right.get(); }

void SubtractionExpression::accept(VisitorBase &visitor) {
  if (auto sub_exp = dynamic_cast<Visitor<SubtractionExpression> *>(&visitor)) {
    sub_exp->visit(*this);
  }
}
