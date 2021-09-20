#include "ioutil.hpp"

#include <iostream>
#include <string>
#include <vector>

// print some string to the out stream
// add end of line at the end
void print(std::string s) {
  std::cout << s << std::endl;
}

// print some string to the out stream
// this will print with red foreground in the terminal
void print_error(std::string s) {
  printf("\033[0;31;49m%s\033[0m", s.c_str());
}

// print some string to the out stream
// this will print with green foreground in the terminal
void print_success(std::string s) {
  printf("\033[0;32;49m%s\033[0m", s.c_str());
}

// Get user input and print some given string
// return user input value
std::string string_line_input(std::string s) {
  if (s.empty() == false) {
    std::cout << s << ": ";
  };

  std::string value;
  getline(std::cin, value);
  return value;
}

// Get user input and print some given string
// return user input value
std::string string_input(std::string s) {
  if (s.empty() == false) {
    std::cout << s << ": ";
  };

  std::string value;
  std::cin >> value;
  return value;
}

// Get user input and print some given string
// return user input value as integer
int number_input(std::string s) {
  std::string input = string_line_input(s);
  try {
    int number = std::stoi(input);
    return number;
  } catch (std::invalid_argument& e) {
    print_error("Invalid number\n");
    return number_input(s);
  } catch (std::out_of_range& e) {
    print_error("The number you input is out of range.\n");
    return number_input(s);
  } catch (...) {
    print_error("Something went wrong\n");
    return number_input(s);
  }
}

// Get user input for given menu
int menu_input(std::string title, std::string question, std::vector<std::string> selections) {
  std::string dialog = "============MENU============\n";
  dialog.append(title + "\n");

  // Each selection will be printed with format <number>. <selection>\n
  for (int i = 0; i < selections.size(); i++) {
    dialog.append(std::to_string(i + 1) + ". " + selections[i] + "\n");
  }

  dialog.append("============================\n");
  dialog.append(question);
  int selected_number = number_input(dialog);

  // Validation
  // Self recall if invalid
  if ((selected_number <= 0) || (selected_number > selections.size())) {
    print("Invalid menu selection. Please try again!");
    return menu_input(title, question, selections);
  }

  return selected_number;
}