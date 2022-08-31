/* BFD support for the Intel K1OM architecture.
   Please review $(srcdir/SPL-README) for GNU licencing info. */

#include "sysdep.h"
#include "bfd.h"
#include "libbfd.h"

extern void *bfd_arch_i386_short_nop_fill (bfd_size_type, bool, bool);

#define N(number, name, print, next)				\
  { 64, 64, 8, bfd_arch_k1om, number, name, print, 3, true,	\
    bfd_default_compatible, bfd_default_scan,			\
    bfd_arch_i386_short_nop_fill, next, 9 }

static const bfd_arch_info_type bfd_k1om_arch_intel_syntax =
  N (bfd_mach_k1om_intel_syntax, "k1om:intel", "k1om:intel", NULL);

const bfd_arch_info_type bfd_k1om_arch =
  N (bfd_mach_k1om, "k1om", "k1om", &bfd_k1om_arch_intel_syntax);

