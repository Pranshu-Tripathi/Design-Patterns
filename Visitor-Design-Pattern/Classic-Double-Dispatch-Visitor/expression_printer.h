#pragma once

#include "expression_visitor.h"
#include <memory>
#include <sstream>

class DoubleExpression;
class AdditionExpression;
class SubtractionExpression;

class ExpressionPrinter : public ExpressionVisitor {
  std::ostringstream m_expression;

public:
  ExpressionPrinter();
  std::string expr() const;
  void visit(DoubleExpression *de) override;
  void visit(AdditionExpression *ae) override;
  void visit(SubtractionExpression *se) override;
};
