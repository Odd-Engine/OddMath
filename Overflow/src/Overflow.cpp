#include "Overflow.h"

#include <limits>

namespace math {

namespace overflow {

bool isSumValid(int8_t first, int8_t second) {
  /**
     * We can't just add and verify that the sum is fine
     * We break into cases where we identify when things
     * can go wrong
     *
     * positive, positive:
     *      first + second > MAX -> first > MAX - second
     *      first + second < MIN -> impossible
     *
     * (positive, negative) or (negative, positive):
     *      first + second > MAX -> impossible
     *      first + second < MIN -> impossible
     *
     * negative, negative:
     *      first + second > MAX -> impossible
     *      first + second < MIN -> first < MIN - second
     */

  if ((first > 0) && (second > 0)) {
    if (first > (std::numeric_limits<int8_t>::max() - second)) {
      return false;
    }
  }

  else if ((first < 0) && (second < 0)) {
    if (first < (std::numeric_limits<int8_t>::min() - second)) {
      return false;
    }
  }

  return true;
}

bool isSumValid(int16_t first, int16_t second) {
  /**
     * We can't just add and verify that the sum is fine
     * We break into cases where we identify when things
     * can go wrong
     *
     * positive, positive:
     *      first + second > MAX -> first > MAX - second
     *      first + second < MIN -> impossible
     *
     * (positive, negative) or (negative, positive):
     *      first + second > MAX -> impossible
     *      first + second < MIN -> impossible
     *
     * negative, negative:
     *      first + second > MAX -> impossible
     *      first + second < MIN -> first < MIN - second
     */

  if ((first > 0) && (second > 0)) {
    if (first > (std::numeric_limits<int16_t>::max() - second)) {
      return false;
    }
  }

  else if ((first < 0) && (second < 0)) {
    if (first < (std::numeric_limits<int16_t>::min() - second)) {
      return false;
    }
  }

  return true;
}

bool isSumValid(int32_t first, int32_t second) {
  /**
     * We can't just add and verify that the sum is fine
     * We break into cases where we identify when things
     * can go wrong
     *
     * positive, positive:
     *      first + second > MAX -> first > MAX - second
     *      first + second < MIN -> impossible
     *
     * (positive, negative) or (negative, positive):
     *      first + second > MAX -> impossible
     *      first + second < MIN -> impossible
     *
     * negative, negative:
     *      first + second > MAX -> impossible
     *      first + second < MIN -> first < MIN - second
     */

  if ((first > 0) && (second > 0)) {
    if (first > (std::numeric_limits<int32_t>::max() - second)) {
      return false;
    }
  }

  else if ((first < 0) && (second < 0)) {
    if (first < (std::numeric_limits<int32_t>::min() - second)) {
      return false;
    }
  }

  return true;
}

bool isSumValid(int64_t first, int64_t second) {
  /**
     * We can't just add and verify that the sum is fine
     * We break into cases where we identify when things
     * can go wrong
     *
     * positive, positive:
     *      first + second > MAX -> first > MAX - second
     *      first + second < MIN -> impossible
     *
     * (positive, negative) or (negative, positive):
     *      first + second > MAX -> impossible
     *      first + second < MIN -> impossible
     *
     * negative, negative:
     *      first + second > MAX -> impossible
     *      first + second < MIN -> first < MIN - second
     */

  if ((first > 0) && (second > 0)) {
    if (first > (std::numeric_limits<int64_t>::max() - second)) {
      return false;
    }
  }

  else if ((first < 0) && (second < 0)) {
    if (first < (std::numeric_limits<int64_t>::min() - second)) {
      return false;
    }
  }

  return true;
}

bool isSumValid(uint8_t first, uint8_t second) {
  /**
     * We can't just add and verify that the sum is fine
     * We break into cases where we identify when things
     * can go wrong
     *
     * first + second < 0 -> first < -second
     *      Cannot happen with unsigned ints
     *
     * first + second > MAX -> first > MAX - second
     *      Subtraction can be performed because MAX - second >= 0U
     */

  return (first <= (std::numeric_limits<uint8_t>::max() - second));
}

bool isSumValid(uint16_t first, uint16_t second) {
  /**
     * We can't just add and verify that the sum is fine
     * We break into cases where we identify when things
     * can go wrong
     *
     * first + second < 0 -> first < -second
     *      Cannot happen with unsigned ints
     *
     * first + second > MAX -> first > MAX - second
     *      Subtraction can be performed because MAX - second >= 0U
     */

  return (first <= (std::numeric_limits<uint16_t>::max() - second));
}

bool isSumValid(uint32_t first, uint32_t second) {
  /**
     * We can't just add and verify that the sum is fine
     * We break into cases where we identify when things
     * can go wrong
     *
     * first + second < 0 -> first < -second
     *      Cannot happen with unsigned ints
     *
     * first + second > MAX -> first > MAX - second
     *      Subtraction can be performed because MAX - second >= 0U
     */

  return (first <= (std::numeric_limits<uint32_t>::max() - second));
}

bool isSumValid(uint64_t first, uint64_t second) {
  /**
     * We can't just add and verify that the sum is fine
     * We break into cases where we identify when things
     * can go wrong
     *
     * first + second < 0 -> first < -second
     *      Cannot happen with unsigned ints
     *
     * first + second > MAX -> first > MAX - second
     *      Subtraction can be performed because MAX - second >= 0U
     */

  return (first <= (std::numeric_limits<uint64_t>::max() - second));
}

}  // namespace overflow

}  // namespace math