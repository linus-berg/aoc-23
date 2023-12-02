#ifndef AOC_GAMESET_H
#define AOC_GAMESET_H
#include<string>
#include<vector>
#include<map>
#include<iostream>
#include<boost/algorithm/string.hpp>
#include "const.h"

class GameSet {
 public:

  explicit GameSet(const std::string &set) {
    this->ParseSet(set);
  }

  int GetColour(const std::string &colour) {
    return colours_[colour];
  }

  bool IsValidSet() {
    return GetColour("red") <= MAX_RED && GetColour("green") <= MAX_GREEN
        && GetColour("blue") <= MAX_BLUE;
  }

 private:
  std::map<std::string, int> colours_{};

  void ParseSet(const std::string &set) {
    std::vector<std::string> colours;
    boost::split(colours, set, boost::is_any_of(","));

    for (const std::string &colour : colours) {
      size_t colour_idx = colour.rfind(' ');
      std::string key = colour.substr(colour_idx + 1);
      int value = stoi(colour.substr(1, colour_idx - 1));
      colours_[key] = value;
    }
  }

};

#endif//AOC_GAMESET_H
