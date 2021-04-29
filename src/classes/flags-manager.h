//
// Created by THALLES on 22/04/2021.
//

#ifndef GREP_FLAGS_MANAGER_H
#define GREP_FLAGS_MANAGER_H

#include <string>
#include <vector>

#include "flag.h"

using std::string;
using std::vector;

namespace Grep {

class FlagsManager {
  static const unsigned int MIN_ARGS{3};
  int argc;
  char **argv;
  unsigned int active_flags;
  vector<Flag *> *flags;

public:
  static const unsigned int FLAG_DEBUG{0};
  static const unsigned int FLAG_HELP{1};

  FlagsManager(int argc, char **argv);
  ~FlagsManager();

  void addFlag(Flag *flag);
  void parseFlagsFromArgs(bool debug);
  void displayHelp();
  bool checkIfFlagsExists(const Flag *flag);
  bool checkIfHelpFlagExists();
  bool checkIfDebugFlagExists();
  bool checkMinArgs(bool debug);
};

} // namespace Grep

#endif // GREP_FLAGS_MANAGER_H
