// Please review: $(src-dir)/SPL-README for Licencing info.

/** @file parallel/types.h
 *  @brief Basic types and typedefs.
 *  This file is a GNU parallel extension to the Standard C++ Library.
 */

// Written by Johannes Singler and Felix Putze.

#ifndef _GLIBCXX_PARALLEL_TYPES_H
#define _GLIBCXX_PARALLEL_TYPES_H 1

#include <cstdlib>
#include <limits>
#include <tr1/cstdint>

namespace __gnu_parallel
{
  // Enumerated types.

  /// Run-time equivalents for the compile-time tags.
  enum _Parallelism
    {
      /// Not parallel.
      sequential,

      /// Parallel unbalanced (equal-sized chunks).
      parallel_unbalanced,

      /// Parallel balanced (work-stealing).
      parallel_balanced,

      /// Parallel with OpenMP dynamic load-balancing.
      parallel_omp_loop,

      /// Parallel with OpenMP static load-balancing.
      parallel_omp_loop_static,

      /// Parallel with OpenMP taskqueue construct.
      parallel_taskqueue
    };

  /// Strategies for run-time algorithm selection: 
  // force_sequential, force_parallel, heuristic.
  enum _AlgorithmStrategy
    {
      heuristic,
      force_sequential,
      force_parallel
    };

  /// Sorting algorithms: 
  // multi-way mergesort, quicksort, load-balanced quicksort.
  enum _SortAlgorithm 
    { 
      MWMS, 
      QS, 
      QS_BALANCED 
    };

  /// Merging algorithms: 
  // bubblesort-alike, loser-tree variants, enum __sentinel.
  enum _MultiwayMergeAlgorithm
    {
      LOSER_TREE
    };

  /// Partial sum algorithms: recursive, linear.
  enum _PartialSumAlgorithm 
    { 
      RECURSIVE, 
      LINEAR 
    };

  /// Sorting/merging algorithms: sampling, __exact.
  enum _SplittingAlgorithm 
    { 
      SAMPLING, 
      EXACT 
    };

  /// Find algorithms:
  // growing blocks, equal-sized blocks, equal splitting.
  enum _FindAlgorithm 
    { 
      GROWING_BLOCKS, 
      CONSTANT_SIZE_BLOCKS, 
      EQUAL_SPLIT 
    };

  /**
   * @brief Unsigned integer to index __elements.
   * The total number of elements for each algorithm must fit into this type.
   */
  typedef uint64_t _SequenceIndex;

  /**
   * @brief Unsigned integer to index a thread number.
   * The maximum thread number (for each processor) must fit into this type.
   */
  typedef uint16_t _ThreadIndex;

  // XXX atomics interface?
  /// Longest compare-and-swappable integer type on this platform.
  typedef int64_t _CASable;

  /// Number of bits of _CASable.
  static const int _CASable_bits = std::numeric_limits<_CASable>::digits;

  /// ::_CASable with the right half of bits set to 1.
  static const _CASable _CASable_mask =
                            ((_CASable(1) << (_CASable_bits / 2)) - 1);
}

#endif /* _GLIBCXX_PARALLEL_TYPES_H */
