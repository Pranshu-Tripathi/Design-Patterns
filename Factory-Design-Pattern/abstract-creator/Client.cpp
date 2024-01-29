#include "Shape.h"
#include "ShapeFactory.h"

int main() {
    auto factory = new RectangleFactory();
    auto shape = factory->getShape();
    shape.draw();
}

/**
 * Disadvantages:
 *    - For every new concrete class we need to create a new factory class.
 *    - Logic Duplication.
*/