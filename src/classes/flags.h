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

  static Flag *caseSensitive();
  static Flag *count();
  static Flag *lineNumber();
  static Flag *occurrences();
  static Flag *output();
};

}

#endif // GREP_FLAGS_H
