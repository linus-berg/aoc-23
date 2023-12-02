#ifndef AOC_DAYS_DAY2_GAMESET_H_
#define AOC_DAYS_DAY2_GAMESET_H_
#include<string>
#include<vector>
#include<map>
#include<iostream>
#include<boost/algorithm/string.hpp>
#include "const.h"

class GameSet {
 public:

  explicit GameSet(const std::string &set) : SET_{set} {
    this->ParseSet();
  }

  int GetColour(const std::string &colour) {
    return colours_[colour];
  }

  bool IsValidSet() {
    for (const std::string &colour : G_COLOURS) {
      if (GetColour(colour) > G_COLOURS_MAX.at(colour)) {
        return false;
      }
    }
    return true;
  }

 private:
  const std::string &SET_;
  std::map<std::string, int> colours_{};

  void ParseSet() {
    std::vector<std::string> colours;
    boost::split(colours, SET_, boost::is_any_of(","));
    for (const std::string &colour : colours) {
      size_t colour_idx = colour.rfind(' ');
      std::string key = colour.substr(colour_idx + 1);
      colours_[key] = stoi(colour.substr(1, colour_idx - 1));
    }
  }

};

#endif//AOC_DAYS_DAY2_GAMESET_H_
