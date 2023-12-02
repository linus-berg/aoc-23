
#ifndef AOC_DAYS_DAY1_DAY1_H_
#define AOC_DAYS_DAY1_DAY1_H_
#include<vector>

const std::vector<const std::string> G_DIGITS = {
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};
class Day1 {

 public:
  int Run(const std::vector<std::string> &input);
 private:
  int Solve(const std::vector<std::string> &input);
  int ConvertNumber(int a, int b);
  int AddNumbers(const std::vector<std::string> &input);
  std::tuple<int, size_t> FindNumber(const std::string &line, bool reverse);
  std::tuple<int, size_t> FindDigit(const std::string &line, bool reverse);
  std::tuple<int, size_t> Find(const std::string &line, bool reverse);
};
#endif//AOC_DAYS_DAY1_DAY1_H_
