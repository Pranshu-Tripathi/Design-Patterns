#pragma once

#include "creature.h"
#include "game.h"
#include "queries.h"
#include <boost/signals2.hpp>
#include <iostream>
class CreatureModifier {
  Game &game;
  Creature &creature;

public:
  CreatureModifier(Game &game, Creature &creature)
      : game{game}, creature{creature} {}
  virtual ~CreatureModifier() = default;
};

class DoubleAttackModifer : public CreatureModifier {
  boost::signals2::connection conn;

public:
  DoubleAttackModifer(Game &game, Creature &creature)
      : CreatureModifier(game, creature) {
    // whenever someone wants creatures attack we simply double the value.
    conn = game.queries.connect([&](Query &q) {
      if (q.creature_name == creature.name && q.argument == QueryArg::attack) {
        std::cout << "entering connection" << std::endl;
        q.result *= 2;
      }
    });
  }
  ~DoubleAttackModifer() { conn.disconnect(); }
};
