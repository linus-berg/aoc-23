#include <iostream>
#include "utils/common.h"
#define DAY 3
#include "days/Day3/Day3.h"

int main() {
  Common common;
  std::vector<std::string> content = common.GetFileContent(DAY);
  Day3 d;
  int result = d.Run(content);
  return 0;
}
