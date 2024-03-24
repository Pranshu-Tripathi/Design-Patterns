#include "expression.h"
#include "expression_evaluator.h"
#include "expression_printer.h"
#include "expression_visitor.h"
#include <iostream>
#include <vector>

int main() {
  auto e = new AdditionExpression{
      new DoubleExpression{1},
      new AdditionExpression{
          new DoubleExpression{2},
          new SubtractionExpression{new DoubleExpression{4},
                                    new DoubleExpression{3}}}};

  auto exp_printer = new ExpressionPrinter();
  auto exp_eval = new ExpressionEvaluator();

  std::vector<ExpressionVisitor *> visitors = {exp_printer, exp_eval};
  for (const auto &visitor : visitors) {
    visitor->visit(e);
  }
  std::cout << exp_printer->expr() << " = " << exp_eval->value() << std::endl;
  delete e;
  return 0;
}
