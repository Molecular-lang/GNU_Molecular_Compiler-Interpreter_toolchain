/* Header file for misc range functions. -*- C++ -*-
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_RANGE_H
#define GCC_RANGE_H

value_range range_zero (tree type);
value_range range_nonzero (tree type);
value_range range_positives (tree type);
value_range range_negatives (tree type);

// Return an irange instance that is a boolean TRUE.

static inline int_range<1>
range_true (tree type)
{
  unsigned prec = TYPE_PRECISION (type);
  return int_range<1> (type, wi::one (prec), wi::one (prec));
}

// Return an irange instance that is a boolean FALSE.

static inline int_range<1>
range_false (tree type)
{
  unsigned prec = TYPE_PRECISION (type);
  return int_range<1> (type, wi::zero (prec), wi::zero (prec));
}

// Return an irange that covers both true and false.

static inline int_range<1>
range_true_and_false (tree type)
{
  unsigned prec = TYPE_PRECISION (type);
  return int_range<1> (type, wi::zero (prec), wi::one (prec));
}

#endif // GCC_RANGE_H
