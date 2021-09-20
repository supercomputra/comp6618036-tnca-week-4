#ifndef ORDER_HPP
#define ORDER_HPP

#include <string>
#include <unordered_map>

#include "user.hpp"

struct Order {
  uint64_t id;
  std::unordered_map<std::string, uint16_t> items_stock_map;  // Inventory as the key and the number of items is the value
  User customer;
  double total_amount();
};

#endif