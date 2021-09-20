#ifndef STORE_HPP
#define STORE_HPP

#include <string>
#include <vector>

#include "hashmap.hpp"
#include "inventory.hpp"
#include "order.hpp"

class Store {
 private:
  HashMap<uint64_t, Order>* order_map;

  HashMap<std::string, Inventory>* inventory_map;

  HashMap<std::string, uint16_t>* inventory_stock_map;

  std::vector<Inventory> inventories;

 public:
  Store();

  uint16_t number_of_available_items(std::string inventory_id);

  std::vector<Inventory> all_items();

  Inventory inventory(std::string inventory_id);

  Order purchase(std::unordered_map<std::string, uint16_t> items_stock_map, User customer);
};
#endif