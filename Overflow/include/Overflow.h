#ifndef OVERFLOW_H
#define OVERFLOW_H

#include <float.h>
#include <stdint.h>

typedef float float32_t;
typedef double float64_t;

namespace math {

namespace overflow {

///@{
/**
 * @brief Checks if sum can be performed without overflowing the bounds of the data type
 *
 * @param first     first value in the sum
 * @param second    second value in the sum
 * @return true when sum can be performed, false if not
 */
bool isSumValid(int8_t first, int8_t second);
bool isSumValid(int16_t first, int16_t second);
bool isSumValid(int32_t first, int32_t second);
bool isSumValid(int64_t first, int64_t second);

bool isSumValid(uint8_t first, uint8_t second);
bool isSumValid(uint16_t first, uint16_t second);
bool isSumValid(uint32_t first, uint32_t second);
bool isSumValid(uint64_t first, uint64_t second);

bool isSumValid(float32_t first, float32_t second);
bool isSumValid(float64_t first, float64_t second);
///@}

}  // namespace overflow

}  // namespace math

#endif  // #ifndef OVERFLOW_H