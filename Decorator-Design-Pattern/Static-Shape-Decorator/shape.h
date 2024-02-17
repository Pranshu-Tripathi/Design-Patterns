#pragma once
#include <string>
/**
 * Shape interface
*/
class Shape
{
    public:
        virtual std::string introduce() = 0;
        Shape() = default;
        virtual ~Shape() = default;
};

/**
 * Concrete Square Shape classes
*/
class Square: public Shape{
        int side;
    public:
        Square(int side);
        std::string introduce() override;
};

/**
 * Concrete Circle Shape classes
*/
class Circle: public Shape{
        int radius;
    public:
        void resize(int factor);
        Circle(int radius);
        std::string introduce() override;
};