#ifndef APP_HPP
#define APP_HPP

#include <string>
#include <vector>

class Auth;
class Store;

class App {
 private:
  std::vector<std::string> menu_items;

  Auth* auth;

  Store* store;

 public:
  App();

  // This method will ask user for menu input
  // The number selected by the user shouls map properly
  // depends on the order of initialized menu_items
  void run();

  void get_inventory_list();

  void purchase_by_inventory();

  void purchase_by_prescription();

  void get_purchase_detail();
};

#endif