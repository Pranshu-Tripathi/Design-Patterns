#include "expression_printer.h"
#include <iostream>

int main() {
  auto e = new AdditionExpression{
      new DoubleExpression{1},
      new AdditionExpression{
          new DoubleExpression{2},
          new SubtractionExpression{new DoubleExpression{4},
                                    new DoubleExpression{3}}}};

  auto exp_printer = new ExpressionPrinter();
  exp_printer->visit(*e);
  std::cout << exp_printer->expr() << std::endl;
  delete e;
  return 0;
}
