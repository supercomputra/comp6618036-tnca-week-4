#ifndef STORE_HPP
#define STORE_HPP

#include "Cart.hpp"
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
  * @param cart the cart to be purchased
  * @param customer the purchasing customer
  * @return the order
  */
  Order purchase(Cart cart, User customer);

  /**
  * @return the summary of the order
  * @param cart the cart
  */
  String summary(Cart cart);

  /**
  * Handle with shopping flow
  * @return the order created for the customer
  */
  Cart shop();
};
#endif