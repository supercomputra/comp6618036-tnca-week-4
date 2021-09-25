#include "Foundation.hpp"

#include <chrono>
#include <iostream>
#include <sstream>

// print some string to the out stream
// add end of line at the end
void print(String s) {
  std::cout << s << std::endl;
}

// print some string to the out stream
// this will print with red foreground in the terminal
void printError(String s) {
  printf("\033[0;31;49m%s\033[0m", s.c_str());
}

// print some string to the out stream
// this will print with green foreground in the terminal
void printSuccess(String s) {
  printf("\033[0;32;49m%s\033[0m", s.c_str());
}

// Generate string representation from double value with 2 decimal place
String formatCurrency(String currency, Double amount, int decimalPlaces) {
  std::ostringstream stringStream;
  stringStream.precision(decimalPlaces);
  stringStream << std::fixed << amount;
  return currency + stringStream.str();
}

// Get user input and print some given string
// return user input value
String readLineInput(String s) {
  if (s.empty() == false) {
    std::cout << s << ": ";
  };

  String value;
  getline(std::cin, value);
  std::cin.clear();
  return value;
}

// Get user input and print some given string
// return user input value
bool readBoolInput(String s) {
  String value = readLineInput(s + " Y/N ");

  if (value == "y" || value == "Y") {
    return true;
  }

  if (value == "n" || value == "N") {
    return false;
  }

  return readBoolInput(s);
}

// Get user input and print some given string
// return user input value as integer
int readNumberInput(String s) {
  String input = readLineInput(s);
  try {
    int number = std::stoi(input);
    return number;
  } catch (std::invalid_argument& e) {
    printError("Invalid number\n");
    return readNumberInput(s);
  } catch (std::out_of_range& e) {
    printError("The number you input is out of range.\n");
    return readNumberInput(s);
  } catch (...) {
    printError("Something went wrong\n");
    return readNumberInput(s);
  }
}

// Get user input and print some given string
// return user input value as integer
UInt64 readLongNumberInput(String s) {
  String input = readLineInput(s);
  try {
    UInt64 number = std::stoull(input);
    return number;
  } catch (std::invalid_argument& e) {
    printError("Invalid number\n");
    return readNumberInput(s);
  } catch (std::out_of_range& e) {
    printError("The number you input is out of range.\n");
    return readNumberInput(s);
  } catch (...) {
    printError("Something went wrong\n");
    return readNumberInput(s);
  }
}

// Get user input for given menu
UInt64 readMenuInput(String title, String question, Vector<String> selections) {
  String dialog = "============MENU============\n";
  if (!title.empty()) {
    dialog.append(title + "\n");
  }

  // Each selection will be printed with format <number>. <selection>\n
  for (int i = 0; i < selections.size(); i++) {
    dialog.append(std::to_string(i + 1) + ". " + selections[i] + "\n");
  }

  dialog.append("============================\n");
  dialog.append(question);
  UInt64 selected = readNumberInput(dialog);
  if ((selected > std::numeric_limits<UInt64>::max()) || (selected < std::numeric_limits<UInt64>::min())) {
    printError("The number is out of range. Please try again!\n");
  }

  // Validation
  // Self recall if invalid
  if ((selected <= 0) || (selected > selections.size())) {
    print("Invalid menu selection. Please try again!");
    return readMenuInput(title, question, selections);
  }

  return (UInt64)selected;
}

// Get current timestamp
// The timestamp return as milliseconds since epoch
UInt64 timestamp() {
  using std::chrono::duration_cast;
  using std::chrono::milliseconds;
  using std::chrono::system_clock;
  using std::chrono::time_point;
  time_point<system_clock> current = system_clock::now();
  milliseconds milliseconds_since_epoch = duration_cast<milliseconds>(current.time_since_epoch());
  return milliseconds_since_epoch.count();
}

Double randomDouble(Double min, Double max) {
  Double f = rand() / (RAND_MAX + 1.0);
  return min + f * (max - min);
}