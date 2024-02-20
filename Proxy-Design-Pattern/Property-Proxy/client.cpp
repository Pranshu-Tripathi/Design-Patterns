#include "creature.h"
#include "creature_proxy.h"
#include <iostream>

int main()
{
    Creature batman{50, 100, 60};

    std::cout << batman.strenght << std::endl;
    std::cout << batman.health << std::endl;
    batman.agility = 70;
    std::cout << batman.agility << std::endl;
    
    /**
     * Now we want to add getter and setters to
     * properties that are part of the Creature class.
     * This is provided as properties in some programming
     * languages like C# and Python.
     * But now here we need to make getters and setters for it.
    */
   // batman.get_strenght(); -> If already batman.strenght was implemented
   // it will be to much work to replace every where
   //Also we want to log if someone updates these parameters just to track the changes.
   // We can use the proxy pattern to do this.


    CreatureProxy batman_proxy{50, 100, 60};
    std::cout << batman_proxy.strenth << std::endl;
    std::cout << batman_proxy.health << std::endl;
    batman_proxy.agility = 70;
    std::cout << batman_proxy.agility << std::endl;
    batman_proxy.strenth >> "joker hate";

    /**
     * Above implementation almost mimics the current Creature implementation.
     * But internally it provides logging and name setting option to a property.
    */
}