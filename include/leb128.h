/* Utilities for reading leb128 values. */

/* The functions defined here can be speed critical.
   Since they are all pretty small we keep things simple and just define
   them all as "static inline".

   WARNING: This file is used by GDB which is stuck at C90. :-(
   Though it can use stdint.h, inttypes.h.
   Therefore if you want to add support for "long long" you need
   to wrap it in #ifdef CC_HAS_LONG_LONG.  */

#ifndef LEB128_H
#define LEB128_H

/* Get a definition for inline.  */
#include "ansidecl.h"

/* Get a definition for NULL, size_t.  */
#include <stddef.h>

#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif
#ifdef HAVE_INTTYPES_H
#include <inttypes.h>
#endif

/* Decode the unsigned LEB128 constant at BUF into the variable pointed to
   by R, and return the number of bytes read.
   If we read off the end of the buffer, zero is returned,
   and nothing is stored in R.

   Note: The result is an int instead of a pointer to the next byte to be
   read to avoid const-vs-non-const problems.  */

static inline size_t
read_uleb128_to_uint64 (const unsigned char *buf, const unsigned char *buf_end,
			uint64_t *r)
{
  const unsigned char *p = buf;
  unsigned int shift = 0;
  uint64_t result = 0;
  unsigned char byte;

  while (1)
    {
      if (p >= buf_end)
	return 0;

      byte = *p++;
      result |= ((uint64_t) (byte & 0x7f)) << shift;
      if ((byte & 0x80) == 0)
	break;
      shift += 7;
    }

  *r = result;
  return p - buf;
}

/* Decode the signed LEB128 constant at BUF into the variable pointed to
   by R, and return the number of bytes read.
   If we read off the end of the buffer, zero is returned,
   and nothing is stored in R.

   Note: The result is an int instead of a pointer to the next byte to be
   read to avoid const-vs-non-const problems.  */

static inline size_t
read_sleb128_to_int64 (const unsigned char *buf, const unsigned char *buf_end,
		       int64_t *r)
{
  const unsigned char *p = buf;
  unsigned int shift = 0;
  int64_t result = 0;
  unsigned char byte;

  while (1)
    {
      if (p >= buf_end)
	return 0;

      byte = *p++;
      result |= ((uint64_t) (byte & 0x7f)) << shift;
      shift += 7;
      if ((byte & 0x80) == 0)
	break;
    }
  if (shift < (sizeof (*r) * 8) && (byte & 0x40) != 0)
    result |= -(((uint64_t) 1) << shift);

  *r = result;
  return p - buf;
}

/* Return the number of bytes to read to skip past an LEB128 number in BUF.
   If the end isn't found before reaching BUF_END, return zero.

   Note: The result is an int instead of a pointer to the next byte to be
   read to avoid const-vs-non-const problems.  */

static inline size_t
skip_leb128 (const unsigned char *buf, const unsigned char *buf_end)
{
  const unsigned char *p = buf;
  unsigned char byte;

  while (1)
    {
      if (p == buf_end)
	return 0;

      byte = *p++;
      if ((byte & 0x80) == 0)
	return p - buf;
    }
}

#endif /* LEB128_H */
