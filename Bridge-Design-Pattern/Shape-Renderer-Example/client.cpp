#include <iostream>
#include "renderer.h"
#include "shape.h"

int main()
{
    auto renderer = new VectorRenderer();
    auto circle = new Circle(renderer, 5);
    circle->draw(); // Drawing Shape using vector rendering

}