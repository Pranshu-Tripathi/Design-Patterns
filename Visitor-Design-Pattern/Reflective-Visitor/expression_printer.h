#pragma once

#include <memory>
#include <sstream>

class Expression;

class ExpressionPrinter {
  std::ostringstream m_expression;

public:
  ExpressionPrinter();
  std::string expr() const;
  void print(Expression *exp);
};
