/* AVR ELF support for BFD.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef _ELF_AVR_H
#define _ELF_AVR_H

#include "elf/reloc-macros.h"

/* Processor specific flags for the ELF header e_flags field.  */
#define EF_AVR_MACH 0x7F

/* If bit #7 is set, it is assumed that the elf file uses local symbols
   as reference for the relocations so that linker relaxation is possible.  */
#define EF_AVR_LINKRELAX_PREPARED 0x80

#define E_AVR_MACH_AVR1     1
#define E_AVR_MACH_AVR2     2
#define E_AVR_MACH_AVR25   25
#define E_AVR_MACH_AVR3     3
#define E_AVR_MACH_AVR31   31
#define E_AVR_MACH_AVR35   35
#define E_AVR_MACH_AVR4     4
#define E_AVR_MACH_AVR5     5
#define E_AVR_MACH_AVR51   51
#define E_AVR_MACH_AVR6     6 
#define E_AVR_MACH_AVRTINY 100
#define E_AVR_MACH_XMEGA1  101
#define E_AVR_MACH_XMEGA2  102
#define E_AVR_MACH_XMEGA3  103
#define E_AVR_MACH_XMEGA4  104
#define E_AVR_MACH_XMEGA5  105
#define E_AVR_MACH_XMEGA6  106
#define E_AVR_MACH_XMEGA7  107

/* Relocations.  */
START_RELOC_NUMBERS (elf_avr_reloc_type)
     RELOC_NUMBER (R_AVR_NONE,			0)
     RELOC_NUMBER (R_AVR_32,			1)
     RELOC_NUMBER (R_AVR_7_PCREL,		2)
     RELOC_NUMBER (R_AVR_13_PCREL,		3)
     RELOC_NUMBER (R_AVR_16, 			4)
     RELOC_NUMBER (R_AVR_16_PM, 		5)
     RELOC_NUMBER (R_AVR_LO8_LDI,		6)
     RELOC_NUMBER (R_AVR_HI8_LDI,		7)
     RELOC_NUMBER (R_AVR_HH8_LDI,		8)
     RELOC_NUMBER (R_AVR_LO8_LDI_NEG,		9)
     RELOC_NUMBER (R_AVR_HI8_LDI_NEG,	       10)
     RELOC_NUMBER (R_AVR_HH8_LDI_NEG,	       11)
     RELOC_NUMBER (R_AVR_LO8_LDI_PM,	       12)
     RELOC_NUMBER (R_AVR_HI8_LDI_PM,	       13)
     RELOC_NUMBER (R_AVR_HH8_LDI_PM,	       14)
     RELOC_NUMBER (R_AVR_LO8_LDI_PM_NEG,       15)
     RELOC_NUMBER (R_AVR_HI8_LDI_PM_NEG,       16)
     RELOC_NUMBER (R_AVR_HH8_LDI_PM_NEG,       17)
     RELOC_NUMBER (R_AVR_CALL,		       18)
     RELOC_NUMBER (R_AVR_LDI,                  19)
     RELOC_NUMBER (R_AVR_6,                    20)
     RELOC_NUMBER (R_AVR_6_ADIW,               21)
     RELOC_NUMBER (R_AVR_MS8_LDI,              22)
     RELOC_NUMBER (R_AVR_MS8_LDI_NEG,          23)
     RELOC_NUMBER (R_AVR_LO8_LDI_GS,	       24)
     RELOC_NUMBER (R_AVR_HI8_LDI_GS,	       25)
     RELOC_NUMBER (R_AVR_8, 		       26)
     RELOC_NUMBER (R_AVR_8_LO8,                27)
     RELOC_NUMBER (R_AVR_8_HI8,                28)
     RELOC_NUMBER (R_AVR_8_HLO8,               29)
     RELOC_NUMBER (R_AVR_DIFF8,                30)
     RELOC_NUMBER (R_AVR_DIFF16,               31)
     RELOC_NUMBER (R_AVR_DIFF32,               32)
     RELOC_NUMBER (R_AVR_LDS_STS_16,           33)
     RELOC_NUMBER (R_AVR_PORT6,                34)
     RELOC_NUMBER (R_AVR_PORT5,                35)
     RELOC_NUMBER (R_AVR_32_PCREL,             36)
END_RELOC_NUMBERS (R_AVR_max)

#endif /* _ELF_AVR_H */
