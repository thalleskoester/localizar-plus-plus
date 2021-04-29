//
// Created by THALLES on 22/04/2021.
//

#include "flags-manager.h"

namespace Grep {

FlagsManager::FlagsManager(int arg_count, char **arg_vec)
    : argc{arg_count}, argv{arg_vec}, active_flags{0}, flags{nullptr} {
  this->flags = new vector<Flag *>();
}

FlagsManager::~FlagsManager() {
  while (!this->flags->empty()) {
    delete this->flags->back();
    this->flags->pop_back();
  }

  delete this->flags;
}

} // namespace Grep
