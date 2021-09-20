#include "auth.hpp"

#include "helpers.hpp"

// Only for admin
const std::string DEFAULT_SUPERUSER_PASSWORD = "superuser1234";
const std::string DEFAULT_SUPERUSER_EMAIL = "superuser@me.com";

User Auth::create_superuser() {
  uint64_t hashed_password = hashed(DEFAULT_SUPERUSER_PASSWORD);
  User user = {
      .id = timestamp(),
      .hashed_password = static_cast<int64_t>(hashed_password),
      .email = DEFAULT_SUPERUSER_EMAIL,
      .name = "Superuser",
      .address = "N/A",
  };
  registed_user_map->set(user.email, user.id);
  user_map->set(user.id, user);
  return user;
}

bool Auth::is_valid_email(std::string email) {
  const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
  return std::regex_match(email, pattern);
}

std::string Auth::password_input(std::string question) {
  std::string password = string_line_input("Please input your password");
  if (password.size() < 8) {
    print_error("Password is too weak. Please use at least 8 characters! \n");
    return password_input(question);
  }

  if (password == "12345678" || password == "qwertyui") {
    print_error("Password is too easy to gueast. Please use non common password! \n");
    return password_input(question);
  }

  for (int i = 0; i < password.size(); i++) {
    if (std::isspace(password[i])) {
      print_error("Password should not contains whitespace. Please try agin! \n");
      return password_input(question);
    }
  }

  return password;
}

// Handle user sign up flow
// Returns signed up user
User Auth::sign_up() {
  std::string email = string_line_input("Please input your email");
  if (is_valid_email(email) != true) {
    print_error("Invalid email format\n");
    return this->sign_up();
  }

  std::string password = password_input("Please input your password");
  int64_t hashed_password = hashed(password);

  std::string name = string_line_input("Please input your name");
  std::string address = string_line_input("Please input your address");
  User user = {
      .id = timestamp(),
      .hashed_password = hashed_password,
      .email = email,
      .name = name,
      .address = address};
  registed_user_map->set(user.email, user.id);
  user_map->set(user.id, user);
  print_success("User with email " + email + " has been created!\n");
  current_authenticated_user_id = user.id;
  return user;
}

// // Handle sign in flow
// // Returns user signed in
User Auth::sign_in() {
  std::string email = string_line_input("Please input your email");
  if (registed_user_map->contains(email) != true) {
    print_error("The user with given email not found\n");
    return this->sign_in();
  }

  std::string password = string_line_input("Please input your password");
  uint64_t user_id = registed_user_map->value(email);
  User user = user_map->value(user_id);
  if (user.hashed_password != hashed(password)) {
    print_error("The password is incorrect!\n");
    return this->current_user();
  }

  current_authenticated_user_id = user_id;
  return user;
}

Auth::Auth() {
  this->menu_items.push_back("Sign Up");
  this->menu_items.push_back("Sign In");
  this->menu_items.push_back("Exit");
  this->registed_user_map = new HashMap<std::string, uint64_t>();
  this->user_map = new HashMap<uint64_t, User>();
  this->current_authenticated_user_id = 0;
  this->create_superuser();
}

void Auth::sign_out() {
  current_authenticated_user_id = 0;
}

// Get current authenticated user
// This will handle with sign up and sign in flow if required
User Auth::current_user() {
  if (this->current_authenticated_user_id != 0) {
    return user_map->value(this->current_authenticated_user_id);
  }

  std::string title = "Welcome!";
  std::string question = "Please input the number associated with the menu";
  int selected = menu_input(title, question, this->menu_items);

  if (selected == 1) {
    return this->sign_up();
  }

  if (selected == 2) {
    return this->sign_in();
  }

  print_error("The number you input doesn't match with available selections");
  return this->current_user();
}