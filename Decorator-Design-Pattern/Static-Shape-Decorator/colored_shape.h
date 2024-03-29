#pragma once
#include <string>
#include "shape.h"
#include "shape_concept.h"

template <IsAShape T>
class ColoredShape : public T
{
    std::string color;
    public:
        template <typename... Args>
        ColoredShape(const std::string& color, Args... args);
        std::string introduce() override;
};