#pragma once

#include <memory>
#include <map>
#include "drink.h"

class HotDrinkFactory;
class ColdDrinkFactory;
class CoffeeFactory;
class TeaFactory;

class DrinkFactory{

std::map<std::string, std::unique_ptr<HotDrinkFactory>> hot_drink_factories;
std::map<std::string, std::unique_ptr<ColdDrinkFactory>> cold_drink_factories;

protected:
    std::unique_ptr<Drink> make_hot_drink(std::string name) {
        return hot_drink_factories[name]->make();
    }
    virtual std::unique_ptr<Drink> make_cold_drink(std::string name) {
        return cold_drink_factories[name]->make();
    }

    void assemble_cold_drink_factories() {
        cold_drink_factories["coffee"] = std::make_unique<CoffeeFactory>();
    }

    void assemble_hot_drink_factories() {
        hot_drink_factories["tea"] = std::make_unique<TeaFactory>();
    }

public:
    DrinkFactory() {
        assemble_hot_drink_factories();
        assemble_cold_drink_factories();
    }
    virtual ~DrinkFactory() = default;
    virtual std::unique_ptr<Drink> make_drink(DrinkType drink_type, std::string drink_name) {
        switch(drink_type){
            case DrinkType::HOT_DRINK:
                return make_hot_drink(drink_name);
            case DrinkType::COLD_DRINK:
                return make_cold_drink(drink_name);
            default:
                return nullptr;
        }
    }
};

class HotDrinkFactory: public DrinkFactory{
protected:
    void boilDrink(float temperature) {
        std::cout << "Boiling drink to " << temperature << " degrees" << std::endl;
    };
public:
    virtual ~HotDrinkFactory() = default;
    virtual std::unique_ptr<Drink> make() = 0;
};

class ColdDrinkFactory: public DrinkFactory{
protected:
    void coolDrink(float temperature) {
        std::cout << "Cooling drink to " << temperature << " degrees" << std::endl;
    };

public:
    virtual ~ColdDrinkFactory() = default;
    virtual std::unique_ptr<Drink> make() = 0;
};


class TeaFactory : public HotDrinkFactory{
public:
    virtual ~TeaFactory() = default;
    virtual std::unique_ptr<Drink> make() override{
        auto drink = std::make_unique<Tea>();
        drink->prepare(200);
        HotDrinkFactory::boilDrink(20);
        return drink;
    }
};


class CoffeeFactory : public ColdDrinkFactory{
public:
    virtual ~CoffeeFactory() = default;
    virtual std::unique_ptr<Drink> make() override{
        auto drink = std::make_unique<Coffee>();
        drink->prepare(200);
        ColdDrinkFactory::coolDrink(20);
        return drink;
    }
};

