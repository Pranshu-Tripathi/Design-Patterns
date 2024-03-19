#pragma once

#include "game.h"
#include <initializer_list>
#include <string>
#include <vector>
class RandomGame : public Game {
  std::vector<std::pair<int, std::string>> m_players;
  std::vector<int> m_scores;

public:
  RandomGame(std::initializer_list<std::pair<int, std::string>> &players);
  int get_player_turn() override;
  int get_player_score() override;
  bool no_winner() override;
  void add_player_score(const int player, const int score) override;
  std::string winner_player() override;
  void initialize_players() override;
};
