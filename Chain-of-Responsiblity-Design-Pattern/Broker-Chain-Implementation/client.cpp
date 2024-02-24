#include "creature.h"
#include "creature_modifiers.h"
#include "game.h"
#include <iostream>
int main() {
  std::cout << "Creating game..." << std::endl;
  Game game;

  Creature batman{game, "batman", 2, 2};

  std::cout << batman.to_string() << std::endl;

  {
    DoubleAttackModifer dam{game, batman};

    std::cout << batman.to_string() << std::endl;
  }
  std::cout << batman.to_string() << std::endl;
}
