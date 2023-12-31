#ifndef AOC_DAYS_DAY3_GRID_H_
#define AOC_DAYS_DAY3_GRID_H_
#include "base.h"
#include <cmath>
#include "GridNumber.h"
#include<sstream>
#include<set>
class Grid {
 public:
  explicit Grid(const std::vector<std::string> &input) : INPUT_{input} {
    CreateGrid();
    FindPointsOfInterest();
    PrintAllValidNumbers();
  }

  void PrintAllValidNumbers() {
    int total = 0;
    for (std::pair<const std::string, const std::shared_ptr<GridNumber> &>
          number : numbers_) {
      if (number.second->Seen()) {
        continue;
      }
      if (number.second->IsValid()) {
        number.second->SetSeen();
        total += number.second->GetNumber();
      }
    }
    std::cout << "Total: " << total << std::endl;
  }
 private:
  const std::vector<std::string> &INPUT_;
  std::vector<std::vector<char>> grid_{};
  std::map<std::string, std::shared_ptr<GridNumber>> numbers_{};
  void CreateGrid() {
    int y = 0;
    for (const std::string &line : INPUT_) {
      size_t l = line.length();
      grid_.emplace_back();
      for (int i = 0; i < l; i++) {
        if (isdigit(line[i])) {
          std::stringstream number_str;
          std::vector<int> occupies{};
          do {
            number_str << line[i];
            occupies.push_back(i);
            grid_[y].push_back(line[i]);
            i++;
          } while (i < l && line[i] != '.' && isdigit(line[i]));
          std::shared_ptr<GridNumber>
              number = std::make_shared<GridNumber>(number_str.str());
          for (int occupied : occupies) {
            numbers_[GetNumber(occupied, y)] = number;
          }
        }
        if (i < l) {
          grid_[y].push_back(line[i]);
        }
      }
      y++;
    }
  }

  void FindPointsOfInterest() {
    int total = 0;
    for (int y = 0; y < grid_.size(); y++) {
      const std::vector<char> &x_v = grid_[y];
      for (int x = 0; x < x_v.size(); x++) {
        char ch = x_v[x];
        if (!isdigit(ch) && ch != '.') {
          total += FindSurroundingNumbers(x, y);
        }
      }
    }
    std::cout << "Gear ratio: " << total << std::endl;
  }

  int FindSurroundingNumbers(int x, int y) {
    std::map<std::string, std::shared_ptr<GridNumber>> found{};
    std::vector<std::pair<int, int>> pairs{};

    for (int adj = 0; adj < 4; adj++) {
      int sin = (int) std::sin(M_PI / 2 + M_PI * std::floor(adj / 2));
      int cos = (int) std::cos(M_PI * adj);
      int corner_x = x + cos;
      int corner_y = y + sin;
      /* Corner */
      pairs.emplace_back(corner_x, corner_y);
      /* Center point */
      pairs.emplace_back(sin != cos ? corner_x : x, sin != cos ? y : corner_y);

      for (const std::pair<int, int> &pair : pairs) {
        int x_p = pair.first;
        int y_p = pair.second;
        char ch = grid_[y_p][x_p];
        if (isdigit(ch)) {
          std::shared_ptr<GridNumber>
              ptr = GetFullNumber(x_p, y_p);
          ptr->SetIsValid();
          if (!(ptr->Touched())) {
            found[GetNumber(x_p, y_p)] = ptr;
            ptr->SetTouched();
          }
        }
      }
    }

    if (grid_[y][x] == '*' && found.size() == 2) {
      auto it = found.begin();
      std::shared_ptr<GridNumber> a = it->second;
      std::shared_ptr<GridNumber> b = (++it)->second;
      int total = a->GetNumber() * b->GetNumber();
      return total;
    }
    return 0;
  }

  std::shared_ptr<GridNumber> GetFullNumber(int x, int y) {
    std::string y_x = GetNumber(x, y);
    return numbers_.at(y_x);
  }

  static std::string GetNumber(int x, int y) {
    return std::to_string(y) + '-' + std::to_string(x);
  }
};

#endif //AOC_DAYS_DAY3_GRID_H_
