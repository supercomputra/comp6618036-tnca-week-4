#include "App.hpp"

#include <cmath>
#include <sstream>

#include "Auth.hpp"
#include "Foundation.hpp"
#include "Store.hpp"

App::App() {
  menuItems.push_back("All Items");
  menuItems.push_back("Purchase by Item");
  menuItems.push_back("Purchase by Prescription");
  menuItems.push_back("Purchase Detail");
  menuItems.push_back("Sign Out");
  auth = new Auth();
  store = new Store();
}

// Destructor
App::~App() {
  delete auth;
  delete store;
}

// This method will ask user for menu input
// The number selected by the user shouls map properly
// depends on the order of initialized menu_items
int App::run() {
  User user;
  try {
    user = auth->currentUser();
  } catch(...) {
    return 0;
  }

  String title = "Welcome " + user.profile.name + "!";
  String question = "Please input the number associated with the menu";
  int selected = readMenuInput(title, question, this->menuItems);

  if (selected == 1) {
    getInventoryList();
    return run();
  }
  if (selected == 2) {
    purchaseByInventory();
    return run();
  }
  if (selected == 3) {
    puchaseByPrescription();
    return run();
  }
  if (selected == 4) {
    getPurchaseDetail();
    return run();
  } else {
    auth->signOut();
    return run();
  }
}

void App::getInventoryList() {
  Vector<Inventory> items = store->getInventories();

  print("Here are our available items:");
  print("===========================================");
  print("Code\tInventory\tStock\tPrice");
  print("-------------------------------------------");
  for (unsigned int i = 0; i < items.size(); ++i) {
    Inventory item = items[i];
    UInt64 stock = store->numberOfAvailableInventories(item.code);

    // Generate string representation from double value with 2 decimal place
    String price = formatCurrency("Rp", item.price);

    // Generate row from each data point
    String row = item.code + "\t" + item.name + "\t\t" + std::to_string(stock) + "\t" + price;
    print(row);
  }
  print("===========================================");
}

void App::purchaseByInventory() {
  getInventoryList();

  // Generate cart
  User customer = auth->currentUser();
  Cart cart = store->shop();
  String summary = store->summary(cart);
  print(summary);

  Bool shouldProceed = readBoolInput("Are you sure to checkout");
  if (shouldProceed) {
    Order order = store->purchase(cart, customer);
    printSuccess("Order created with id " + std::to_string(order.id) + "\n");
    printSuccess("Thank you " + order.customer.profile.name + " for shopping with us!\n");
  }

  run();
}

void App::puchaseByPrescription() {
  print("\nHere are our available prescriptions:");
  print("===========================================");
  Vector<Prescription>prescriptions = store->prescriptions;
  for(unsigned int i = 0; i< prescriptions.size(); ++i){
    Prescription pres = prescriptions[i];
    print("Prescription " + std::to_string((pres.id)));
    print("-------------------------------------------");
    print(store->summary(pres.cart));
  }
  UInt64 selectedPrescriptionId;
  while(true){
    selectedPrescriptionId = readLongNumberInput("Plese input the prescription number you want to purchase");
    if(selectedPrescriptionId > 3){
     printError("Option out of range!\n");
    } else {
      break;
    }
  }

  Prescription selectedPrescription = prescriptions[selectedPrescriptionId-1];
  Order orderData = store->purchase(selectedPrescription.cart, auth->currentUser());
  
  printSuccess("Purchase successful with order id: " + std::to_string(orderData.id) + '\n');
  run();
}

void App::getPurchaseDetail() {
  Order order = store->fetchOrder();
  if (order.customer.id != auth->currentUser().id) {
    printError("The order id you are fetching is belong to someone else. Please try agin!\n");
    return getPurchaseDetail();
  }

  String summary = store->summary(order.cart);
  print("Here is your order detail:");
  String dialog;
  User user = auth->currentUser();
  dialog += "* Customer Name\t\t\t: " + user.profile.name + "\n";
  dialog += "* Customer Email\t\t: " + user.email + "\n";
  dialog += "* Customer Address\t\t: " + user.profile.address + "\n";
  print(dialog);
  print(summary);
  run();
}
