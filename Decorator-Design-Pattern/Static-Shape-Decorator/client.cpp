#include "shape.h"
#include "colored_shape.h"
#include "transparent_shape.h"
#include <iostream>

int main() 
{
    Square square{5};
    std::cout << square.introduce() << std::endl;

    ColoredShape<Square> blue_square{"blue", 5};
    std::cout << blue_square.introduce() << std::endl;

    TransparentShape<Circle> half_visible_circle{0.5f, 10};
    std::cout << half_visible_circle.introduce() << std::endl;

    TransparentShape<ColoredShape<Circle>> half_visible_blue_circle{0.5f, "blue", 10};
    std::cout << half_visible_blue_circle.introduce() << std::endl;
    
    /**
     * Note that now we have access to the member functions of the base object.
    */
    half_visible_blue_circle.resize(2);
    std::cout << half_visible_blue_circle.introduce() << std::endl;
}