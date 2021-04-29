//
// Created by THALLES on 26/04/2021.
//

#include "flags.h"

namespace Grep {

Flag *Flags::debug() {
  return new Flag("Debug", "Enable detailed output", {"--debug"});
}

Flag *Flags::help() {
  return new Flag("Help", "Display help", {"-h", "--help"});
}

}