#pragma once

#include "creature.h"
#include "creature_modifier.h"
#include <iostream>
class DoubleAttackModifer : public CreatureModifier {
public:
  DoubleAttackModifer(Creature &creature) : CreatureModifier(creature) {}
  void handle() override {
    auto attack = creature.getAttack();
    creature.setAttack(attack * 2);
    std::cout << creature.toString() << std::endl;
    CreatureModifier::handle();
  }
};

class CurseActionModifier : public CreatureModifier {
public:
  CurseActionModifier(Creature &creature) : CreatureModifier(creature) {}
  void handle() override {
    /*
        This class curses the creature to see no op on his modifiers.
        This breaks the chain of responsibility by not calling the base
        handle class.
    */
    std::cout << "Broke Chain At Curse" << std::endl;
  }
};

class DefenceDoubleModifier : public CreatureModifier {
public:
  DefenceDoubleModifier(Creature &creature) : CreatureModifier(creature) {}
  void handle() override {
    auto attack = creature.getAttack();
    auto defence = creature.getDefence();
    if (attack <= 4) { /* Additional Checks */
      creature.setDefence(defence * 2);
    }
    std::cout << creature.toString() << std::endl;
    CreatureModifier::handle();
  }
};
