#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <string>

// Get current timestampå
// The timestamp return as milliseconds since epoch
uint64_t timestamp();

double random_double(double min, double max);

// returns hash value for the string
template <typename T>
int64_t hashed(T value) {
  std::hash<T> hasher;
  int64_t hashed_value = hasher(value);
  return hashed_value;
}

#endif
