#ifndef USER_HPP
#define USER_HPP

#include <string>

struct User {
  uint64_t id;
  int64_t hashed_password;
  std::string email;
  std::string name;
  std::string address;
};

#endif