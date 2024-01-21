#include <iostream>
#include <string>

class Pizza
{
    std::string crust;
    std::string sauce;
    std::string topping;

    public:
        void setCrust(std::string crust)
        {
            this->crust = crust;
        }

        void setSauce(std::string sauce)
        {
            this->sauce = sauce;
        }

        void setTopping(std::string topping)
        {
            this->topping = topping;
        }
    
        void showPizza()
        {
            std::cout << "Crust: " << crust << std::endl;
            std::cout << "Sauce: " << sauce << std::endl;
            std::cout << "Topping: " << topping << std::endl;
        }
};

/**
 * Director Class
 * Knows high level logic of how to make pizza.
 * Delegates the concreate implementation to the passed builder.
*/
class PizzaStation
{
    public:
        void processPizza(PizzaBuilder* pizzaBuilder)
        {
            pizzaBuilder->buildCrust();
            pizzaBuilder->buildSauce();
            pizzaBuilder->buildTopping();
        }

        PizzaStation()
        {
            // we can set a builder here as well. Disadvantage is that we can't change the builder at runtime.
        }
};


/**
 * This is pizza builder interface.
 * Different types of builders will follow the same interface.
*/
class PizzaBuilder
{
    protected:
        Pizza* pizza;
    
    public:
        Pizza* getPizza()
        {
            return pizza;
        }

        virtual void buildCrust() = 0;
        virtual void buildSauce() = 0;
        virtual void buildTopping() = 0;
};

/**
 * Concreate builder classes.
 * They will implement the interface and provide their own implementation.
*/
class MexianPizzaBuilder : public PizzaBuilder
{
    public:
        MexianPizzaBuilder()
        {
            pizza = new Pizza();
        }
        void buildCrust()
        {
            pizza->setCrust("Mexican Crust");
        }

        void buildSauce()
        {
            pizza->setSauce("Mexican Sauce");
        }

        void buildTopping()
        {
            pizza->setTopping("Mexican Topping");
        }
};

/**
 * Concreate builder classes.
 * They will implement the interface and provide their own implementation.
*/
class AmericanPizzaBuilder : public PizzaBuilder
{
    public:
        AmericanPizzaBuilder()
        {
            pizza = new Pizza();
        }
        void buildCrust()
        {
            pizza->setCrust("American Crust");
        }

        void buildSauce()
        {
            pizza->setSauce("American Sauce");
        }

        void buildTopping()
        {
            pizza->setTopping("American Topping");
        }
};

int main()
{
    PizzaStation pizzaStation;  
    PizzaBuilder* pizzaBuilder = new MexianPizzaBuilder();
    pizzaStation.processPizza(pizzaBuilder);
    auto pizza = pizzaBuilder->getPizza();
    pizza->showPizza();

    pizzaBuilder = new AmericanPizzaBuilder();
    pizzaStation.processPizza(pizzaBuilder);
    pizza = pizzaBuilder->getPizza();
    pizza->showPizza();
}