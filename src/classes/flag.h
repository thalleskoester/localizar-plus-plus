//
// Created by THALLES on 22/04/2021.
//

#ifndef GREP_COMMAND_H
#define GREP_COMMAND_H

#include <string>
#include <vector>

using std::string;
using std::vector;

namespace Grep {

class Flag {
  string name;
  string desc;
  vector<string> params;
  bool status;

public:
  Flag(string name, string desc, vector<string> params);

};

} // namespace Grep

#endif // GREP_COMMAND_H
