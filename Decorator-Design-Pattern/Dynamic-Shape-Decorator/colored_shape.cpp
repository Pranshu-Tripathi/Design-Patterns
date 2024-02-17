#include "colored_shape.h"
#include <sstream>

ColoredShape::ColoredShape(Shape& shape, std::string color): shape(shape), color(color) {};

std::string ColoredShape::introduce() {
    std::ostringstream oss;
    oss << shape.introduce() << " and I am colored " << color << std::endl;
    return oss.str();
}