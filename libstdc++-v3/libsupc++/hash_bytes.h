// Declarations for hash functions. -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

/** @file bits/hash_bytes.h
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly. @headername{functional}
 */

#ifndef _HASH_BYTES_H
#define _HASH_BYTES_H 1

#pragma GCC system_header

#include <bits/c++config.h>

namespace std
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  // Hash function implementation for the nontrivial specialization.
  // All of them are based on a primitive that hashes a pointer to a
  // byte array. The actual hash algorithm is not guaranteed to stay
  // the same from release to release -- it may be updated or tuned to
  // improve hash quality or speed.
  size_t
  _Hash_bytes(const void* __ptr, size_t __len, size_t __seed);

  // A similar hash primitive, using the FNV hash algorithm. This
  // algorithm is guaranteed to stay the same from release to release.
  // (although it might not produce the same values on different
  // machines.)
  size_t
  _Fnv_hash_bytes(const void* __ptr, size_t __len, size_t __seed);

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace

#endif
