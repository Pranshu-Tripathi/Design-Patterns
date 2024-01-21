#include <iostream>
#include "pizza_builders.hpp"
#include "pizza.hpp"
int main()
{

    /**
     * Fluent Builder Facade Pattern
     * Here we are using multiple builders and are switching between them using the builder facets.
     * Such pattern is used when object creation is a combination of complicated objects.
     */
    Pizza pizza = Pizza::makePizza()
        .bakeCrust().withCrust("Mexican Crust")
        .addSauce().withSauce("Mexican Sauce")
        .addTopping().withTopping("Mexican Topping")
        .packPizza().withPackaging("Box Packaging")
        .deliverPizza().forCustomer("John Doe").atAddress("123 Main Street").withContactDetails("1234567890");

    std::cout << pizza << std::endl;
}