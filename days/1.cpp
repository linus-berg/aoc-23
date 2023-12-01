#include<string>
#include<vector>
#include<iostream>
#include "1.h"

int Day1::Run(const std::vector<std::string> &input) {
  this->Solve(input);
}

int Day1::Solve(const std::vector<std::string> &input) {
  int first_idx = 0;
  int total =  this->AddNumbers(input);
  std::cout << total;
  return total;
}
int Day1::ConvertNumber(int a, int b) {
  int f = a * 10;
  return f + b;
}

int Day1::AddNumbers(const std::vector<std::string> &input) {
  int total = 0;

  for(auto it = input.begin(); it < input.end(); ++it) {
    std::tuple<int, size_t> first = this->Find(*it, false);
    int first_number = std::get<0>(first);
    size_t first_idx = std::get<1>(first);
    if (first_number == -1) {
      continue;
    }
    std::tuple<int, size_t> last = this->Find(*it, true);
    int last_number = std::get<0>(last);
    size_t last_idx = std::get<1>(last);

    std::cout << *it << "-> " << first_number << last_number << std::endl;

    /* Add to total */
    if (last_idx == first_idx) {
      total += this->ConvertNumber(first_number, first_number);
    } else {
      total += this->ConvertNumber(first_number, last_number);
    }


  }
  return total;
}
std::vector<std::string> digits = {
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

std::tuple<int, size_t> Day1::Find(const std::string &line, bool reverse) {
  std::tuple<int, size_t> number = FindNumber(line, reverse);
  std::tuple<int, size_t> digit = FindDigit(line, reverse);

  int number_v = std::get<0>(number);
  size_t number_idx = std::get<1>(number);

  int digit_v = std::get<0>(digit);
  size_t digit_idx = std::get<1>(digit);

  if (number_idx == -1 && digit_idx != -1) {
    return digit;
  } else if (digit_v == -1 && number_idx != -1) {
    return number;
  } else if (digit_v != -1 && number_v != -1) {
    if (reverse) {
      if (number_idx > digit_idx) {
        return number;
      } else {
        return digit;
      }
    } else {
      if (number_idx < digit_idx) {
        return number;
      } else {
        return digit;
      }
    }
  }
  return number;
}

std::tuple<int, size_t> Day1::FindDigit(const std::string &line, bool reverse) {
  size_t best = reverse ? 0 : 1000;
  int best_i = -1;
  int i = 0;
  for (auto it = digits.begin(); it != digits.end(); ++it) {
    i++;
    std::string number = *it;
    size_t index = reverse ? line.rfind(number) : line.find(number);
    if (index == std::string::npos) {
      continue;
    }

    if (reverse && index > best) {
      best = index;
      best_i = i;
    } else if (!reverse && index < best) {
      best = index;
      best_i = i;
    }
  }
  return {best_i, best};
}

std::tuple<int, size_t> Day1::FindNumber(const std::string &line, bool reverse) {
  size_t ln = line.length();
  for (int i = 0; i < ln; i++) {
    size_t idx = reverse ? ln - 1 - i : i;
    int j = line[idx] - 48;
    if (j <= 9) {
      return {j, idx};
    }
  }
  return {-1, 0};
}