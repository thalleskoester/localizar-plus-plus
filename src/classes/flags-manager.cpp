//
// Created by THALLES on 22/04/2021.
//

#include <iostream>

#include "flags-manager.h"
#include "flags.h"

using std::cout;
using std::endl;

namespace Grep {

FlagsManager::FlagsManager(int arg_count, char **arg_vec)
    : argc{arg_count}, argv{arg_vec}, active_flags{0}, flags{nullptr} {
  this->flags = new vector<Flag *>();

  this->addFlag(Flags::debug());
  this->addFlag(Flags::help());
}

FlagsManager::~FlagsManager() {
  while (!this->flags->empty()) {
    delete this->flags->back();
    this->flags->pop_back();
  }

  delete this->flags;
}

void FlagsManager::addFlag(Flag *flag) { this->flags->push_back(flag); }

bool FlagsManager::checkIfFlagsExists(const Flag *flag) {
  for (int i = 1; i < this->argc; ++i) {
    if (flag->verify(this->argv[i])) {
      return true;
    }
  }
  return false;
}

bool FlagsManager::checkMinArgs(bool debug) {
  if (this->argc >= FlagsManager::MIN_ARGS) {
    return true;
  }

  if (debug) {
    cout << "[PARSE] Invalid usage!";
  }

  return false;
}

} // namespace Grep
