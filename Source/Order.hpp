#ifndef ORDER_HPP
#define ORDER_HPP

#include "Foundation.hpp"
#include "User.hpp"

typedef UInt64 OrderIdentifier;

struct Order {
 public:
  OrderIdentifier id;
  User customer;
  Cart cart;

  Order(User customer = User(), Cart cart = Cart()) {
    this->customer = customer;
    this->id = timestamp();
    this->cart = cart;
  }

  ~Order() {}
};

#endif