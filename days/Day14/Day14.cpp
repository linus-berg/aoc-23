#include "Day14.h"

void Day14::Run(const std::vector<std::string> &input) {
  std::map<int, int> max{};
  int load_max = 100;
  int load_sum = 0;

  int y = 0;
  for (const std::string &row : input) {
    int x = 0;
    for (const char column : row) {
      if (column == '#') {
        /* max y so far */
        max[x] = y;
      } else if (y == 0) {
        max[x] = -1;
      }
      if (column == 'O') {
        load_sum += load_max - (max[x] + 1);
        max[x] = max[x] + 1;
      }
      x++;
    }
    y++;
  }
  std::cout << load_sum << std::endl;
}

