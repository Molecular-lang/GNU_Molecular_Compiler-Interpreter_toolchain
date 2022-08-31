/* This file defines the interface between the d10v simulator and gdb.

   Please review: $(src-dir)/SPL-README for Licencing info. */

#if !defined (SIM_D10V_H)
#define SIM_D10V_H

/* GDB interprets addresses as:

   0x00xxxxxx: Physical unified memory segment     (Unified memory)
   0x01xxxxxx: Physical instruction memory segment (On-chip insn memory)
   0x02xxxxxx: Physical data memory segment        (On-chip data memory)
   0x10xxxxxx: Logical data address segment        (DMAP translated memory)
   0x11xxxxxx: Logical instruction address segment (IMAP translated memory)

   The remote d10v board interprets addresses as:

   0x00xxxxxx: Physical unified memory segment     (Unified memory)
   0x01xxxxxx: Physical instruction memory segment (On-chip insn memory)
   0x02xxxxxx: Physical data memory segment        (On-chip data memory)

   The following translate a virtual DMAP/IMAP offset into a physical
   memory segment assigning the translated address to PHYS.  Since a
   memory access may cross a page boundrary the number of bytes for
   which the translation is applicable (or 0 for an invalid virtual
   offset) is returned. */

enum
  {
    SIM_D10V_MEMORY_UNIFIED = 0x00000000,
    SIM_D10V_MEMORY_INSN = 0x01000000,
    SIM_D10V_MEMORY_DATA = 0x02000000,
    SIM_D10V_MEMORY_DMAP = 0x10000000,
    SIM_D10V_MEMORY_IMAP = 0x11000000
  };

/* The simulator makes use of the following register information. */

enum sim_d10v_regs
{
  SIM_D10V_R0_REGNUM,
  SIM_D10V_R1_REGNUM,
  SIM_D10V_R2_REGNUM,
  SIM_D10V_R3_REGNUM,
  SIM_D10V_R4_REGNUM,
  SIM_D10V_R5_REGNUM,
  SIM_D10V_R6_REGNUM,
  SIM_D10V_R7_REGNUM,
  SIM_D10V_R8_REGNUM,
  SIM_D10V_R9_REGNUM,
  SIM_D10V_R10_REGNUM,
  SIM_D10V_R11_REGNUM,
  SIM_D10V_R12_REGNUM,
  SIM_D10V_R13_REGNUM,
  SIM_D10V_R14_REGNUM,
  SIM_D10V_R15_REGNUM,
  SIM_D10V_CR0_REGNUM,
  SIM_D10V_CR1_REGNUM,
  SIM_D10V_CR2_REGNUM,
  SIM_D10V_CR3_REGNUM,
  SIM_D10V_CR4_REGNUM,
  SIM_D10V_CR5_REGNUM,
  SIM_D10V_CR6_REGNUM,
  SIM_D10V_CR7_REGNUM,
  SIM_D10V_CR8_REGNUM,
  SIM_D10V_CR9_REGNUM,
  SIM_D10V_CR10_REGNUM,
  SIM_D10V_CR11_REGNUM,
  SIM_D10V_CR12_REGNUM,
  SIM_D10V_CR13_REGNUM,
  SIM_D10V_CR14_REGNUM,
  SIM_D10V_CR15_REGNUM,
  SIM_D10V_A0_REGNUM,
  SIM_D10V_A1_REGNUM,
  SIM_D10V_SPI_REGNUM,
  SIM_D10V_SPU_REGNUM,
  SIM_D10V_IMAP0_REGNUM,
  SIM_D10V_IMAP1_REGNUM,
  SIM_D10V_DMAP0_REGNUM,
  SIM_D10V_DMAP1_REGNUM,
  SIM_D10V_DMAP2_REGNUM,
  SIM_D10V_DMAP3_REGNUM,
  SIM_D10V_TS2_DMAP_REGNUM
};
  
enum
{
  SIM_D10V_NR_R_REGS = 16,
  SIM_D10V_NR_A_REGS = 2,
  SIM_D10V_NR_IMAP_REGS = 2,
  SIM_D10V_NR_DMAP_REGS = 4,
  SIM_D10V_NR_CR_REGS = 16
};

#endif
