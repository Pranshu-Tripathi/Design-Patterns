#pragma once
#include <iostream>

enum class DrinkType{
    HOT_DRINK,
    COLD_DRINK
};

class Drink{
public:
    virtual ~Drink() = default;
    virtual void prepare(int volume) = 0;
};

class HotDrink : public Drink{
    void boilDrink(float temperature){
        std::cout << "Boiling drink to " << temperature << " degrees" << std::endl;
    };
public:
    virtual ~HotDrink() = default;
    virtual void prepare(int volume) override = 0;
};


class ColdDrink : public Drink{
    
public:
    virtual ~ColdDrink() = default;
    virtual void prepare(int volume) override = 0;
};


class Tea : public HotDrink{
public:
    virtual void prepare(int volume) override{
        std::cout << "Preparing tea with " << volume << " ml" << std::endl;
    }
};

class Coffee : public ColdDrink{
public:
    virtual void prepare(int volume) override{
        std::cout << "Preparing coffee with " << volume << " ml" << std::endl;
    }
};