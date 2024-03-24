#include "expression.h"
#include "expression_printer.h"
#include <iostream>

int main() {
  auto e = new AdditionExpression{
      new DoubleExpression{1},
      new AdditionExpression{new DoubleExpression{2},
                             new AdditionExpression{new DoubleExpression{3},
                                                    new DoubleExpression{4}}}};

  ExpressionPrinter exp_printer;
  exp_printer.print(e);
  std::cout << exp_printer.expr() << std::endl;
  delete e;
  return 0;
}
