/* moxie ELF support for BFD. */

#ifndef _ELF_MOXIE_H
#define _ELF_MOXIE_H

#include "elf/reloc-macros.h"

/* Relocation types.  */
START_RELOC_NUMBERS (elf_moxie_reloc_type)
  RELOC_NUMBER (R_MOXIE_NONE, 0)
  RELOC_NUMBER (R_MOXIE_32, 1)
  RELOC_NUMBER (R_MOXIE_PCREL10, 2)
END_RELOC_NUMBERS (R_MOXIE_max)

#endif /* _ELF_MOXIE_H */
