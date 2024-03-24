#pragma once
#include <memory>
#include <sstream>

class ExpressionVisitor;
class Expression {
public:
  Expression();
  virtual ~Expression() = default;
  virtual void accept(ExpressionVisitor *visitor) = 0;
};

class DoubleExpression : public Expression {
  double m_value;

public:
  DoubleExpression(double value);
  double get_value() const;
  void accept(ExpressionVisitor *visitor) override;
};

class AdditionExpression : public Expression {
  std::shared_ptr<Expression> m_left{nullptr};
  std::shared_ptr<Expression> m_right{nullptr};

public:
  AdditionExpression(Expression *left, Expression *right);
  Expression *left_exp() const;
  Expression *right_exp() const;
  void accept(ExpressionVisitor *visitor) override;
};

class SubtractionExpression : public Expression {
  std::shared_ptr<Expression> m_left{nullptr};
  std::shared_ptr<Expression> m_right{nullptr};

public:
  SubtractionExpression(Expression *left, Expression *right);
  Expression *left_exp() const;
  Expression *right_exp() const;
  void accept(ExpressionVisitor *visitor) override;
};
