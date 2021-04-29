//
// Created by THALLES on 22/04/2021.
//

#include "flag.h"

namespace Grep {

Flag::Flag(string flag_name, string flag_desc, vector<string> flag_params)
    : name{flag_name}, desc{flag_desc}, params{flag_params}, status{false} {}

void Flag::setStatus(bool status) { this->status = status; }

bool Flag::getStatus() const { return this->status; }

} // namespace Grep
