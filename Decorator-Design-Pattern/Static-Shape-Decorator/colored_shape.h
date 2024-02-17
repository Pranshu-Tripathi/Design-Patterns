#pragma once
#include <concepts>
#include <type_traits>
#include <string>
#include "shape.h"

template <typename T>
concept IsAShape = std::is_base_of<Shape, T>::value;

template <IsAShape T>
class ColoredShape : public T
{
    std::string color;
    public:
        template <typename... Args>
        ColoredShape(const std::string& color, Args... args)
            : T(std::forward<Args>(args)...), color{color}
        {
        }
        std::string introduce() override;
};