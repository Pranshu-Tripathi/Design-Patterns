#include "expression_evaluator.h"
#include "expression.h"

ExpressionEvaluator::ExpressionEvaluator() : ExpressionVisitor(){};

double ExpressionEvaluator::value() const { return m_result; }

void ExpressionEvaluator::visit(DoubleExpression *de) {
  m_result = de->get_value();
}

void ExpressionEvaluator::visit(AdditionExpression *ae) {
  ae->left_exp()->accept(this);
  auto left_value = m_result;
  ae->right_exp()->accept(this);
  auto right_value = m_result;
  m_result = left_value + right_value;
}

void ExpressionEvaluator::visit(SubtractionExpression *se) {
  se->left_exp()->accept(this);
  auto left_value = m_result;
  se->right_exp()->accept(this);
  auto right_value = m_result;
  m_result = left_value - right_value;
}
