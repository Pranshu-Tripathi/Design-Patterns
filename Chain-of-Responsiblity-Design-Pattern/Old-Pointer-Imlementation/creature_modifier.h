#pragma once

#include "creature.h"
class CreatureModifier {
public:
  CreatureModifier(Creature &creature) : creature{creature} {}
  void add(CreatureModifier &cm) {
    if (next) {
      next->add(cm);
    } else {
      next = &cm;
    }
  }
  virtual void handle() {
    if (next) {
      next->handle();
    }
  }

protected:
  Creature &creature;

private:
  CreatureModifier *next{nullptr};
};
