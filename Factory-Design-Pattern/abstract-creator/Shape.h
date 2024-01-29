class Shape {
    public:
    virtual void draw() = 0;
};

class Rectangle : public Shape {
    void draw();
};

class Circle : public Shape {
    void draw();
};

class Square : public Shape {
    void draw();
};