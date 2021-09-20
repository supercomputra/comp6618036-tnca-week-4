#ifndef AUTH_HPP
#define AUTH_HPP

#include <regex>
#include <vector>

#include "hashmap.hpp"
#include "helpers.hpp"
#include "ioutil.hpp"
#include "user.hpp"

class Auth {
 private:
  // Menu items for authentication
  std::vector<std::string> menu_items;

  // Map user email to the user id
  HashMap<std::string, uint64_t>* registed_user_map;

  // Map user id to the user detail
  HashMap<uint64_t, User>* user_map;

  // Returns authenticated user id
  std::uint64_t current_authenticated_user_id;

  // Create super user for admin
  User create_superuser();

  // Handle user sign up flow
  // Returns signed up user
  User sign_up();

  // Handle sign in flow
  // Returns user signed in
  User sign_in();

  // Check whether the given email i in valid format
  static bool is_valid_email(std::string email);

  // Check whether the given email i in valid format
  static std::string password_input(std::string question);

 public:
  Auth();
  User current_user();
  void sign_out();
};

#endif