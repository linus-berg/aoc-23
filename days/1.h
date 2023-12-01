
#ifndef AOC_1_H
#define AOC_1_H
#include<vector>

const std::vector<const std::string> DIGITS = {
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
#endif//AOC_1_H
