// Please review: $(src-dir)/SPL-README for Licencing info.

/** @file parallel/random_number.h
 *  @brief Random number generator based on the Mersenne twister.
 *  This file is a GNU parallel extension to the Standard C++ Library.
 */

// Written by Johannes Singler.

#ifndef _GLIBCXX_PARALLEL_RANDOM_NUMBER_H
#define _GLIBCXX_PARALLEL_RANDOM_NUMBER_H 1

#include <parallel/types.h>
#include <tr1/random>
#include <limits>

namespace __gnu_parallel
{
  /** @brief Random number generator, based on the Mersenne twister. */
  class _RandomNumber
  {
  private:
    std::tr1::mt19937   _M_mt;
    uint64_t            _M_supremum;
    uint64_t            _M_rand_sup;
    double              _M_supremum_reciprocal;
    double              _M_rand_sup_reciprocal;

    // Assumed to be twice as long as the usual random number.
    uint64_t              __cache;

    // Bit results.
    int __bits_left;
    
    static uint32_t
    __scale_down(uint64_t __x,
#if _GLIBCXX_SCALE_DOWN_FPU
               uint64_t /*_M_supremum*/, double _M_supremum_reciprocal)
#else
               uint64_t _M_supremum, double /*_M_supremum_reciprocal*/)
#endif
        {
#if _GLIBCXX_SCALE_DOWN_FPU
          return uint32_t(__x * _M_supremum_reciprocal);
#else
          return static_cast<uint32_t>(__x % _M_supremum);
#endif
        }

  public:
    /** @brief Default constructor. Seed with 0. */
    _RandomNumber()
    : _M_mt(0), _M_supremum(0x100000000ULL),
      _M_rand_sup(1ULL << std::numeric_limits<uint32_t>::digits),
      _M_supremum_reciprocal(double(_M_supremum) / double(_M_rand_sup)),
      _M_rand_sup_reciprocal(1.0 / double(_M_rand_sup)),
      __cache(0), __bits_left(0) { }

    /** @brief Constructor.
     *  @param __seed Random __seed.
     *  @param _M_supremum Generate integer random numbers in the
     *                  interval @c [0,_M_supremum). */
    _RandomNumber(uint32_t __seed, uint64_t _M_supremum = 0x100000000ULL)
    : _M_mt(__seed), _M_supremum(_M_supremum),
      _M_rand_sup(1ULL << std::numeric_limits<uint32_t>::digits),
      _M_supremum_reciprocal(double(_M_supremum) / double(_M_rand_sup)),
      _M_rand_sup_reciprocal(1.0 / double(_M_rand_sup)),
      __cache(0), __bits_left(0) { }

    /** @brief Generate unsigned random 32-bit integer. */
    uint32_t
    operator()()
    { return __scale_down(_M_mt(), _M_supremum, _M_supremum_reciprocal); }

    /** @brief Generate unsigned random 32-bit integer in the
        interval @c [0,local_supremum). */
    uint32_t
    operator()(uint64_t local_supremum)
    {
      return __scale_down(_M_mt(), local_supremum,
                        double(local_supremum * _M_rand_sup_reciprocal));
    }

    /** @brief Generate a number of random bits, run-time parameter.
     *  @param __bits Number of bits to generate. */
    unsigned long
    __genrand_bits(int __bits)
    {
      unsigned long __res = __cache & ((1 << __bits) - 1);
      __cache = __cache >> __bits;
      __bits_left -= __bits;
      if (__bits_left < 32)
        {
          __cache |= ((uint64_t(_M_mt())) << __bits_left);
          __bits_left += 32;
        }
      return __res;
    }
};

} // namespace __gnu_parallel

#endif /* _GLIBCXX_PARALLEL_RANDOM_NUMBER_H */
