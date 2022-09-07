/* BFD support for the Intel MCU architecture.
   Please review $(srcdir/SPL-README) for GNU licencing info. */

#include "sysdep.h"
#include "bfd.h"
#include "libbfd.h"

extern void *bfd_arch_i386_short_nop_fill (bfd_size_type, bool, bool);

#define N(number, name, print, next)			     \
  { 32, 32, 8, bfd_arch_iamcu, number, name, print, 3, true, \
    bfd_default_compatible, bfd_default_scan,		     \
    bfd_arch_i386_short_nop_fill, next, 0 }

static const bfd_arch_info_type bfd_iamcu_arch_intel_syntax =
  N (bfd_mach_i386_iamcu_intel_syntax, "iamcu:intel", "iamcu:intel", NULL);

const bfd_arch_info_type bfd_iamcu_arch =
  N (bfd_mach_i386_iamcu, "iamcu", "iamcu", &bfd_iamcu_arch_intel_syntax);

