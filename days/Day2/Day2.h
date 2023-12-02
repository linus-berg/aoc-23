#ifndef AOC_DAY2_H
#define AOC_DAY2_H
#include "../basic.h"
#include<map>

class Day2 {

public:
  int Run(const std::vector<std::string> &input);

private:
  int Solve(const std::vector<std::string> &input);
  int Solve2(const std::vector<std::string> &input);
};


#endif//AOC_DAY2_H
