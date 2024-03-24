#pragma once
#include <memory>
#include <sstream>
class Expression {
public:
  Expression();
  virtual ~Expression() = default;
};

class DoubleExpression : public Expression {
  double m_value;

public:
  DoubleExpression(double value);
  double get_value() const;
};

class AdditionExpression : public Expression {
  std::shared_ptr<Expression> m_left{nullptr};
  std::shared_ptr<Expression> m_right{nullptr};

public:
  AdditionExpression(Expression *left, Expression *right);
  Expression *left_exp() const;
  Expression *right_exp() const;
};
