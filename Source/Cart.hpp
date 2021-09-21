#ifndef CART_HPP
#define CART_HPP

#include "Foundation.hpp"
#include "Inventory.hpp"

struct Cart {
 private:
  HashMap<InventoryCode, UInt16> amountMap;

 public:
  /**
   * Add item with amount to cart
   *    
   * @param code the inventory code
   * @param amount the amount of inventory to be added to the cart
   */
  void add(InventoryCode code, UInt16 amount) {
    if (amountMap.contains(code)) {
      UInt16 currentAmount = amountMap.get(code);
      amountMap.set(code, (currentAmount + amount));
    }

    amountMap.set(code, amount);
  }

  /**
   * Get all inventory code from current state of the cart
   *    
   * @param return code list
   */
  Vector<InventoryCode> allCodes() {
    return amountMap.allKeys();
  }

  /**
   * Get the amount for given inventory code
   * 
   * @return the amount of the inventory 
   * @param code the inventory code
   */
  UInt16 amountForInventory(InventoryCode code) {
    if (amountMap.contains(code)) {
      return amountMap.get(code);
    }

    return 0;
  }
};

#endif