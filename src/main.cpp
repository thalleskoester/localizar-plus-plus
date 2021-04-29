
#include "classes/controller.h"

using Grep::Controller;

int main(int argc, char *argv[]) {
  auto *controller = new Controller(argc, argv);
  controller->init();
  delete controller;

  return 0;
}