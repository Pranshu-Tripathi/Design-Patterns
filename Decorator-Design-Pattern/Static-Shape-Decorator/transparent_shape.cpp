#include "transparent_shape.h"
#include "colored_shape.h"
#include <sstream>

template <IsAShape T>
template <typename... Args>
TransparentShape<T>::TransparentShape(float transparency, Args... args)
    : T(std::forward<Args>(args)...), transparency(transparency)
{
}

template <IsAShape T>
std::string TransparentShape<T>::introduce()
{
    std::ostringstream oss;
    oss << T::introduce() << " and has " << transparency * 100 << "% transparency"; 
    return oss.str();
}

// Explicit instantiations
template class TransparentShape<Square>;
template class TransparentShape<Circle>;
template class TransparentShape<ColoredShape<Square>>;
template class TransparentShape<ColoredShape<Circle>>;
template TransparentShape<Square>::TransparentShape(float, int);
template TransparentShape<Circle>::TransparentShape(float, int);
template TransparentShape<ColoredShape<Circle>>::TransparentShape(float, const std::string&, int);
template TransparentShape<ColoredShape<Square>>::TransparentShape(float, const std::string&, int);
template TransparentShape<ColoredShape<Circle>>::TransparentShape(float, char const* color, int); // Wierd I had to declare this!
