#include <unordered_map>
#include <vector>

#include "helpers.cc"
#include "model/user.cc"

class Authentication {
 private:
  typedef std::unordered_map<std::string, std::string> user_detail_map;

  std::vector<std::string> menu_items;

  std::unordered_map<std::string, uint64_t> registed_user_map;

  std::unordered_map<uint64_t, User> user_map;

  std::uint64_t current_authenticated_user_id;

  User sign_up() {
    std::string name = string_input("Please input your name");
    std::string address = string_input("Please input your address");
    std::string email = string_input("Please input your email");
    std::string password = string_input("Please input your password");
    int64_t hashed_password = hash(password);
    User user = {
        .id = current_timestamp(),
        .hashed_password = hashed_password,
        .email = email,
        .name = name,
        .address = address};
    this->registed_user_map[user.email] = user.id;
    this->user_map[user.id] = user;
    print_success("User with email " + email + " has been created!\n");
    current_authenticated_user_id = user.id;
    return user;
  }

  User sign_in() {
    std::string email = string_input("Please input your email");
    uint64_t user_id = this->registed_user_map[email];
    if (user_id == 0) {
      print_error("The user with given email not found\n");
      return this->sign_in();
    }

    std::string password = string_input("Please input your password");
    User user = this->user_map[user_id];
    if (user.hashed_password != hash(password)) {
      print_error("The password is incorrect!\n");
      return this->current_user();
    }

    current_authenticated_user_id = user_id;
    return user;
  }

 public:
  Authentication() {
    this->menu_items.push_back("Sign Up");
    this->menu_items.push_back("Sign In");
    this->menu_items.push_back("Exit");
  }

  void sign_out() {
    current_authenticated_user_id = 0;
  }

  User current_user() {
    if (this->current_authenticated_user_id != 0) {
      printf("%lld", this->current_authenticated_user_id);
      return this->user_map[this->current_authenticated_user_id];
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
    return current_user();
  }
};