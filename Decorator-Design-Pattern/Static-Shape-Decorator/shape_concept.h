#pragma once
#include <concepts>
#include <type_traits>

template <typename T>
concept IsAShape = std::is_base_of<Shape, T>::value;