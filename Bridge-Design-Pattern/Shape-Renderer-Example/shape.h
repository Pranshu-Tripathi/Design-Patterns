#pragma once
#include "renderer.h"

class Shape{
    public:
        virtual void draw() = 0;
        virtual void resize(float factor) = 0;
        virtual ~Shape() = default;
    protected:
        /**
         * This object will delegate task to respective renderer type.
         * Hence is the bridge between Shape and Renderer.
        */
        Shape(Renderer* renderer) : renderer{renderer}{}
        Renderer* renderer;
};

class Circle : public Shape{
    public:
        Circle(Renderer* renderer, float radius);
        void draw() override;
        void resize(float factor) override;
    private:
        float radius;
};

class Square : public Shape{
    public:
        Square(Renderer* renderer, float side);
        void draw() override;
        void resize(float factor) override;
    private:
        float side;
}; 