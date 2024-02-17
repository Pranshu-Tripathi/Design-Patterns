#include "colored_shape.h"
#include <sstream>

template <IsAShape T>
template <typename... Args>
ColoredShape<T>::ColoredShape(const std::string& color, Args... args)
    : T(std::forward<Args>(args)...), color(color)
{
}

template <IsAShape T>
std::string ColoredShape<T>::introduce()
{
    std::ostringstream oss;
    oss << T::introduce() << " which has the color " << color;
    return oss.str();
}

// Explicit instantiations
template class ColoredShape<Square>;
template class ColoredShape<Circle>;
template ColoredShape<Square>::ColoredShape(const std::string&, int);
template ColoredShape<Circle>::ColoredShape(const std::string&, int);
