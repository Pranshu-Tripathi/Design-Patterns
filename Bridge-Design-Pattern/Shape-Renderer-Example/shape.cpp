#include "shape.h"
#include <iostream>

Circle::Circle(Renderer* renderer, float radius): Shape(renderer), radius(radius){}

void Circle::draw(){
    renderer->render_shape();
}

void Circle::resize(float factor){
    std::cout << "Resizing Circle by factor " << factor << std::endl;
    radius *= factor;
}

Square::Square(Renderer* renderer, float side): Shape(renderer), side(side){}

void Square::draw(){
    renderer->render_shape();
}

void Square::resize(float factor){
    std::cout << "Resizing Square by factor " << factor << std::endl;
    side *= factor;
}