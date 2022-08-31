/* MN10200 ELF support for BFD.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* This file holds definitions specific to the MN10200 ELF ABI.  */

#ifndef _ELF_MN10200_H
#define _ELF_MN10200_H

#include "elf/reloc-macros.h"

/* Relocations.  */
START_RELOC_NUMBERS (elf_mn10200_reloc_type)
  RELOC_NUMBER (R_MN10200_NONE, 0)
  RELOC_NUMBER (R_MN10200_32, 1)
  RELOC_NUMBER (R_MN10200_16, 2)
  RELOC_NUMBER (R_MN10200_8, 3)
  RELOC_NUMBER (R_MN10200_24, 4)
  RELOC_NUMBER (R_MN10200_PCREL8, 5)
  RELOC_NUMBER (R_MN10200_PCREL16, 6)
  RELOC_NUMBER (R_MN10200_PCREL24, 7)
END_RELOC_NUMBERS (R_MN10200_max)

#endif /* _ELF_MN10200_H */
