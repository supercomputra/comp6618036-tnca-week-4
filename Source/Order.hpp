#ifndef ORDER_HPP
#define ORDER_HPP
#include <string>
#include <unordered_map>

#include "Foundation.hpp"
#include "User.hpp"

typedef UInt64 OrderIdentifier;

struct Order {
 public:
  OrderIdentifier id;
  User customer;

  Order(User customer = User()) {
    this->itemStockMap = new HashMap<InventoryCode, UInt16>();
    this->customer = customer;
    this->id = timestamp();
  }

  ~Order() {
    delete itemStockMap;
  }

  Vector<InventoryCode> allInventoryIdentifiers() {
    return itemStockMap->allKeys();
  }

  /**
   * Add item with amount to cart
   *    
   * @param code the inventory code
   * @param amount the amount of inventory to be added to the cart
   */
  void addToCart(InventoryCode code, UInt16 amount) {
    if (itemStockMap->contains(code)) {
      UInt16 currentAmount = itemStockMap->get(code);
      itemStockMap->set(code, currentAmount + amount);
    }

    itemStockMap->set(code, amount);
  }

  /**
   * @return the number of inventory for given code
   * @param code
  */
  UInt16 numberOfInventories(InventoryCode code) {
    if (itemStockMap->contains(code)) {
      return itemStockMap->get(code);
    }

    return 0;
  }

 private:
  HashMap<InventoryCode, UInt16>* itemStockMap;
};

#endif