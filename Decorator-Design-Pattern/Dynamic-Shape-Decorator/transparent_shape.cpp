#include "transparent_shape.h"
#include <sstream>

TransparentShape::TransparentShape(Shape& shape, float transparency): shape(shape), transparency(transparency) {};

std::string TransparentShape::introduce() {
    std::ostringstream oss;
    oss << shape.introduce() << " and I am " << transparency * 100 << "% transparent" << std::endl;
    return oss.str();
}