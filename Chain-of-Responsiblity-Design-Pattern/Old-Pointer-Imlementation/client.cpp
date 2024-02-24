#include "concrete_modifiers.h"
#include "creature.h"
#include "creature_modifier.h"
#include <iostream>
#include <ostream>

void apply_modification(Creature &creature) {
  CreatureModifier root{creature};
  DoubleAttackModifer double_attack_mod{creature};
  DefenceDoubleModifier double_defence_mod{creature};
  CurseActionModifier cursed_creature{creature};
  DoubleAttackModifer double_attack_on_curse{creature};

  root.add(double_attack_mod);
  root.add(double_defence_mod);
  root.add(cursed_creature);
  root.add(double_attack_on_curse);

  root.handle();
}

int main() {
  Creature batman{"Batman", 1, 1};
  std::cout << batman.toString() << std::endl;
  apply_modification(batman);
  std::cout << batman.toString() << std::endl;
}
