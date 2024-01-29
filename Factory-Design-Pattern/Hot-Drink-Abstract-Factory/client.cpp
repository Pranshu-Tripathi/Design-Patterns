#include "drink_factory.h"

int main()
{
    auto factory = new DrinkFactory();
    auto drink = factory->make_drink(DrinkType::HOT_DRINK, "tea");
    auto drink2 = factory->make_drink(DrinkType::COLD_DRINK, "coffee");
}