#pragma once
#include <iostream>
#include <string>

template <typename T>

class Property {
    T value;
    std::string name = "Property";
    public:
        Property(T value) {
            this->value = value;
        }
        Property(T value, std::string name) {
            this->value = value;
            this->name = name;
        }
        operator T() {
            std::cout << name << "::Reading the value!" << std::endl; // "Log the reading of the property.
            return value;
        }
        T operator=(T new_value) {
            std::cout << name  << "::Assignment!" << std::endl; // "Log the changes to the property.
            return value = new_value;
        }
        void operator>>(std::string name) {
            std::cout << this->name << " is updated sucessfully to :: " << name << std::endl;
            this->name = name;
        }
};

class CreatureProxy {
    public:
    CreatureProxy(int strenght, int health, int agility) : 
        strenth(strenght, "strength"),
         health(health, "health"),
         agility(agility, "agility") {}
    Property<int> strenth{10};
    Property<int> health{100};
    Property<int> agility{60};
};

