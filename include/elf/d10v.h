/* d10v ELF support for BFD.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef _ELF_D10V_H
#define _ELF_D10V_H

#include "elf/reloc-macros.h"

/* Relocation types.  */
START_RELOC_NUMBERS (elf_d10v_reloc_type)
  RELOC_NUMBER (R_D10V_NONE, 0)
  RELOC_NUMBER (R_D10V_10_PCREL_R, 1)
  RELOC_NUMBER (R_D10V_10_PCREL_L, 2)
  RELOC_NUMBER (R_D10V_16, 3)
  RELOC_NUMBER (R_D10V_18, 4)
  RELOC_NUMBER (R_D10V_18_PCREL, 5)
  RELOC_NUMBER (R_D10V_32, 6)
  RELOC_NUMBER (R_D10V_GNU_VTINHERIT, 7)
  RELOC_NUMBER (R_D10V_GNU_VTENTRY, 8)
END_RELOC_NUMBERS (R_D10V_max)

#endif
