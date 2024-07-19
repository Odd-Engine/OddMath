#include <iostream>
#include <limits>

#include "Overflow.h"
#include "gtest/gtest.h"

using namespace math;
using namespace overflow;

TEST(TestOverflow, Uint8Overflow) {
  uint8_t first = 255U;
  uint8_t second = 10U;
  EXPECT_FALSE(isSumValid(first, second));
}

TEST(TestOverflow, Uint8NonOverflow) {
  uint8_t first = 200U;
  uint8_t second = 10U;
  EXPECT_TRUE(isSumValid(first, second));
}