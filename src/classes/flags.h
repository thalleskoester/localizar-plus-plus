//
// Created by THALLES on 26/04/2021.
//

#ifndef GREP_FLAGS_H
#define GREP_FLAGS_H

#include "flag.h"

namespace Grep {

class Flags {
public:
  static Flag *debug();
  static Flag *help();
};

}

#endif // GREP_FLAGS_H
