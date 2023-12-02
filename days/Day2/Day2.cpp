#include "Day2.h"
#include "Game.h"

int Day2::Run(const std::vector<std::string> &input) {
  int total = this->Solve(input);
  int total2 = this->Solve2(input);
  std::cout << "Part 1: " << total << std::endl;
  std::cout << "Part 2: " << total2 << std::endl;
  return total;
}

int Day2::Solve(const std::vector<std::string> &input) {
  int total = 0;
  for (const std::string &line : input) {
    Game game(line);
    if (game.IsValidGame()) {
      total += game.GetGameId();
    }
  }
  return total;
}

int Day2::Solve2(const std::vector<std::string> &input) {
  int total = 0;
  for (const std::string &line : input) {
    Game game(line);
    total += game.GetGamePower();
  }
  return total;
}
