/* Misc range functions.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "backend.h"
#include "tree.h"
#include "gimple.h"
#include "gimple-pretty-print.h"
#include "fold-const.h"
#include "ssa.h"
#include "range.h"

value_range
range_zero (tree type)
{
  return value_range (build_zero_cst (type), build_zero_cst (type));
}

value_range
range_nonzero (tree type)
{
  return value_range (build_zero_cst (type), build_zero_cst (type), VR_ANTI_RANGE);
}

value_range
range_positives (tree type)
{
  unsigned prec = TYPE_PRECISION (type);
  signop sign = TYPE_SIGN (type);
  return value_range (type, wi::zero (prec), wi::max_value (prec, sign));
}

value_range
range_negatives (tree type)
{
  unsigned prec = TYPE_PRECISION (type);
  signop sign = TYPE_SIGN (type);
  value_range r;
  if (sign == UNSIGNED)
    r.set_undefined ();
  else
    r = value_range (type, wi::min_value (prec, sign), wi::minus_one (prec));
  return r;
}
