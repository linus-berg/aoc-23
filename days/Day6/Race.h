#ifndef AOC_DAYS_DAY6_RACE_H_
#define AOC_DAYS_DAY6_RACE_H_

class Race {
 public:
  Race(long max_time, long record) : MAX_TIME_{max_time}, RECORD_{record} {
    WaysToWin();
  }
  [[nodiscard]] long GetWins() const {
    return wins_;
  }
 private:
  const long MAX_TIME_;
  const long RECORD_;
  int wins_ = 0;

  long WaysToWin() {
    long milliseconds_held = 0;
    while (milliseconds_held <= MAX_TIME_) {
      long distance = milliseconds_held * (MAX_TIME_ - milliseconds_held);
      if (distance > RECORD_) {
        wins_++;
      }
      milliseconds_held++;
    }
  }
};

#endif //AOC_DAYS_DAY6_RACE_H_
