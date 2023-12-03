#ifndef AOC_DAYS_DAY3_GRIDNUMBER_H_
#define AOC_DAYS_DAY3_GRIDNUMBER_H_
#include "base.h"
class GridNumber {
 public:
  GridNumber(const std::string &number) {
    number_ = stoi(number);
  }
  bool IsValid() {
    return valid_;
  }

  bool Seen() {
    return seen_;
  }

  int SetSeen() {
    seen_ = true;
  }
  bool Touched() {
    return touched_;
  }

  int SetTouched() {
    touched_ = true;
  }

  int GetNumber() {
    return number_;
  }

  void SetIsValid() {
    valid_ = true;
  }

 private:
  int number_;
  bool seen_ = false;
  bool touched_ = false;
  bool valid_ = false;
};

#endif //AOC_DAYS_DAY3_GRIDNUMBER_H_
