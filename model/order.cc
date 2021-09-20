
#include <string>
#include <unordered_map>

#include "inventory.cc"
#include "user.cc"

struct Order {
  uint64_t id;
  std::unordered_map<Inventory, uint16_t> items_map;  // Inventory as the key and the number of items is the value
  User customer;

  double total_amount() {
    // TODO: Calculate the total amount
    // By iteratring each item in the items_map
    return 0.0;
  }
};