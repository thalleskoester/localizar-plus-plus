//
// Created by THALLES on 22/04/2021.
//

#include <iostream>

#include "flags-manager.h"
#include "flags.h"

using std::cout;
using std::endl;
using std::to_string;

namespace Grep {

FlagsManager::FlagsManager(int arg_count, char **arg_vec)
    : argc{arg_count}, argv{arg_vec}, active_flags{0}, flags{nullptr} {
  this->flags = new vector<Flag *>();

  this->addFlag(Flags::debug());
  this->addFlag(Flags::help());
  this->addFlag(Flags::caseSensitive());
  this->addFlag(Flags::count());
  this->addFlag(Flags::lineNumber());
  this->addFlag(Flags::occurrences());
  this->addFlag(Flags::output());
}

FlagsManager::~FlagsManager() {
  while (!this->flags->empty()) {
    delete this->flags->back();
    this->flags->pop_back();
  }

  delete this->flags;
}

void FlagsManager::addFlag(Flag *flag) { this->flags->push_back(flag); }

void FlagsManager::displayHelp() {
  cout << "----- USAGE ------" << endl;
  cout << "\t" << this->argv[0] << " <options> <search_term> <paths>" << endl;
  cout << "---- OPTIONS -----" << endl;

  for (auto *flag : *this->flags) {
    cout << "\t" << flag->getUsage() << endl;
  }
}

void FlagsManager::parseFlagsFromArgs(bool debug) {
  if (debug) {
    cout << "[PARSER] Parsing started..." << endl;
  }

  for (size_t i = 2; i < this->flags->size(); ++i) {
    auto *flagObj = this->flags->at(i);

    if (FlagsManager::checkIfFlagsExists(flagObj)) {
      flagObj->setStatus();
      ++this->active_flags;
    }

    if (debug) {
      cout << "[PARSER] Flag: " << flagObj->getName()
           << " - Status: " << to_string(flagObj->getStatus()) << endl;
    }
  }

  if (debug) {
    cout << "[PARSER] Parsing started..." << endl;
  }
}

bool FlagsManager::checkIfFlagsExists(const Flag *flag) {
  for (int i = 1; i < this->argc; ++i) {
    if (flag->verify(this->argv[i])) {
      return true;
    }
  }
  return false;
}

bool FlagsManager::checkIfDebugFlagExists() {
  auto *debugObj = this->flags->at(FlagsManager::FLAG_DEBUG);

  if (FlagsManager::checkIfFlagsExists(debugObj)) {
    debugObj->setStatus();
    ++this->active_flags;
    return true;
  }

  return false;
}

bool FlagsManager::checkIfHelpFlagExists() {
  return FlagsManager::checkIfFlagsExists(
      this->flags->at(FlagsManager::FLAG_HELP));
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
