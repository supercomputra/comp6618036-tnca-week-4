#include "Auth.hpp"

#include <regex>

#include "Foundation.hpp"

// Only for admin
const String DEFAULT_SUPERUSER_PASSWORD = "superuser1234";
const String DEFAULT_SUPERUSER_EMAIL = "superuser@me.com";
const String DEFAULT_SUPERUSER_NAME = "Superuser";
const String DEFAULT_SUPERUSER_ADDRESS = "0x0000001";

User Auth::createSuperuser() {
  User user = User(DEFAULT_SUPERUSER_EMAIL, DEFAULT_SUPERUSER_PASSWORD);
  user.profile.name = DEFAULT_SUPERUSER_NAME;
  user.profile.address = DEFAULT_SUPERUSER_ADDRESS;
  registedUserIdentifierMap.set(user.email, user.id);
  registedUserMap.set(user.id, user);
  return user;
}

bool Auth::isValidEmailFormat(String email) {
  const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
  return std::regex_match(email, pattern);
}

String Auth::getPasswordInput(String question) {
  String password = readLineInput("Please input your password");
  // Shouldn't contains 8 size
  if (password.size() < 8) {
    printError("Password is too weak. Please use at least 8 characters! \n");
    return getPasswordInput(question);
  }

  // Shouldn't contains weak password
  if (password == "12345678" || password == "qwertyui") {
    printError("Password is too easy to gueast. Please use non common password! \n");
    return getPasswordInput(question);
  }

  // Shouldn't contains whitespace
  for (int i = 0; i < password.size(); i++) {
    if (std::isspace(password[i])) {
      printError("Password should not contains whitespace. Please try agin! \n");
      return getPasswordInput(question);
    }
  }

  return password;
}

// Handle user sign up flow
// Returns signed up user
User Auth::signUp() {
  String email = readLineInput("Please input your email");
  if (isValidEmailFormat(email) != true) {
    printError("Invalid email format\n");
    return signUp();
  }

  // Create usr
  String password = getPasswordInput("Please input your password");
  User user = User(email, password);
  user.profile.name = readLineInput("Please input your name");
  user.profile.address = readLineInput("Please input your address");

  registedUserIdentifierMap.set(user.email, user.id);
  registedUserMap.set(user.id, user);
  printSuccess("User with email " + email + " has been created!\n");
  currentUserIdentifier = user.id;
  return user;
}

// // Handle sign in flow
// // Returns user signed in
User Auth::signIn() {
  // Email validation
  String email = readLineInput("Email");
  if (registedUserIdentifierMap.contains(email) != true) {
    printError("The user with given email not found\n");
    return signIn();
  }

  // Password validation
  String password = readLineInput("Password");
  UserIdentifier id = registedUserIdentifierMap.get(email);
  User user = registedUserMap.get(id);
  if (!user.isPasswordMatched(password)) {
    printError("The password is incorrect!\n");
    return currentUser();
  }

  currentUserIdentifier = id;
  return user;
}

Auth::Auth() {
  menuItems.push_back("Sign In");
  menuItems.push_back("Sign Up");
  menuItems.push_back("Exit");
  currentUserIdentifier = 0;
  createSuperuser();
}

Auth::~Auth() {}

void Auth::signOut() {
  currentUserIdentifier = 0;
}

// Get current authenticated user
// This will handle with sign up and sign in flow if required
User Auth::currentUser() {
  if (currentUserIdentifier != 0) {
    return registedUserMap.get(currentUserIdentifier);
  }

  String title = "Welcome!";
  String question = "Please input the number associated with the menu";
  int selected = readMenuInput(title, question, menuItems);

  if (selected == 1) {
    return signIn();
  }

  if (selected == 2) {
    return signUp();
  }

  printError("The number you input doesn't match with available selections");
  return currentUser();
}