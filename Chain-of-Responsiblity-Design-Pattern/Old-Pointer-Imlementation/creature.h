#pragma once
#include <sstream>
#include <string>

class Creature {
public:
  Creature(const std::string &name, int attack, int defence)
      : name{name}, attack{attack}, defence{defence} {};
  ~Creature() = default;
  std::string toString() const {
    std::ostringstream oss;
    oss << "Creature : " << name << " Attack : " << attack
        << " Defence : " << defence;
    return oss.str();
  }
  void setAttack(int attack) { this->attack = attack; }
  void setDefence(int def) { this->defence = def; }

  int getAttack() const { return attack; }
  int getDefence() const { return defence; }

private:
  std::string name;
  int attack;
  int defence;
};
