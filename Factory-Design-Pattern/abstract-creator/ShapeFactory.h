#include "Shape.h"

class ShapeFactory {
    public:
    Shape getShape() {
        return buildShape();
    }
protected:
    virtual Shape buildShape() = 0;

    // can have other helper methods here.
};

class RectangleFactory : public ShapeFactory {
    Shape buildShape(){
        return Rectangle();
    }
    // other rectangle related helper methods.
};

class CircleFactory : public ShapeFactory {
    Shape buildShape(){
        return Circle();
    }
    // other circle related helper methods.
};

class SquareFactory : public ShapeFactory {
    Shape buildShape(){
        return Square();
    }
    // other square related helper methods.
};