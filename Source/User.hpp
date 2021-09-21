#ifndef USER_HPP
#define USER_HPP

#include "Foundation.hpp"

typedef UInt64 UserIdentifier;

struct Profile {
  String name;
  String address;

  Profile() {
    name = "";
    address = "";
  }
};

struct User {
 public:
  UserIdentifier id;
  String email;
  Profile profile;

  Bool isPasswordMatched(String password) {
    UInt64 hashValue = hashed(password);
    return hashValue == hashedPassword;
  }

  User(String email = "", String password = "", UserIdentifier id = timestamp(), Profile profile = Profile()) {
    this->id = id;
    this->email = email;
    this->profile = profile;
    this->hashedPassword = hashed(password);
  }

 private:
  Int64 hashedPassword;
};

#endif