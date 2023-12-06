#include "Day6.h"
#include "Race.h"

void Day6::Run(const std::vector<std::string> &input) {
  std::vector<Race> races = {
      Race(40929790, 215106415051100),
  };

  long record = 1;
  for (const Race &race : races) {
    record = record * race.GetWins();
  }
  std::cout << record << std::endl;
}

