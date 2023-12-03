#ifndef AOC_DAYS_DAY2_GAME_H_
#define AOC_DAYS_DAY2_GAME_H_
#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>
#include <map>
#include "GameSet.h"
#include "const.h"
class Game {
 public:
  explicit Game(const std::string &input) : INPUT_{input} {
    this->ParseGame();
  }
  [[nodiscard]] int GetGameId() const {
    return this->game_id_;
  }

  [[nodiscard]] bool IsValidGame() const {
    return !this->invalid_;
  }

  [[nodiscard]] int GetGamePower() const {
    return max_.at("red") * max_.at("green") * max_.at("blue");
  }

 private:
  /* Original INPUT_ */
  const std::string &INPUT_;

  /* Game id */
  int game_id_ = 0;
  size_t game_id_idx_ = 0;

  /* State */
  bool invalid_ = false;
  std::map<std::string, int> max_{};

  void ParseGame() {
    this->SetGameId();
    std::string game_play = INPUT_.substr(game_id_idx_ + 1);
    std::vector<std::string> result;
    boost::split(result, game_play, boost::is_any_of(";"));
    for (const std::string &set : result) {
      GameSet game_set(set);
      /* Update max_ values */
      for (const std::string &colour : G_COLOURS) {
        int colour_value = game_set.GetColour(colour);
        int colour_max = max_[colour];
        if (colour_max < colour_value) {
          max_[colour] = colour_value;
        }
      }
      /* Part 1 */
      if (!game_set.IsValidSet()) {
        invalid_ = true;
      }
    }
  }

  void SetGameId() {
    size_t idx = INPUT_.find(':');
    this->game_id_ = stoi(INPUT_.substr(5, idx - 5));
    this->game_id_idx_ = idx;
  }
};
#endif//AOC_DAYS_DAY2_GAME_H_
