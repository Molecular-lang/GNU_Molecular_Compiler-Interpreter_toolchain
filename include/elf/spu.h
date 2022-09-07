/* SPU ELF support for BFD.

   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef _ELF_SPU_H
#define _ELF_SPU_H

#include "elf/reloc-macros.h"

/* elf32-spu.c depends on these being consecutive. */
START_RELOC_NUMBERS (elf_spu_reloc_type)
     RELOC_NUMBER (R_SPU_NONE,		 0)
     RELOC_NUMBER (R_SPU_ADDR10,	 1)
     RELOC_NUMBER (R_SPU_ADDR16,	 2)
     RELOC_NUMBER (R_SPU_ADDR16_HI,	 3)
     RELOC_NUMBER (R_SPU_ADDR16_LO,	 4)
     RELOC_NUMBER (R_SPU_ADDR18,	 5)
     RELOC_NUMBER (R_SPU_ADDR32,	 6)
     RELOC_NUMBER (R_SPU_REL16,		 7)
     RELOC_NUMBER (R_SPU_ADDR7,		 8)
     RELOC_NUMBER (R_SPU_REL9,		 9)
     RELOC_NUMBER (R_SPU_REL9I,		10)
     RELOC_NUMBER (R_SPU_ADDR10I,	11)
     RELOC_NUMBER (R_SPU_ADDR16I,	12)
     RELOC_NUMBER (R_SPU_REL32,		13)
     RELOC_NUMBER (R_SPU_ADDR16X,	14)
     RELOC_NUMBER (R_SPU_PPU32,		15)
     RELOC_NUMBER (R_SPU_PPU64,		16)
     RELOC_NUMBER (R_SPU_ADD_PIC,	17)
END_RELOC_NUMBERS (R_SPU_max)

/* Program header extensions */

/* Mark a PT_LOAD segment as containing an overlay which should not
   initially be loaded.  */
#define PF_OVERLAY		(1 << 27)

/* SPU Dynamic Object Information.  */
#define PT_SPU_INFO             0x70000000

/* SPU plugin information */
#define SPU_PLUGIN_NAME         "SPUNAME"
#define SPU_PTNOTE_SPUNAME	".note.spu_name"

#endif /* _ELF_SPU_H */
