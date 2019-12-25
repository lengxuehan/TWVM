#include <memory>
#include <iostream>
#include <vector>
#include "gtest/gtest.h"
#include "lib/loader.h"
#include "lib/executor.h"
#include "lib/instantiator.h"

using std::make_unique;
using std::cout;
using std::endl;
using std::vector;

TEST(TWVM, Miscellaneous) {
  const auto executor = make_unique<Executor>();
  // little-endian;
  executor->execute(
    Instantiator::instantiate(
      Loader::init(vector<uint8_t>{
        0, 0x61, 0x73, 0x6d, 0x1, 0, 0, 0, 0x1, 0x8a, 0x80, 0x80, 0x80, 0, 0x2, 0x60,
        0x1, 0x7f, 0x1, 0x7f, 0x60, 0, 0x1, 0x7f, 0x3, 0x83, 0x80, 0x80, 0x80, 0, 0x2, 0,
        0x1, 0x4, 0x84, 0x80, 0x80, 0x80, 0, 0x1, 0x70, 0, 0, 0x5, 0x83, 0x80, 0x80, 0x80,
        0, 0x1, 0, 0x1, 0x6, 0x81, 0x80, 0x80, 0x80, 0, 0, 0x7, 0x97, 0x80, 0x80, 0x80,
        0, 0x3, 0x6, 0x6d, 0x65, 0x6d, 0x6f, 0x72, 0x79, 0x2, 0, 0x3, 0x66, 0x69, 0x62, 0,
        0, 0x4, 0x6d, 0x61, 0x69, 0x6e, 0, 0x1, 0x0a, 0xaf, 0x80, 0x80, 0x80, 0, 0x2, 0x9e,
        0x80, 0x80, 0x80, 0, 0, 0x2, 0x40, 0x20, 0, 0x41, 0x2, 0x4e, 0xd, 0, 0x20, 0,
        0x0f, 0xb, 0x20, 0, 0x41, 0x7f, 0x6a, 0x10, 0, 0x20, 0, 0x41, 0x7e, 0x6a, 0x10, 0,
        0x6a, 0x0b, 0x86, 0x80, 0x80, 0x80, 0, 0, 0x41, 0x0a, 0x10, 0, 0x0b,  
      })));
  EXPECT_EQ(55, executor->inspectRunningResult<int32_t>());
}