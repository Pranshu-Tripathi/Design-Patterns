#pragma once
#include "pizza.hpp"

/**
 * This is a base builder class that all the builders inherit.
 * Reason of making this to always have the reference of the pizza object.
 * If we simply used the PizzaBuilder class we will get duplications of Pizza object.
*/

class PizzaBuilderBase {

    protected:
        Pizza& pizza;
        explicit PizzaBuilderBase(Pizza& pizza) : pizza(pizza) {}
    public:
        /**
         * Always get the same reference object.
        */
        operator Pizza() const {
            return std::move(pizza);
        }

        // Builder facets -> these are the public APIs that client will use to build pizza using different builders.
        PizzaCrustBuilder bakeCrust(){
            return PizzaCrustBuilder(pizza);
        }

        PizzaSauceBuilder addSauce(){
            return PizzaSauceBuilder(pizza);
        }

        PizzaToppingBuilder addTopping(){
            return PizzaToppingBuilder(pizza);
        }

        PizzaPackagingBuilder packPizza(){
            return PizzaPackagingBuilder(pizza);
        }

        PizzaCustomerBuilder deliverPizza(){
            return PizzaCustomerBuilder(pizza);
        }
};


/**
 * Contains the actual pizza object. Its reference is held by the base builder class.
*/
class PizzaBuilder : public PizzaBuilderBase {
    Pizza pizza;
    public:
        PizzaBuilder() : PizzaBuilderBase(pizza) {}
};

/**
 * Crust Builder
*/
class PizzaCrustBuilder : public PizzaBuilderBase {
    public:
        explicit PizzaCrustBuilder(Pizza& pizza) : PizzaBuilderBase(pizza) {}
        PizzaCrustBuilder& withCrust(const std::string& crust) {
            pizza.crust = crust;
            return *this;
        }
};

/**
 * Pizza Sauce Builder.
*/
class PizzaSauceBuilder : public PizzaBuilderBase {
    public:
        explicit PizzaSauceBuilder(Pizza& pizza) : PizzaBuilderBase(pizza) {}
        PizzaSauceBuilder& withSauce(const std::string& sauce) {
            pizza.sauce = sauce;
            return *this;
        }
};


/**
 * Pizza Topping Builder.
*/
class PizzaToppingBuilder : public PizzaBuilderBase {
    public:
        explicit PizzaToppingBuilder(Pizza& pizza) : PizzaBuilderBase(pizza) {}
        PizzaToppingBuilder& withTopping(const std::string& topping) {
            pizza.topping = topping;
            return *this;
        }
};

/**
 * Pizza Packaging Builder.
*/
class PizzaPackagingBuilder : public PizzaBuilderBase {
    public:
        explicit PizzaPackagingBuilder(Pizza& pizza) : PizzaBuilderBase(pizza) {}
        PizzaPackagingBuilder& withPackaging(const std::string& packaging) {
            pizza.packaging = packaging;
            return *this;
        }
};


/**
 * Pizza Customer Builder.
 * We can have multiple APIs here to set customer details.
*/
class PizzaCustomerBuilder : public PizzaBuilderBase {
    public:
        explicit PizzaCustomerBuilder(Pizza& pizza) : PizzaBuilderBase(pizza) {}
        PizzaCustomerBuilder& forCustomer(const std::string& customer) {
            pizza.customer = customer;
            return *this;
        }
        PizzaCustomerBuilder& atAddress(const std::string& address) {
            pizza.customer_address = address;
            return *this;
        }
        PizzaCustomerBuilder& withContactDetails (const std::string& contact_details) {
            pizza.customer_phone = contact_details;
            return *this;
        }
};