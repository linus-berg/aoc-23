#ifndef AOC_DAYS_DAY4_CARD_H_
#define AOC_DAYS_DAY4_CARD_H_
#include "base.h"
#include <boost/algorithm/string.hpp>
#include <cmath>
class Card {
 public:
  explicit Card(const std::string &input) : INPUT_{input} {
    ParseCard();
  }

  [[nodiscard]] int GetScore() const {
    return (wins_ - 1) == -1 ? 0 : static_cast<int>(std::pow(2, wins_ - 1));
  }
 private:
  const std::string &INPUT_;
  std::map<int, bool> winning_numbers_;
  std::vector<int> running_numbers_;
  int wins_ = 0;

  void ParseCard() {
    std::string input = INPUT_.substr(10);
    std::vector<std::string> sets;
    boost::split(sets, input, boost::is_any_of("|"));

    std::vector<std::string> running_numbers;
    std::vector<std::string> winning_numbers;

    boost::split(winning_numbers, sets[0], boost::is_any_of(" "));
    boost::split(running_numbers, sets[1], boost::is_any_of(" "));

    for (const std::string &number : winning_numbers) {
      if (!number.empty()) {
        winning_numbers_[std::stoi(number)] = true;
      }
    }

    for (const std::string &number_str : running_numbers) {
      if (!number_str.empty()) {
        int number = std::stoi(number_str);
        running_numbers_.push_back(number);
        if (winning_numbers_.find(number) != winning_numbers_.end()) {
          wins_++;
        }
      }
    }
  }

};

#endif //AOC_DAYS_DAY4_CARD_H_
