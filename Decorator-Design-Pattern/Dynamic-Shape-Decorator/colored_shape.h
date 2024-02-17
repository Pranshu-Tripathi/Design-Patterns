#pragma once

#include "shape.h"
#include <string>

/**
 * This is a decorator class that adds color functionality to a shape.
*/
class ColoredShape: public Shape {
    protected:
        Shape& shape; // reference to underlying shape
        std::string color;
    public:
        ColoredShape(Shape& shape, std::string color);
        ~ColoredShape() = default;
        std::string introduce() override;
        
};