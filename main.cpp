#include "src/app.cpp"
#include "src/auth.cpp"
#include "src/helpers.cpp"
#include "src/ioutil.cpp"
#include "src/store.cpp"

int main(int argc, char* argv[]) {
  App* app = new App();
  app->run();
  return 0;
}
