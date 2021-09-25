#ifndef Prescription_HPP
#define Prescription_HPP

#include "Cart.hpp"
#include "Foundation.hpp"

typedef UInt64 PrescriptionIdentifier;

struct Prescription {
  PrescriptionIdentifier id;
  Cart cart;
};

#endif