// std::hash definitions -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

#if __cplusplus < 201103L
# error "hash_c++0x.cc must be compiled with -std=gnu++0x"
#endif

#include <type_traits>
#include <bits/functional_hash.h>

namespace std _GLIBCXX_VISIBILITY(default) {
  _GLIBCXX_PURE size_t
  hash<long double>::operator()(long double __val) const noexcept {
    // 0 and -0 both hash to zero.
    if (__val == 0.0L)
      return 0;

    int __exponent;
    __val = __builtin_frexpl(__val, &__exponent);
    __val = __val < 0.0l ? -(__val + 0.5l) : __val;

    const long double __mult = __SIZE_MAX__ + 1.0l;
    __val *= __mult;

    // Try to use all the bits of the mantissa (really necessary only
    // on 32-bit targets, at least for 80-bit floating point formats).
    const size_t __hibits = (size_t)__val;
    __val = (__val - (long double)__hibits) * __mult;

    const size_t __coeff = __SIZE_MAX__ / __LDBL_MAX_EXP__;

    return __hibits + (size_t)__val + __coeff * __exponent;
  }
}
