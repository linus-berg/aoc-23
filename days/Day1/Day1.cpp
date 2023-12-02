#include<string>
#include<vector>
#include<iostream>
#include "Day1.h"

int Day1::Run(const std::vector<std::string> &input) {
  this->Solve(input);
}

int Day1::Solve(const std::vector<std::string> &input) {
  int total =  this->AddNumbers(input);
  std::cout << "Answer: " << total;
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
    if (first_number == -1) {
      continue;
    }
    std::tuple<int, size_t> last = this->Find(*it, true);
    int last_number = std::get<0>(last);
    std::cout << *it << "-> " << first_number << last_number << std::endl;
    /* Add to total */
    total += this->ConvertNumber(first_number, last_number);
  }
  return total;
}

std::tuple<int, size_t> Day1::Find(const std::string &line, bool reverse) {
  std::tuple<int, size_t> number = FindNumber(line, reverse);
  std::tuple<int, size_t> digit = FindDigit(line, reverse);

  int number_v = std::get<0>(number);
  size_t number_idx = std::get<1>(number);

  int digit_v = std::get<0>(digit);
  size_t digit_idx = std::get<1>(digit);

  /* No number found, but digit exists */
  if (number_idx == -1 && digit_idx != -1) {
    return digit;
    /* No digit found, but number exists */
  } else if (digit_v == -1 && number_idx != -1) {
    return number;
    /* Found digit and number */
  } else if (digit_v != -1 && number_v != -1) {
    /* If walking in reverse */
    if (reverse) {
      /* If number is in later indexed than digit */
      if (number_idx > digit_idx) {
        return number;
      } else {
        return digit;
      }
      /* If walking forward */
    } else {
      /* If number is earlier indexed than digit */
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
  size_t best = reverse ? 0 : std::string::npos;
  int best_i = -1;
  int i = 0;
  for (const auto & number : G_DIGITS) {
    i++;
    size_t index = reverse ? line.rfind(number) : line.find(number);
    if (index == std::string::npos) {
      continue;
    }

    if (reverse && index > best || !reverse && index < best) {
      best = index;
      best_i = i;
    }
  }
  return {best_i, best};
}

std::tuple<int, size_t> Day1::FindNumber(const std::string &line, bool reverse) {
  size_t line_length = line.length();
  for (int i = 0; i < line_length; i++) {
    size_t idx = reverse ? line_length - 1 - i : i;
    int j = line[idx] - 48;
    if (j <= 9) {
      return {j, idx};
    }
  }
  return {-1, 0};
}