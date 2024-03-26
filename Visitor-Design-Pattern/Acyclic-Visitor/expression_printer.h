#pragma once

#include "expression.h"
#include "visitor.h"
#include <sstream>

/*
Advantage of this inheritance is that we can simly remove any of
the template inheritance and this will still work. (only it will
not visit that class).

for `(1 + (2 + (4 - 3)))` input, if we comment out the
DoubleExpression Visitor template logic here, then the
visit response will be `( + ( + ( - )))`.
*/
class ExpressionPrinter : public VisitorBase,
                          public Visitor<DoubleExpression>,
                          public Visitor<AdditionExpression>,
                          public Visitor<SubtractionExpression> {
  std::ostringstream m_expression;

public:
  ExpressionPrinter();
  std::string expr() const;
  void visit(DoubleExpression &de) override;
  void visit(AdditionExpression &ae) override;
  void visit(SubtractionExpression &se) override;
};
