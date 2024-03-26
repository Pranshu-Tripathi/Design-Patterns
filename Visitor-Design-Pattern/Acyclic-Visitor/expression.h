#pragma once

#include <memory>

class VisitorBase;
class Expression {
public:
  virtual ~Expression() = default;
  Expression();
  virtual void accept(VisitorBase &obj);
};

class DoubleExpression : public Expression {
  double m_value;

public:
  DoubleExpression(double value);
  double get_value() const;

  void accept(VisitorBase &obj) override;
};

class AdditionExpression : public Expression {
  std::shared_ptr<Expression> m_left{nullptr};
  std::shared_ptr<Expression> m_right{nullptr};

public:
  AdditionExpression(Expression *left, Expression *right);
  Expression *left_exp() const;
  Expression *right_exp() const;
  void accept(VisitorBase &obj) override;
};

class SubtractionExpression : public Expression {
  std::shared_ptr<Expression> m_left{nullptr};
  std::shared_ptr<Expression> m_right{nullptr};

public:
  SubtractionExpression(Expression *left, Expression *right);
  Expression *left_exp() const;
  Expression *right_exp() const;
  void accept(VisitorBase &obj) override;
};
