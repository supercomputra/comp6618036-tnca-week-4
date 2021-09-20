#include <unordered_map>
#include <vector>

#include "model/inventory.cc"
#include "model/order.cc"

class Store {
 private:
  std::unordered_map<std::string, Inventory> inventory_map;
  std::unordered_map<std::string, bool> inventory_existance_map;
  std::unordered_map<std::string, uint16_t> inventory_stock_map;
  std::vector<Inventory> inventories;

  std::unordered_map<std::string, Order> order_map;
  std::unordered_map<std::string, bool> order_existance_map;

 public:
  Store() {
    // Prepare predefined data
    Inventory panadol = {.id = "OBT001", .name = "Panadol", .price = 10000.0};
    inventory_stock_map[panadol.id] = 13;
    inventory_map[panadol.id] = panadol;
    inventory_existance_map[panadol.id] = true;
    inventories.push_back(panadol);

    Inventory sanmol = {.id = "OBT002", .name = "Sanmol", .price = 15000.0};
    inventory_stock_map[sanmol.id] = 13;
    inventory_map[sanmol.id] = sanmol;
    inventory_existance_map[sanmol.id] = true;
    inventories.push_back(sanmol);

    Inventory bodrex = {.id = "OBT003", .name = "Bodrex", .price = 11000.0};
    inventory_stock_map[bodrex.id] = 13;
    inventory_map[bodrex.id] = bodrex;
    inventory_existance_map[bodrex.id] = true;
    inventories.push_back(bodrex);
  }

  int number_of_stock_for_inventory(std::string inventory_id) {
    return inventory_stock_map[inventory_id];
  }

  Inventory inventory(std::string inventory_id) {
    if (inventory_existance_map[inventory_id] == false) {
      throw "Not Found";
    }

    return inventory_map[inventory_id];
  }

  Order purchase(std::unordered_map<Inventory, uint16_t> items_map, User customer) {
    Order order = {
        .id = current_timestamp(),
        .items_map = items_map,
        .customer = customer};

    order_existance_map[order.id] = true;
    order_map[order.id] = order;
    return order;
  }
};