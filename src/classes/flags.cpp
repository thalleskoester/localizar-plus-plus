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

Flag *Flags::caseSensitive() {
  return new Flag("Case Sensitive", "Case sensitive search disable",
                  {"-i", "--case"});
}

Flag *Flags::count() {
  return new Flag("Count",
                  "Display count of lines with has appearances of the pattern",
                  {"-c", "--count"});
}

Flag *Flags::lineNumber() {
  return new Flag("Line Number",
                  "Display the number of the line witch contains the pattern",
                  {"-n", "--numb"});
}

Flag *Flags::occurrences() {
  return new Flag("Occurrences",
                  "Display occurrences os the pattern in the file",
                  {"-r", "--rep"});
}

Flag *Flags::output() {
  return new Flag("Output", "Save an output copy without the pattern",
                  {"-o", "--out"});
}

}