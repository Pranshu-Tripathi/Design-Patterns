#include "game.h"
#include <iostream>

Game::Game(const int players, const int max_score)
    : m_players(players), m_max_score(max_score) {}

std::string Game::start_game() {
  initialize_players();
  std::cout << "+++++++++++++++++++++ START +++++++++++++++++++++++++"
            << std::endl;
  int prev_player = -1;
  while (no_winner()) {
    auto player = prev_player;
    while (player == prev_player)
      player = get_player_turn();
    auto player_score = get_player_score();
    std::cout << "Player [" << player << "] :: " << player_score << std::endl;
    add_player_score(player, player_score);
    prev_player = player;
  }
  std::cout << "+++++++++++++++++++++ END +++++++++++++++++++++++++"
            << std::endl;
  return winner_player();
}

int Game::get_max_score() { return m_max_score; }

int Game::get_players() { return m_players; }
