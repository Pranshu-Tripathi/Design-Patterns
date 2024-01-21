#pragma once
#include <string>
#include <iostream>

/**
 * This is pizza data member class.
*/

class Pizza
{
    std::string crust;
    std::string sauce;
    std::string topping;
    std::string packaging;
    std::string customer;
    std::string customer_address;
    std::string customer_phone;

    public:
    
        friend std::ostream& operator<<(std::ostream& os, const Pizza& pizza)
        {
            os << "Crust: " << pizza.crust << std::endl;
            os << "Sauce: " << pizza.sauce << std::endl;
            os << "Topping: " << pizza.topping << std::endl;
            os << "Packaging: " << pizza.packaging << std::endl;
            os << "Customer: " << pizza.customer << std::endl;
            os << "Customer Address: " << pizza.customer_address << std::endl;
            return os;
        }

        /**
         * This returns a pizza builder object.
        */
        static PizzaBuilder makePizza(){
            return PizzaBuilder{};
        }

    friend class PizzaBuilder;
    friend class PizzaCrustBuilder;
    friend class PizzaSauceBuilder;
    friend class PizzaToppingBuilder;
    friend class PizzaPackagingBuilder;
    friend class PizzaCustomerBuilder;
};