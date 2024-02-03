#include <iostream>

// Target interface
class Target {
public:
    virtual void request() const = 0;
};

// Adaptee (existing class with incompatible interface)
class Adaptee {
public:
    void specificRequest() const {
        std::cout << "Adaptee's specific request" << std::endl;
    }
};

// Class Adapter
class Adapter : public Target, private Adaptee {
public:
    void request() const override {
        // Using Adaptee's specificRequest to implement Target's request
        specificRequest();
    }
};

// Client code
void clientCode(const Target& target) {
    target.request();
}

int main() {
    // Using the Adapter to make Adaptee's interface compatible with Target's
    Adapter adapter;
    clientCode(adapter);

    return 0;
}
