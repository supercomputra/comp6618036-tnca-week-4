#ifndef STORE_HPP
#define STORE_HPP

#include "Foundation.hpp"
#include "HashMap.hpp"
#include "Inventory.hpp"
#include "Order.hpp"

class Store {
 private:
  HashMap<OrderIdentifier, Order>* orderMap;

  HashMap<InventoryCode, Inventory>* inventoryMap;

  HashMap<InventoryCode, UInt64>* inventoryStockMap;

  Vector<Inventory> inventories;

 public:
  /**
  * Constructor
  */
  Store();

  /**
  * Desctructor
  */
  ~Store();

  /**
  * @return the number of available inventories to purchaes
  * @param code the inventory code
  */
  UInt16 numberOfAvailableInventories(InventoryCode code);

  /**
  * @return the vector of all available inventories
  */
  Vector<Inventory> getInventories();

  /**
  * @return boolean check whether the inventory with given code exists in the store
  * @param code the inventory code
  */
  Bool contains(InventoryCode code);

  /**
  * @return the inventory for given code
  * @param code the inventory code
  */
  Inventory inventory(String code);

  /**
  * Purchase the order
  * @param order the order
  */
  void purchase(Order order);

  /**
  * @return the summary of the order
  * @param order the order
  */
  String summary(Order order);

  /**
  * Handle with shopping flow
  * @return the order created for the customer
  * @param customer the customer to shop
  */
  Order shop(User customer);
};
#endif