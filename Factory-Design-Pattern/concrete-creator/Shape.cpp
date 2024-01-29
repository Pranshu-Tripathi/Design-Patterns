#include <iostream>
#include "Shape.h"

void Rectangle::draw() {
    std::cout << "Rectangle::draw()" << std::endl;
}

void Circle::draw() {
    std::cout << "Circle::draw()" << std::endl;
}

void Square::draw() {
    std::cout << "Square::draw()" << std::endl;
}