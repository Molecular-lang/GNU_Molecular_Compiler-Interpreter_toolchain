/* ELF support for BFD for the WebAssembly target */

#ifndef _ELF_WASM32_H
#define _ELF_WASM32_H

#include "elf/reloc-macros.h"

/* Relocation types.  */

START_RELOC_NUMBERS (elf_wasm32_reloc_type)
  RELOC_NUMBER (R_WASM32_NONE,            	  0)
  RELOC_NUMBER (R_WASM32_32,           	  	  1)
END_RELOC_NUMBERS (R_WASM32_max = 1)

#endif /* _ELF_WASM32_H */
