#include "Shape.h"

enum class ShapeType {
    Rectangle,
    Circle,
    Square
};

class ShapeFactory {
public:
    Shape getShape(ShapeType type) {
        switch(type) {
            case ShapeType::Rectangle:
                return Rectangle();
            case ShapeType::Circle:
                return Circle();
            case ShapeType::Square:
                return Square();
            default:
                return Rectangle();
        }
    }
    // other shape related helper methods.
};