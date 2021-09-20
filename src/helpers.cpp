// THESE ARE SOME HELPER METHODS
// PLEASE ADD ADDITIONAL FUNCTION AS NEEDED

#include "helpers.hpp"

#include <chrono>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

// Get current timestamp
// The timestamp return as milliseconds since epoch
uint64_t timestamp() {
  using std::chrono::duration_cast;
  using std::chrono::milliseconds;
  using std::chrono::system_clock;
  using std::chrono::time_point;
  time_point<system_clock> current = system_clock::now();
  milliseconds milliseconds_since_epoch = duration_cast<milliseconds>(current.time_since_epoch());
  return milliseconds_since_epoch.count();
}

double random_double(double min, double max) {
  double f = rand() / (RAND_MAX + 1.0);
  return min + f * (max - min);
}