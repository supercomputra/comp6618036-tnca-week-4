#ifndef FOUNDATION_HPP
#define FOUNDATION_HPP

#include <string>
#include <unordered_map>
#include <vector>

#include "HashMap.hpp"

// Aliasing to improve code readabilty
typedef std::string String;
typedef bool Bool;
typedef double Double;
typedef long long Int64;
typedef uint64_t UInt64;
typedef int Int;

template <typename T>
using Vector = std::vector<T>;

// Get current timestampå
// The timestamp return as milliseconds since epoch
UInt64 timestamp();

// Generate random with bounds
Double randomDouble(Double min, Double max);

// returns hash value for any given value
template <typename T>
Int64 hashed(T value) {
  std::hash<T> hasher;
  Int64 hashedValue = hasher(value);
  return hashedValue;
}

// print some string to the out stream
// add end of line at the end
void print(String s);

// print some string to the out stream
// this will print with red foreground in the terminal
void printError(String s);

// print some string to the out stream
// this will print with green foreground in the terminal
void printSuccess(String s);

// print some string to the out stream
// this will print with green foreground in the terminal
String formatCurrency(String currency, Double amount, int decimalPlaces = 2);

// Get user input and print some given string
// return user input value
String readLineInput(String s);

// Get user input and print some given string
// return user input value
Bool readBoolInput(String s);

// Get user input and print some given string
// return user input value as integer
Int readNumberInput(String s);

// Get user input and print some given string
// return user input value as integer
UInt64 readLongNumberInput(String s);

// Get user input for given menu
UInt64 readMenuInput(String title, String question, Vector<String> selections);

#endif