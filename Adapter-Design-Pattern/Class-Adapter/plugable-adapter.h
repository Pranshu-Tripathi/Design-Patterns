#include <iostream>

// PluggableAdapter interface
class PluggableAdapter {
public:
    virtual void plug() const = 0;
};

// Adaptee (existing class with incompatible interface)
class Adaptee {
public:
    void specificRequest() const {
        std::cout << "Adaptee's specific request" << std::endl;
    }
};

// Class Adapter
class Adapter : public PluggableAdapter, private Adaptee {
public:
    void plug() const override {
        // Using Adaptee's specificRequest to implement PluggableAdapter's plug
        specificRequest();
    }
};

// Another Adapter
class AnotherAdapter : public PluggableAdapter {
public:
    void plug() const override {
        std::cout << "AnotherAdapter's plug" << std::endl;
    }
};

// Client code
void clientCode(const PluggableAdapter& adapter) {
    adapter.plug();
}

int main() {
    // Using the first adapter
    Adapter adapter1;
    clientCode(adapter1);

    // Using another adapter
    AnotherAdapter adapter2;
    clientCode(adapter2);

    return 0;
}
