/* Lattice Mico32 ELF support for BFD.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef _ELF_LM32_H
#define _ELF_LM32_H

#include "elf/reloc-macros.h"

/* Relocations.  */
START_RELOC_NUMBERS (elf_lm32_reloc_type)
     RELOC_NUMBER (R_LM32_NONE,                      0)
     RELOC_NUMBER (R_LM32_8,                         1)
     RELOC_NUMBER (R_LM32_16,                        2)
     RELOC_NUMBER (R_LM32_32,                        3)
     RELOC_NUMBER (R_LM32_HI16,                      4)
     RELOC_NUMBER (R_LM32_LO16,                      5)
     RELOC_NUMBER (R_LM32_GPREL16,                   6)
     RELOC_NUMBER (R_LM32_CALL,                      7)
     RELOC_NUMBER (R_LM32_BRANCH,                    8)
     RELOC_NUMBER (R_LM32_GNU_VTINHERIT,             9)
     RELOC_NUMBER (R_LM32_GNU_VTENTRY,               10)
     RELOC_NUMBER (R_LM32_16_GOT,                    11)
     RELOC_NUMBER (R_LM32_GOTOFF_HI16,               12)
     RELOC_NUMBER (R_LM32_GOTOFF_LO16,               13)
     RELOC_NUMBER (R_LM32_COPY,                      14)
     RELOC_NUMBER (R_LM32_GLOB_DAT,                  15)
     RELOC_NUMBER (R_LM32_JMP_SLOT,                  16)
     RELOC_NUMBER (R_LM32_RELATIVE,                  17)
END_RELOC_NUMBERS (R_LM32_max)

/* Processor specific flags for the ELF header e_flags field.  */

#define EF_LM32_MACH                 0x00000001

/* Various CPU types.  */

#define E_LM32_MACH                  0x1

#endif /* _ELF_LM32_H */
