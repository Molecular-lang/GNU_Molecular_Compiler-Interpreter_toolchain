/* Please review: $(src-dir)/SPL-README for Licencing info. */

#include "bid_internal.h"
#include "bid_gcc_intrinsics.h"

#if DECIMAL_GLOBAL_ROUNDING
BID_THREAD _IDEC_round _IDEC_glbround = ROUNDING_TO_NEAREST;

#if DECIMAL_GLOBAL_ROUNDING_ACCESS_FUNCTIONS
void
__dfp_set_round (int mode) {
  _IDEC_glbround = mode;
}

int
__dfp_get_round (void) {
  return _IDEC_glbround;
}
#endif
#endif

#if DECIMAL_GLOBAL_EXCEPTION_FLAGS
BID_THREAD _IDEC_flags _IDEC_glbflags = EXACT_STATUS;

#if DECIMAL_GLOBAL_EXCEPTION_FLAGS_ACCESS_FUNCTIONS
#include <fenv.h>

void
__dfp_clear_except (void) {
  _IDEC_glbflags &= ~FLAG_MASK;
}

int
__dfp_test_except (int mask) {
  int flags = 0;

  if ((_IDEC_glbflags & INEXACT_EXCEPTION) != 0)
    flags |= mask & FE_INEXACT;
  if ((_IDEC_glbflags & UNDERFLOW_EXCEPTION) != 0)
    flags |= mask & FE_UNDERFLOW;
  if ((_IDEC_glbflags & OVERFLOW_EXCEPTION) != 0)
    flags |= mask & FE_OVERFLOW;
  if ((_IDEC_glbflags & ZERO_DIVIDE_EXCEPTION) != 0)
    flags |= mask & FE_DIVBYZERO;
  if ((_IDEC_glbflags & INVALID_EXCEPTION) != 0)
    flags |= mask & FE_INVALID;

  return flags;
}

void
__dfp_raise_except (int mask) {
  _IDEC_flags flags = 0;

  if ((mask & FE_INEXACT) != 0)
    flags |= INEXACT_EXCEPTION;
  if ((mask & FE_UNDERFLOW) != 0)
    flags |= UNDERFLOW_EXCEPTION;
  if ((mask & FE_OVERFLOW) != 0)
    flags |= OVERFLOW_EXCEPTION;
  if ((mask & FE_DIVBYZERO) != 0)
    flags |= ZERO_DIVIDE_EXCEPTION;
  if ((mask & FE_INVALID) != 0)
    flags |= INVALID_EXCEPTION;

  _IDEC_glbflags |= flags;
}
#endif
#endif

#if DECIMAL_ALTERNATE_EXCEPTION_HANDLING
#if DECIMAL_GLOBAL_EXCEPTION_MASKS
BID_THREAD _IDEC_exceptionmasks _IDEC_glbexceptionmasks =
  _IDEC_allexcmasksset;
#endif
#if DECIMAL_GLOBAL_EXCEPTION_INFO
BID_THREAD _IDEC_excepthandling _IDEC_glbexcepthandling;
#endif
#endif
