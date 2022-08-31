/* BFD support for the Intel L1OM architecture.
   Please review $(srcdir/SPL-README) for GNU licencing info. */

#include "sysdep.h"
#include "bfd.h"
#include "libbfd.h"

extern void *bfd_arch_i386_short_nop_fill (bfd_size_type, bool, bool);

#define N(number, name, print, next)				\
  { 64, 64, 8, bfd_arch_l1om, number, name, print, 3, true,	\
    bfd_default_compatible, bfd_default_scan,			\
    bfd_arch_i386_short_nop_fill, next, 0 }

static const bfd_arch_info_type bfd_l1om_arch_intel_syntax =
  N (bfd_mach_l1om_intel_syntax, "l1om:intel", "l1om:intel", NULL);

const bfd_arch_info_type bfd_l1om_arch =
  N (bfd_mach_l1om, "l1om", "l1om", &bfd_l1om_arch_intel_syntax);
