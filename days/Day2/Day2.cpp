#include "Day2.h"
#include "Game.h"

int Day2::Run(const std::vector<std::string> &input) {
  int total = this->Solve(input);
  return total;
}

int Day2::Solve(const std::vector<std::string> &input) {
  int total = 0;
  int power = 0;
  for (const std::string &line : input) {
    Game game(line);
    power += game.GetGamePower();
    if (game.IsValidGame()) {
      total += game.GetGameId();
    }
  }
  std::cout << "Part 1: " << total << std::endl;
  std::cout << "Part 2: " << power << std::endl;
  return total;
}

