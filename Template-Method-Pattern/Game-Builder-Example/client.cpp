#include "random_game.h"
#include <initializer_list>
#include <iostream>

int main() {
  std::initializer_list<std::pair<int, std::string>> players = {
      std::make_pair(0, "Pranshu"), std::make_pair(1, "Anurag"),
      std::make_pair(2, "Priyansh"), std::make_pair(3, "Divyendra")};

  RandomGame rand(players);

  auto winner = rand.start_game();
  std::cout << "Winner is : " << winner << std::endl;
}
