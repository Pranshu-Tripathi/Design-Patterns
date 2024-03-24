#pragma once

#include "expression_visitor.h"

class ExpressionEvaluator : public ExpressionVisitor {
  double m_result{0};

public:
  ExpressionEvaluator();
  double value() const;
  void visit(DoubleExpression *de) override;
  void visit(AdditionExpression *ae) override;
  void visit(SubtractionExpression *se) override;
};
