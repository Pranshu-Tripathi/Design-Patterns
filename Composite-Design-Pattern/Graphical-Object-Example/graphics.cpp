#include "graphics.h"
#include <iostream>

void Line::draw(){
    std::cout << "Drawing Line" << std::endl;
}

void Circle::draw(){
    std::cout << "Drawing Circle" << std::endl;
}

void Group::draw(){
    std::cout << "Drawing Group " << getName() << " : " << std::endl;
    for(const auto& obj : objects){
        obj->draw();
    }
}

void Group::add(GraphicalObject* obj){
    objects.push_back(obj);
}

void Group::remove(GraphicalObject* obj){
    auto iter = std::find(objects.begin(), objects.end(), obj);
    if(iter != objects.end()){
        objects.erase(iter);
    }
}
