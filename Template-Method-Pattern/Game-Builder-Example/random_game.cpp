#include "random_game.h"
#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <random>

static int random_generator(const int lower = 0, const int upper = 22) {
  std::random_device rd;
  std::mt19937 gen(rd());

  std::uniform_int_distribution<int> distribution(lower,
                                                  std::max(lower, upper - 1));
  auto random_numer = distribution(gen);
  return random_numer;
}

RandomGame::RandomGame(
    std::initializer_list<std::pair<int, std::string>> &players)
    : Game(players.size(), random_generator(1)), m_players(players) {
  m_scores.resize(players.size(), -1);
}

int RandomGame::get_player_turn() {
  auto player = random_generator(0, get_players());
  return player;
}

int RandomGame::get_player_score() {
  auto score = random_generator(1, get_max_score());
  return score;
}

bool RandomGame::no_winner() {

  const auto player_reached_max = [this](const int score) {
    return score == get_max_score();
  };
  auto player =
      std::find_if(m_scores.begin(), m_scores.end(), player_reached_max);
  return player == std::end(m_scores);
}

void RandomGame::add_player_score(const int player, const int score) {
  auto current_score = m_scores[player];
  auto new_score = std::min(get_max_score(), current_score + score);
  m_scores[player] = new_score;
}

std::string RandomGame::winner_player() {
  std::string name;
  const auto check_winner = [&name,
                             this](const std::pair<int, std::string> &player) {
    if (auto winner = (m_scores[player.first] == get_max_score()); winner) {
      name = player.second;
    }
  };
  std::for_each(m_players.begin(), m_players.end(), check_winner);
  return name;
}

void RandomGame::initialize_players() {
  m_scores.resize(get_players(), -1);
  std::fill_n(m_scores.begin(), m_scores.size(), 0);
  std::cout << "Game Max Score : " << get_max_score() << std::endl;
  std::cout << "Game Players : " << get_players() << std::endl;
}
