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

} // namespace Grep
