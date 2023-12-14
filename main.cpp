#include <iostream>
#include "utils/common.h"
#define DAY 14
#include "days/Day14/Day14.h"

int main() {
  Common common;
  std::vector<std::string> content = common.GetFileContent(DAY);
  Day14 d;
  d.Run(content);
  return 0;
}
