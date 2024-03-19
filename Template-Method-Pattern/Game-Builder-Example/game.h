#pragma once
#include <string>
class Game {
  int m_players;
  int m_max_score;

public:
  Game(const int players, const int max_score);

  std::string start_game(); /* Template Method */
  virtual int get_player_turn() = 0;
  virtual int get_player_score() = 0;
  virtual bool no_winner() = 0;
  virtual void add_player_score(const int player, const int score) = 0;
  virtual std::string winner_player() = 0;
  virtual void initialize_players() = 0;
  int get_max_score();
  int get_players();
};
