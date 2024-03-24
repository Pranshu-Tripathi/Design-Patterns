#pragma once

class DoubleExpression;
class AdditionExpression;
class SubtractionExpression;

class ExpressionVisitor {
public:
  ExpressionVisitor(){};
  virtual ~ExpressionVisitor() = default;
  virtual void visit(AdditionExpression *expr) = 0;
  virtual void visit(DoubleExpression *expr) = 0;
  virtual void visit(SubtractionExpression *expr) = 0;
};
