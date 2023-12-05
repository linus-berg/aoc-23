#include <iostream>
#include "utils/common.h"
#define DAY 4
#include "days/Day4/Day4.h"

int main() {
  Common common;
  std::vector<std::string> content = common.GetFileContent(DAY);
  Day4 d;
  int result = d.Run(content);
  return 0;
}
