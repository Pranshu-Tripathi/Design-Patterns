#include "expression.h"
#include <iostream>
#include <sstream>

int main() {
  auto e = new AdditionExpression{
      new DoubleExpression{1},
      new AdditionExpression{new DoubleExpression{2},
                             new AdditionExpression{new DoubleExpression{3},
                                                    new DoubleExpression{4}}}};

  std::ostringstream print_exp; /*this is our visitor that will traverse
 through all components. */
  e->print(print_exp);
  std::cout << "Expression :" << print_exp.str() << std::endl;
  delete e;
  return 0;
}
