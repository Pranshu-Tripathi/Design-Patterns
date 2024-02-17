#pragma once

#include "shape.h"
#include <string>

/**
 * This is a decorator class that adds transparency functionality to a shape.
*/
class TransparentShape : public Shape {
    protected:
        Shape& shape; // reference to underlying shape
        float transparency;
    public:
        TransparentShape(Shape& shape, float transparency);
        ~TransparentShape() = default;
        std::string introduce() override;
};