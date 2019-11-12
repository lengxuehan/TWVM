// Copyright 2019 YHSPY. All rights reserved.
#include <iostream>
#include <string>
#include "./utilities.h"
#include "./constants.h"
#include "./loader.h"
#include "./module.h"
#include "./executor.h"

using std::to_string;

int main(int argc, char **argv) {
  if (argc < 2) {
    Utilities::reportError("no input file.");
    return 1;
  }

  const auto wasmModule = Loader::init(argv[INPUT_ARG_OFFSET]);
  // debug;
  if (wasmModule) {
    const auto wasmModuleSize = wasmModule->getModContentLength();
    if (wasmModuleSize > 0) {
      Utilities::reportDebug("module parsing completed. (" + to_string(wasmModuleSize) + " bytes)");
    }
  } else {
    return 1;
  }

  return 0;
}
