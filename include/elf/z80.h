/* Z80 ELF support for BFD.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef _ELF_Z80_H
#define _ELF_Z80_H

#include "elf/reloc-macros.h"

/* Processor specific flags for the ELF header e_flags field.  */
#define EF_Z80_MACH_Z80      0x01
#define EF_Z80_MACH_Z180     0x02
#define EF_Z80_MACH_R800     0x03
#define EF_Z80_MACH_EZ80_Z80 0x04
#define EF_Z80_MACH_EZ80_ADL 0x84
#define EF_Z80_MACH_GBZ80    0x05
#define EF_Z80_MACH_Z80N     0x06
#define EF_Z80_MACH_MSK      0xff

/* Relocations.  */
START_RELOC_NUMBERS (elf_z80_reloc_type)
     RELOC_NUMBER (R_Z80_NONE,		0)
     RELOC_NUMBER (R_Z80_8, 		1)
     RELOC_NUMBER (R_Z80_8_DIS,		2)
     RELOC_NUMBER (R_Z80_8_PCREL,	3)
     RELOC_NUMBER (R_Z80_16, 		4)
     RELOC_NUMBER (R_Z80_24, 		5)
     RELOC_NUMBER (R_Z80_32, 		6)
     RELOC_NUMBER (R_Z80_BYTE0,		7)
     RELOC_NUMBER (R_Z80_BYTE1,		8)
     RELOC_NUMBER (R_Z80_BYTE2,		9)
     RELOC_NUMBER (R_Z80_BYTE3,		10)
     RELOC_NUMBER (R_Z80_WORD0,		11)
     RELOC_NUMBER (R_Z80_WORD1,		12)
     RELOC_NUMBER (R_Z80_16_BE,		13)
END_RELOC_NUMBERS (R_Z80_max)

#endif /* _ELF_Z80_H */
