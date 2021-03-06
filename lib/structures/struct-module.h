// Copyright 2019 YHSPY. All rights reserved.
#ifndef LIB_STRUCTURES_STRUCT_MODULE_H_
#define LIB_STRUCTURES_STRUCT_MODULE_H_

#include <vector>
#include <iostream>
#include <memory>
#include <utility>
#include "lib/type.h"
#include "lib/common/macros.h"

using std::vector;
using std::shared_ptr;
using std::move;

// pay attention to the bound check;
#define WRAP_SELECT_METHOD(name, key) \
  const auto name() { return &key; } \
  const auto name(uint32_t index) \
    { return (index >= 0 && index < key.size()) ? &key[index] : nullptr; }

class Module {
 public:
  uint32_t importedFuncCount = 0;
  uint32_t importedTableCount = 0;
  uint32_t startFuncIndex = 0;
  bool hasValidStartFunc = false;

  WRAP_SELECT_METHOD(getTable, tables)
  WRAP_SELECT_METHOD(getFunctionSig, funcSignatures)
  WRAP_SELECT_METHOD(getFunction, functions)
  WRAP_SELECT_METHOD(getExport, exportTable)
  WRAP_SELECT_METHOD(getImport, importTable)
  WRAP_SELECT_METHOD(getGlobal, globals)
  WRAP_SELECT_METHOD(getElement, elements)

  auto& getMemory() { return memory; }

 private:
  // params, returns.
  vector<WasmFunctionSig> funcSignatures;
  // order: external imported | internal defined.
  vector<WasmFunction> functions;
  vector<WasmTable> tables;
  shared_ptr<WasmMemory> memory = nullptr;
  vector<WasmGlobal> globals;
  vector<WasmExport> exportTable;
  vector<WasmImport> importTable;
  vector<WasmElement<>> elements;
};

using shared_module_t = shared_ptr<Module>;

#endif  // LIB_STRUCTURES_STRUCT_MODULE_H_
