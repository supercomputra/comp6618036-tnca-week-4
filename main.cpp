#include "Source/App.cpp"
#include "Source/Auth.cpp"
#include "Source/Foundation.cpp"
#include "Source/Store.cpp"

int main(int argc, char* argv[]) {
  App* app = new App();
  app->run();
  return 0;
}
