#include "shape.h"
#include <sstream>

Square::Square(int side): side(side) {};

std::string Square::introduce() {
    std::ostringstream oss;
    oss << "I am a square with side " << side;
    return oss.str();
}

Circle::Circle(int radius): radius(radius) {};

std::string Circle::introduce() {
    std::ostringstream oss;
    oss << "I am a circle with radius " << radius;
    return oss.str();
}

void Circle::resize(int factor) {
    radius *= factor;
}