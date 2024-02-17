#include "colored_shape.h"
#include <sstream>

template <IsAShape T>
std::string ColoredShape<T>::introduce()
{
    std::ostringstream oss;
    oss << T::introduce() << " has the color " << color;
    return oss.str();
}

// Explicit instantiations
template class ColoredShape<Square>;
template class ColoredShape<Circle>;
