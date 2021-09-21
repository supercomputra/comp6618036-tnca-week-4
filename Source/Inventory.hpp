#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include <string>

#include "Foundation.hpp"

typedef String InventoryCode;

struct Inventory {
  InventoryCode code;
  String name;
  Double price;
};

#endif