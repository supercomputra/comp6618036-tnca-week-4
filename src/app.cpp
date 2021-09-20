#include "app.hpp"

#include <cmath>
#include <vector>

#include "auth.hpp"
#include "hashmap.hpp"
#include "ioutil.hpp"
#include "store.hpp"

App::App() {
  menu_items.push_back("All Items");
  menu_items.push_back("Purchase by Item");
  menu_items.push_back("Purchase by Prescription");
  menu_items.push_back("Purchase Detail");
  menu_items.push_back("Sign Out");
  auth = new Auth();
  store = new Store();
}

// This method will ask user for menu input
// The number selected by the user shouls map properly
// depends on the order of initialized menu_items
void App::run() {
  User current_user = auth->current_user();

  std::string title = "Welcome " + current_user.name + "!";
  std::string question = "Please input the number associated with the menu";
  int selected = menu_input(title, question, this->menu_items);

  if (selected == 1) {
    get_inventory_list();
    run();
  }
  if (selected == 2) {
    purchase_by_inventory();
    run();
  }
  if (selected == 3) {
    purchase_by_prescription();
    run();
  }
  if (selected == 4) {
    get_purchase_detail();
    run();
  } else {
    auth->sign_out();
    run();
  }
}

void App::get_inventory_list() {
  std::vector<Inventory> items = this->store->all_items();

  print("Here are our available items:");
  print("==================================================================");
  print("No\tInventory\tCode\t\tStock\tPrice");
  for (unsigned int i = 0; i < items.size(); ++i) {
    Inventory item = items[i];
    uint16_t stock = this->store->number_of_available_items(item.id);
    std::string row = std::to_string(i + 1) + ".\t" + item.name + "\t\t" + item.id + "\t\t" + std::to_string(stock) + "\tRp." + std::to_string(std::ceil(item.price * 100.0) / 100.0);
    print(row);
  }
  print("==================================================================");
}

void App::purchase_by_inventory() {
  print_error("Purchase by item hasn't implemented yet\n");
  print_error("Please create pull request related to the issue https://github.com/supercomputra/comp6618036-tnca-week-4/issues/1 \n");
  this->run();
}

void App::purchase_by_prescription() {
  print_error("Purchase by prescription hasn't implemented yet\n");
  print_error("Please create pull request related to the issue https://github.com/supercomputra/comp6618036-tnca-week-4/issues/2 \n");
  this->run();
}

void App::get_purchase_detail() {
  print_error("Purchase detail hasn't implemented yet\n");
  print_error("Please create pull request related to the issue https://github.com/supercomputra/comp6618036-tnca-week-4/issues/3 \n");
  this->run();
}
