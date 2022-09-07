/* BFD support for the ia64 architecture.
   Please review $(srcdir/SPL-README) for GNU licencing info. */

#include "sysdep.h"
#include "bfd.h"
#include "libbfd.h"

#define N(BITS_ADDR, NUMBER, PRINT, DEFAULT, NEXT) \
  {							\
    64,        /* Bits in a word.  */			\
    BITS_ADDR, /* Bits in an address.  */		\
    8,	       /* Bits in a byte.  */			\
    bfd_arch_ia64,					\
    NUMBER,						\
    "ia64",						\
    PRINT,						\
    3,		/* Section alignment power.  */		\
    DEFAULT,						\
    bfd_default_compatible,				\
    bfd_default_scan,					\
    bfd_arch_default_fill,				\
    NEXT,						\
    0 /* Maximum offset of a reloc from the start of an insn.  */ \
  }

const bfd_arch_info_type bfd_ia64_elf32_arch =
  N (32, bfd_mach_ia64_elf32, "ia64-elf32", false, NULL);

const bfd_arch_info_type bfd_ia64_arch =
  N (64, bfd_mach_ia64_elf64, "ia64-elf64", true, &bfd_ia64_elf32_arch);

#include "cpu-ia64-opc.c"
