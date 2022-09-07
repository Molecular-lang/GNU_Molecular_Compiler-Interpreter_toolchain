/* Infineon XC16X ELF support for BFD.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef _ELF_XC16X_H
#define _ELF_XC16X_H

#include "elf/reloc-macros.h"

/* Relocations.  */
START_RELOC_NUMBERS (elf_xc16x_reloc_type)
  RELOC_NUMBER (R_XC16X_NONE, 0)
  RELOC_NUMBER (R_XC16X_ABS_8, 1)
  RELOC_NUMBER (R_XC16X_ABS_16, 2)
  RELOC_NUMBER (R_XC16X_ABS_32, 3)
  RELOC_NUMBER (R_XC16X_8_PCREL, 4)
  RELOC_NUMBER (R_XC16X_PAG, 5)
  RELOC_NUMBER (R_XC16X_POF, 6)
  RELOC_NUMBER (R_XC16X_SEG, 7)
  RELOC_NUMBER (R_XC16X_SOF, 8)

END_RELOC_NUMBERS (R_XC16X_max)

#endif /* _ELF_XC16X_H */
