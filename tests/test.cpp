#include <iostream>
#include <limits>

#include "Overflow.h"

int main() {
  int8_t first = -1;
  int8_t second = std::numeric_limits<int8_t>::min();

  if (math::overflow::isSumValid(first, second)) {
    std::cout << "Sum of " << static_cast<int16_t>(first) << " and "
              << static_cast<int16_t>(second) << " is valid\n";
  } else {
    std::cout << "Sum of " << static_cast<int16_t>(first) << " and "
              << static_cast<int16_t>(second) << " is not valid\n";
  }

  return 0;
}