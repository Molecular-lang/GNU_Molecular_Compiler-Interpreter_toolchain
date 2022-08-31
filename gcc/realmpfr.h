/* Definitions of floating-point conversion from compiler
   internal format to MPFR.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_REALGMP_H
#define GCC_REALGMP_H

#include <mpfr.h>
#include <mpc.h>

/* Convert between MPFR and REAL_VALUE_TYPE.  The caller is
   responsible for initializing and clearing the MPFR parameter.  */

extern void real_from_mpfr (REAL_VALUE_TYPE *, mpfr_srcptr, tree, mpfr_rnd_t);
extern void real_from_mpfr (REAL_VALUE_TYPE *, mpfr_srcptr, const real_format *, mpfr_rnd_t);
extern void mpfr_from_real (mpfr_ptr, const REAL_VALUE_TYPE *, mpfr_rnd_t);

#endif /* ! GCC_REALGMP_H */
