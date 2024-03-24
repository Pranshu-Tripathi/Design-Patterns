#include "expression_printer.h"
#include "expression.h"
#include <memory>
#include <stdexcept>

ExpressionPrinter::ExpressionPrinter() {
  m_expression.str("");
  m_expression.clear();
}

std::string ExpressionPrinter::expr() const { return m_expression.str(); }

void ExpressionPrinter::print(Expression *exp) {
  /*
  Reflective visitor cause reflects on object type
  */
  if (auto double_exp = dynamic_cast<DoubleExpression *>(exp)) {
    m_expression << double_exp->get_value();
  } else if (auto addition_exp = dynamic_cast<AdditionExpression *>(exp)) {
    m_expression << "(";
    print(addition_exp->left_exp());
    m_expression << " + ";
    print(addition_exp->right_exp());
    m_expression << ")";
  } else {
    throw std::runtime_error("Cannot deduce the expression type");
  }
}
