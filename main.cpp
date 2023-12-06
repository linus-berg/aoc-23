#include <iostream>
#include "utils/common.h"
#define DAY 6
#include "days/Day6/Day6.h"

int main() {
  Common common;
  std::vector<std::string> content = common.GetFileContent(DAY);
  Day6 d;
  int result = d.Run(content);
  return 0;
}
