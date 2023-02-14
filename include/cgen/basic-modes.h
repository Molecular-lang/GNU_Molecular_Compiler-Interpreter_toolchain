/* Basic CGEN modes. */

#ifndef CGEN_BASIC_MODES_H
#define CGEN_BASIC_MODES_H

/* This file doesn't contain all modes,
   just the basic/portable ones.
   It also provides access to stdint.h so the includer doesn't have
   to deal with the portability issues.  */

#include <stdint.h>

typedef int8_t QI;
typedef uint8_t UQI;

typedef int16_t HI;
typedef uint16_t UHI;

typedef int32_t SI;
typedef uint32_t USI;

typedef int64_t DI;
typedef uint64_t UDI;

typedef int INT;
typedef unsigned int UINT;

/* Cover macro to create a 64-bit integer.  */
#define MAKEDI(hi, lo) ((((DI) (SI) (hi)) << 32) | ((UDI) (USI) (lo)))

#endif /* CGEN_BASIC_MODES_H */
