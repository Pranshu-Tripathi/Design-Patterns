#include "shape.h"
#include "colored_shape.h"
#include "transparent_shape.h"
#include <iostream>

int main() 
{
    Square square{5};
    std::cout << square.introduce();
    ColoredShape red_square{square, "red"};
    std::cout << red_square.introduce();
    TransparentShape half_transparent_red_square{red_square, 0.5};
    std::cout << half_transparent_red_square.introduce();


    Circle circle{5};
    std::cout << circle.introduce();
    ColoredShape green_circle{circle, "green"};
    std::cout << green_circle.introduce();

    /**
     * The following code will not work because the resize method is not part of the Shape interface.
     * This exposes the problem with dynamic decorator - we cannot call methods that are not part of
     * the interface. Assuming resize is a circle centric method it cannot be moved to shape interface.
    */
    // green_circle.resize(2);
    // std::cout << green_circle.introduce();
}