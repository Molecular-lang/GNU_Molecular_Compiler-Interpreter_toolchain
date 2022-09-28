// Please review: $(src-dir)/SPL-README for Licencing info.

/** @file parallel/compiletime_settings.h
 *  @brief Defines on options concerning debugging and performance, at
 *  compile-time.
 *  This file is a GNU parallel extension to the Standard C++ Library.
 */

// Written by Johannes Singler.

#include <cstdio>

/** @brief Determine verbosity level of the parallel mode.
 *  Level 1 prints a message each time a parallel-mode function is entered. */
#define _GLIBCXX_VERBOSE_LEVEL 0

/** @def _GLIBCXX_CALL
 *  @brief Macro to produce log message when entering a function.
 *  @param __n Input size.
 *  @see _GLIBCXX_VERBOSE_LEVEL */
#if (_GLIBCXX_VERBOSE_LEVEL == 0)
#define _GLIBCXX_CALL(__n)
#endif
#if (_GLIBCXX_VERBOSE_LEVEL == 1)
#define _GLIBCXX_CALL(__n) \
  printf("   %__s:\niam = %d, __n = %ld, __num_threads = %d\n", \
  __PRETTY_FUNCTION__, omp_get_thread_num(), (__n), __get_max_threads());
#endif

#ifndef _GLIBCXX_SCALE_DOWN_FPU
/** @brief Use floating-point scaling instead of modulo for mapping
 *  random numbers to a range.  This can be faster on certain CPUs. */
#define _GLIBCXX_SCALE_DOWN_FPU 0
#endif

#ifndef _GLIBCXX_PARALLEL_ASSERTIONS
/** @brief Switch on many _GLIBCXX_PARALLEL_ASSERTions in parallel code.
 *  Should be switched on only locally. */
#define _GLIBCXX_PARALLEL_ASSERTIONS (_GLIBCXX_ASSERTIONS+0)
#endif

#ifndef _GLIBCXX_RANDOM_SHUFFLE_CONSIDER_L1
/** @brief Switch on many _GLIBCXX_PARALLEL_ASSERTions in parallel code.
 *  Consider the size of the L1 cache for
*  gnu_parallel::__parallel_random_shuffle(). */
#define _GLIBCXX_RANDOM_SHUFFLE_CONSIDER_L1 0
#endif
#ifndef _GLIBCXX_RANDOM_SHUFFLE_CONSIDER_TLB
/** @brief Switch on many _GLIBCXX_PARALLEL_ASSERTions in parallel code.
 *  Consider the size of the TLB for
*  gnu_parallel::__parallel_random_shuffle(). */
#define _GLIBCXX_RANDOM_SHUFFLE_CONSIDER_TLB 0
#endif
