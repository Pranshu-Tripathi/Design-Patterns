#include "shape.h"
#include "colored_shape.h"
#include <iostream>

int main() 
{
    Square square{5};
    std::cout << square.introduce() << std::endl;

    ColoredShape<Square> blue_square{"blue", 5};
    std::cout << blue_square.introduce() << std::endl;
}