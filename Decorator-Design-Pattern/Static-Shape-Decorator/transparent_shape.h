#pragma once

#include <string>
#include "shape.h"
#include "shape_concept.h"

template <IsAShape T>
class TransparentShape: public T
{
    float transparency;
    public:
        template <typename... Args>
        TransparentShape(float transparency, Args... args);
        std::string introduce() override;
};