#ifndef AOC_GAME_H
#define AOC_GAME_H
#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
#include "GameSet.h"
#include "const.h"
class Game {
 public:
  explicit Game(const std::string &input) {
    this->ParseGame(input);
  }
  [[nodiscard]] int GetGameId() const {
    return this->game_id;
  }

  [[nodiscard]] bool IsValidGame() const {
    return !this->invalid;
  }

  [[nodiscard]] int GetGamePower() const {
    return max_red * max_green * max_blue;
  }

 private:
  int game_id = 0;
  bool invalid = false;
  int max_red = 0;
  int max_green = 0;
  int max_blue = 0;

  void ParseGame(const std::string &input) {
    size_t game_id_idx = this->SetGameId(input);
    std::string game_play = input.substr(game_id_idx);
    std::vector<std::string> result;
    boost::split(result, game_play, boost::is_any_of(";"));
    for (const std::string &set : result) {
      GameSet game_set(set);
      int set_red = game_set.GetColour("red");
      if (max_red < set_red) {
        max_red = set_red;
      }
      int set_green = game_set.GetColour("green");
      if (max_green < set_green) {
        max_green = set_green;
      }
      int set_blue = game_set.GetColour("blue");
      if (max_blue < set_blue) {
        max_blue = set_blue;
      }

      /* Part 1 */
      if (!game_set.IsValidSet()) {
        invalid = true;
      }
    }
  }

  size_t SetGameId(const std::string &input) {
    size_t game_id_idx = input.find(':');
    std::string game_id_str = input.substr(0, game_id_idx);
    this->game_id = stoi(game_id_str.substr(game_id_str.find(' ')));
    return game_id_idx + 1;
  }
};
#endif//AOC_GAME_H
