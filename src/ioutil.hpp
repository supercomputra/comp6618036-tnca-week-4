#ifndef IOUTIL_HPP
#define IOUTIL_HPP

#include <string>
#include <vector>

// print some string to the out stream
// add end of line at the end
void print(std::string s);

// print some string to the out stream
// this will print with red foreground in the terminal
void print_error(std::string s);

// print some string to the out stream
// this will print with green foreground in the terminal
void print_success(std::string s);

// Get user input and print some given string
// return user input value
std::string string_line_input(std::string s);

// Get user input and print some given string
// return user input value
std::string string_input(std::string s);

// Get user input and print some given string
// return user input value as integer
int number_input(std::string s);

// Get user input for given menu
int menu_input(std::string title, std::string question, std::vector<std::string> selections);

#endif