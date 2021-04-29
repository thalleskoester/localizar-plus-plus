//
// Created by THALLES on 25/04/2021.
//

#ifndef GREP_CONTROLLER_H
#define GREP_CONTROLLER_H

#include "flags-manager.h"

namespace Grep {

class Controller {
  bool debug;
  FlagsManager *flagsManager;

public:
  Controller(int arg_count, char **arg_vec);
  ~Controller();
};

} // namespace Grep

#endif // GREP_CONTROLLER_H
