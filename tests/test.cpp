#include <iostream>
#include <limits>

#include "Overflow.h"
#include "gtest/gtest.h"

using namespace math;
using namespace overflow;

TEST(TestOverflow, Uint8_overflow) {
  uint8_t first = 255U;
  uint8_t second = 10U;
  EXPECT_FALSE(isSumValid(first, second));
}

TEST(TestOverflow, Uint8_nonOverflow) {
  uint8_t first = 200U;
  uint8_t second = 55U;
  EXPECT_TRUE(isSumValid(first, second));
}

TEST(TestOverflow, Uint16_overflow) {
  uint16_t first = 65530U;
  uint16_t second = 10U;
  EXPECT_FALSE(isSumValid(first, second));
}

TEST(TestOverflow, Uint16_nonOverflow) {
  uint16_t first = 65500U;
  uint16_t second = 35U;
  EXPECT_TRUE(isSumValid(first, second));
}

TEST(TestOverflow, Uint32_overflow) {
  uint32_t first = std::numeric_limits<uint32_t>::max() - 5U;
  uint32_t second = 10U;
  EXPECT_FALSE(isSumValid(first, second));
}

TEST(TestOverflow, Uint32_nonOverflow) {
  uint32_t first = std::numeric_limits<uint32_t>::max() - 50U;
  uint32_t second = 50U;
  EXPECT_TRUE(isSumValid(first, second));
}

TEST(TestOverflow, Uint64_overflow) {
  uint64_t first = std::numeric_limits<uint64_t>::max() - 5U;
  uint64_t second = 10U;
  EXPECT_FALSE(isSumValid(first, second));
}

TEST(TestOverflow, Uint64_nonOverflow) {
  uint64_t first = std::numeric_limits<uint64_t>::max() - 50U;
  uint64_t second = 50U;
  EXPECT_TRUE(isSumValid(first, second));
}

TEST(TestOverflow, Int8_overflow) {
  int8_t first = 120;
  int8_t second = 8;
  EXPECT_FALSE(isSumValid(first, second));
}

TEST(TestOverflow, Int8_underflow) {
  int8_t first = -120;
  int8_t second = -9;
  EXPECT_FALSE(isSumValid(first, second));
}

TEST(TestOverflow, Int8_nonOverflow) {
  int8_t first = 120;
  int8_t second = 7;
  EXPECT_TRUE(isSumValid(first, second));
}

TEST(TestOverflow, Int8_NonUnderflow) {
  int8_t first = -120;
  int8_t second = -8;
  EXPECT_TRUE(isSumValid(first, second));
}

TEST(TestOverflow, Int8_pos_neg_impossible) {
  int8_t first = 1;
  int8_t second = std::numeric_limits<int8_t>::min();
  EXPECT_TRUE(isSumValid(first, second));
}

TEST(TestOverflow, Int8_neg_pos_impossible) {
  int8_t first = std::numeric_limits<int8_t>::min();
  int8_t second = 1;
  EXPECT_TRUE(isSumValid(first, second));
}

TEST(TestOverflow, Int16_overflow) {
  int16_t first = 32700;
  int16_t second = 68;
  EXPECT_FALSE(isSumValid(first, second));
}

TEST(TestOverflow, Int16_underflow) {
  int16_t first = -32700;
  int16_t second = -69;
  EXPECT_FALSE(isSumValid(first, second));
}

TEST(TestOverflow, Int16_nonOverflow) {
  int16_t first = 32700;
  int16_t second = 67;
  EXPECT_TRUE(isSumValid(first, second));
}

TEST(TestOverflow, Int16_NonUnderflow) {
  int16_t first = -32700;
  int16_t second = -68;
  EXPECT_TRUE(isSumValid(first, second));
}

TEST(TestOverflow, Int16_pos_neg_impossible) {
  int16_t first = 1;
  int16_t second = std::numeric_limits<int16_t>::min();
  EXPECT_TRUE(isSumValid(first, second));
}

TEST(TestOverflow, Int16_neg_pos_impossible) {
  int16_t first = std::numeric_limits<int16_t>::min();
  int16_t second = 1;
  EXPECT_TRUE(isSumValid(first, second));
}

TEST(TestOverflow, Int32_overflow) {
  int32_t first = std::numeric_limits<int32_t>::max() - 50;
  int32_t second = 51;
  EXPECT_FALSE(isSumValid(first, second));
}

TEST(TestOverflow, Int32_underflow) {
  int32_t first = std::numeric_limits<int32_t>::min() + 50;
  int32_t second = -51;
  EXPECT_FALSE(isSumValid(first, second));
}

TEST(TestOverflow, Int32_nonOverflow) {
  int32_t first = std::numeric_limits<int32_t>::max() - 50;
  int32_t second = 50;
  EXPECT_TRUE(isSumValid(first, second));
}

TEST(TestOverflow, Int32_NonUnderflow) {
  int32_t first = std::numeric_limits<int32_t>::min() + 50;
  int32_t second = -50;
  EXPECT_TRUE(isSumValid(first, second));
}

TEST(TestOverflow, Int32_pos_neg_impossible) {
  int32_t first = 1;
  int32_t second = std::numeric_limits<int32_t>::min();
  EXPECT_TRUE(isSumValid(first, second));
}

TEST(TestOverflow, Int32_neg_pos_impossible) {
  int32_t first = std::numeric_limits<int32_t>::min();
  int32_t second = 1;
  EXPECT_TRUE(isSumValid(first, second));
}

TEST(TestOverflow, Int64_overflow) {
  int64_t first = std::numeric_limits<int64_t>::max() - 50;
  int64_t second = 51;
  EXPECT_FALSE(isSumValid(first, second));
}

TEST(TestOverflow, Int64_underflow) {
  int64_t first = std::numeric_limits<int64_t>::min() + 50;
  int64_t second = -51;
  EXPECT_FALSE(isSumValid(first, second));
}

TEST(TestOverflow, Int64_nonOverflow) {
  int64_t first = std::numeric_limits<int64_t>::max() - 50;
  int64_t second = 50;
  EXPECT_TRUE(isSumValid(first, second));
}

TEST(TestOverflow, Int64_NonUnderflow) {
  int64_t first = std::numeric_limits<int64_t>::min() + 50;
  int64_t second = -50;
  EXPECT_TRUE(isSumValid(first, second));
}

TEST(TestOverflow, Int64_pos_neg_impossible) {
  int64_t first = 1;
  int64_t second = std::numeric_limits<int64_t>::min();
  EXPECT_TRUE(isSumValid(first, second));
}

TEST(TestOverflow, Int64_neg_pos_impossible) {
  int64_t first = std::numeric_limits<int64_t>::min();
  int64_t second = 1;
  EXPECT_TRUE(isSumValid(first, second));
}
