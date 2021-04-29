//
// Created by THALLES on 25/04/2021.
//

#include "controller.h"

namespace Grep {

Controller::Controller(int arg_count, char **arg_vec)
    : debug{false}, flagsManager{nullptr} {
  this->flagsManager = new FlagsManager(arg_count, arg_vec);
}

Controller::~Controller() { delete this->flagsManager; }

bool Controller::parseArguments() {
  if (!this->flagsManager->checkMinArgs(this->debug) ||
      this->flagsManager->checkIfHelpFlagExists()) {
    this->flagsManager->displayHelp();
    return false;
  }

  this->flagsManager->parseFlagsFromArgs(this->debug);
  return true;
}

} // namespace Grep
