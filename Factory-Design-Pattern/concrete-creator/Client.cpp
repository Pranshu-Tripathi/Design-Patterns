#include "Shape.h"
#include "ShapeFactory.h"

int main(){
    auto factory = new ShapeFactory();
    auto shape = factory->getShape(ShapeType::Rectangle);
    shape.draw();
}