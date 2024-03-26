#include "expression_printer.h"

ExpressionPrinter::ExpressionPrinter() {
  m_expression.str("");
  m_expression.clear();
}

std::string ExpressionPrinter::expr() const { return m_expression.str(); }

void ExpressionPrinter::visit(DoubleExpression &de) {
  m_expression << de.get_value();
}

void ExpressionPrinter::visit(AdditionExpression &ae) {
  m_expression << "(";
  ae.left_exp()->accept(*this);
  m_expression << " + ";
  ae.right_exp()->accept(*this);
  m_expression << ")";
}

void ExpressionPrinter::visit(SubtractionExpression &se) {
  m_expression << "(";
  se.left_exp()->accept(*this);
  m_expression << " - ";
  se.right_exp()->accept(*this);
  m_expression << ")";
}
