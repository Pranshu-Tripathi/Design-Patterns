#pragma once
#include "game.h"
#include "queries.h"
#include <sstream>
#include <string>

class Creature {
  Game &game;
  int attack, defense;

public:
  std::string name;
  Creature(Game &game, const std::string &name, const int attack,
           const int defense)
      : game{game}, name{name}, attack{attack}, defense{defense} {}

  int GetAttack() const {
    Query q{name, QueryArg::attack, attack};
    game.queries(q);
    return q.result;
  }

  std::string to_string() const {
    std::ostringstream oss;
    oss << "name: " << name << " attack: " << attack << " defense: " << defense;
    return oss.str();
  }
};
