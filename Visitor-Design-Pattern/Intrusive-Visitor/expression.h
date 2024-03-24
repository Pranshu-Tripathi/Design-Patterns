#pragma once
#include <memory>
#include <sstream>
class Expression {
public:
  Expression();
  virtual ~Expression() = default;
  virtual void print(std::ostringstream &print_exp) = 0;
};

class DoubleExpression : public Expression {
  double m_value;

public:
  DoubleExpression(double value);
  void print(std::ostringstream &print_exp) override;
};

class AdditionExpression : public Expression {
  std::shared_ptr<Expression> m_left{nullptr};
  std::shared_ptr<Expression> m_right{nullptr};

public:
  AdditionExpression(Expression *left, Expression *right);
  void print(std::ostringstream &print_exp) override;
};
