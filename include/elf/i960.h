/* Intel 960 ELF support for BFD. */

#ifndef _ELF_I960_H
#define _ELF_I960_H

#include "elf/reloc-macros.h"


START_RELOC_NUMBERS (elf_i960_reloc_type)
     RELOC_NUMBER (R_960_NONE,	    0)
     RELOC_NUMBER (R_960_12,	    1)
     RELOC_NUMBER (R_960_32,	    2)
     RELOC_NUMBER (R_960_IP24,	    3)
     RELOC_NUMBER (R_960_SUB,	    4)
     RELOC_NUMBER (R_960_OPTCALL,   5)
     RELOC_NUMBER (R_960_OPTCALLX,  6)
     RELOC_NUMBER (R_960_OPTCALLXA, 7)
END_RELOC_NUMBERS (R_960_max)

#endif /* _ELF_I960_H */
