#pragma once
#include <vector>
#include <string>

class GraphicalObject{
    public:
        virtual void draw() = 0;
};

class Line : public GraphicalObject{
    public:
        void draw() override;
};

class Circle : public GraphicalObject{
    public:
        void draw() override;
};

class Group : public GraphicalObject{
    public:
        Group(std::string name) : name(name){}
        void draw() override;
        void add(GraphicalObject* obj);
        void remove(GraphicalObject* obj);
        std::string getName() const { return name; }
    private:
        std::vector<GraphicalObject*> objects;
        std::string name;
};

