/* DLX support for BFD. */

#ifndef _ELF_DLX_H
#define _ELF_DLX_H

#include "elf/reloc-macros.h"

#ifdef __cplusplus
extern "C" {
#endif

#if 0
START_RELOC_NUMBERS (elf_dlx_reloc_type)
     RELOC_NUMBER (R_DLX_NONE,            0)
     RELOC_NUMBER (R_DLX_RELOC_16,        1)
     RELOC_NUMBER (R_DLX_RELOC_26,        2)
     RELOC_NUMBER (R_DLX_RELOC_32,        3)
     RELOC_NUMBER (R_DLX_GNU_VTINHERIT,   4)
     RELOC_NUMBER (R_DLX_GNU_VTENTRY,     5)
     RELOC_NUMBER (R_DLX_RELOC_16_HI,     6)
     RELOC_NUMBER (R_DLX_RELOC_16_LO,     7)
     RELOC_NUMBER (R_DLX_RELOC_16_PCREL,  8)
     RELOC_NUMBER (R_DLX_RELOC_26_PCREL,  9)
END_RELOC_NUMBERS (R_DLX_max)
#else
START_RELOC_NUMBERS (elf_dlx_reloc_type)
     RELOC_NUMBER (R_DLX_NONE,            0)
     RELOC_NUMBER (R_DLX_RELOC_8,         1)
     RELOC_NUMBER (R_DLX_RELOC_16,        2)
     RELOC_NUMBER (R_DLX_RELOC_32,        3)
     RELOC_NUMBER (R_DLX_GNU_VTINHERIT,   4)
     RELOC_NUMBER (R_DLX_GNU_VTENTRY,     5)
     RELOC_NUMBER (R_DLX_RELOC_16_HI,     6)
     RELOC_NUMBER (R_DLX_RELOC_16_LO,     7)
     RELOC_NUMBER (R_DLX_RELOC_16_PCREL,  8)
     RELOC_NUMBER (R_DLX_RELOC_26_PCREL,  9)
END_RELOC_NUMBERS (R_DLX_max)
#endif /* 0 */

#ifdef __cplusplus
     }
#endif

#endif /* _ELF_DLX_H */
