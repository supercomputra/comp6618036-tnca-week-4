#ifndef AUTH_HPP
#define AUTH_HPP

#include "Foundation.hpp"
#include "User.hpp"

typedef UInt64 UserIdentifier;
typedef String UserEmail;

class Auth {
 private:
  // Menu items for authentication
  Vector<String> menuItems;

  // Map user email to the user id
  HashMap<UserEmail, UserIdentifier>* registedUserIdentifierMap;

  // Map user id to the user detail
  HashMap<UserIdentifier, User>* registedUserMap;

  // Returns authenticated user id
  UserIdentifier currentUserIdentifier;

  // Create super user for admin
  User createSuperuser();

  // Handle user sign up flow
  // Returns signed up user
  User signUp();

  // Handle sign in flow
  // Returns user signed in
  User signIn();

  // Check whether the given email i in valid format
  static Bool isValidEmailFormat(String email);

  // Check whether the given email i in valid format
  static String getPasswordInput(String question);

 public:
  /**
  * Constructor
  */
  Auth();

  /**
  * Desctructor
  */
  ~Auth();

  /**
   * Get current authenticated user
   * @return current authenticated user
   */
  User currentUser();

  /**
   * Signing out the current authenticated user
   */
  void signOut();
};

#endif