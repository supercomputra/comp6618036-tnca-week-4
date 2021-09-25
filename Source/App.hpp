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

  int run();

  /**
   * Purchase by list
   */
  void getInventoryList();

  /**
   * Purchase by inventory
   */
  void purchaseByInventory();

  /**
   * Purchase by prescription 
   */
  void puchaseByPrescription();

  /**
   * Purchase detail
   */
  void getPurchaseDetail();
};

#endif