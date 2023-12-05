#include "Day4.h"
#include "Card.h"

int Day4::Run(const std::vector<std::string> &input) {
  int total = 0;
  for (const std::string &line : input) {
    Card card{line};
    total += card.GetScore();
  }
  std::cout << "Total: " << total << std::endl;
}
