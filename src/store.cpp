#include "store.hpp"

#include "helpers.hpp"
#include "inventory.hpp"

Store::Store() {
  inventory_map = new HashMap<std::string, Inventory>();
  inventory_stock_map = new HashMap<std::string, uint16_t>();
  // Prepare predefined data
  Inventory panadol = {.id = "OBT001", .name = "Panadol", .price = 10000.0};
  inventory_stock_map->set(panadol.id, 13);
  inventory_map->set(panadol.id, panadol);
  inventories.push_back(panadol);

  Inventory sanmol = {.id = "OBT002", .name = "Sanmol", .price = 15000.0};
  inventory_stock_map->set(sanmol.id, 13);
  inventory_map->set(sanmol.id, sanmol);
  inventories.push_back(sanmol);

  Inventory bodrex = {.id = "OBT003", .name = "Bodrex", .price = 11000.0};
  inventory_stock_map->set(bodrex.id, 13);
  inventory_map->set(bodrex.id, bodrex);
  inventories.push_back(bodrex);
}

std::vector<Inventory> Store::all_items() {
  return inventories;
}

uint16_t Store::number_of_available_items(std::string inventory_id) {
  return inventory_stock_map->value(inventory_id);
}

Inventory Store::inventory(std::string inventory_id) {
  return inventory_map->value(inventory_id);
}

Order Store::purchase(std::unordered_map<std::string, uint16_t> items_stock_map, User customer) {
  Order order = {
      .id = timestamp(),
      .items_stock_map = items_stock_map,
      .customer = customer,
  };

  order_map->set(order.id, order);
  return order;
};