#include <unordered_map>
#include <vector>

#include "authentication.cc"

class App {
 private:
  std::vector<std::string> menu_items;
  Authentication* authentication;

 public:
  App() {
    this->menu_items.push_back("All Items");
    this->menu_items.push_back("Purchase by Item");
    this->menu_items.push_back("Purchase by Prescription");
    this->menu_items.push_back("Purchase Detail");
    this->menu_items.push_back("Sign Out");
    this->authentication = new Authentication();
  }

  // This method will ask user for menu input
  // The number selected by the user shouls map properly
  // depends on the order of initialized menu_items
  int run() {
    User current_user = authentication->current_user();

    std::string title = "Welcome " + current_user.name + "!";
    std::string question = "Please input the number associated with the menu";
    int selected = menu_input(title, question, this->menu_items);

    if (selected == 1) {
      print_error("Item list hasn't implemented yet\n");
      this->run();
    }

    if (selected == 2) {
      print_error("Purchase by item hasn't implemented yet\n");
      this->run();
    }

    if (selected == 3) {
      print_error("Purchase by prescription hasn't implemented yet\n");
      this->run();
    }

    if (selected == 4) {
      print_error("Purchase detail hasn't implemented yet\n");
      this->run();
    }

    if (selected == 5) {
      authentication->sign_out();
      this->run();
    }

    // For unxexpected selection
    return 1;
  }
};