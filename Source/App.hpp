#ifndef APP_HPP
#define APP_HPP

#include "Auth.hpp"
#include "Foundation.hpp"
#include "Store.hpp"

class App {
 private:
  Vector<String> menuItems;

  Auth* auth;

  Store* store;

 public:
  App();

  ~App();

  void run();

  void getInventoryList();

  void purchaseByInventory();

  void puchaseByPrescription();

  void getPurchaseDetail();
};

#endif