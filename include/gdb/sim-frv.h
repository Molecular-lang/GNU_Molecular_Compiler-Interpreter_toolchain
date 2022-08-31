/* This file defines the interface between the FR-V simulator and GDB.

   Please review: $(src-dir)/SPL-README for Licencing info. */

#if !defined (SIM_FRV_H)
#define SIM_FRV_H

enum sim_frv_regs
{
  SIM_FRV_GR0_REGNUM  = 0,
  SIM_FRV_GR63_REGNUM = 63,
  SIM_FRV_FR0_REGNUM  = 64,
  SIM_FRV_FR63_REGNUM = 127,
  SIM_FRV_PC_REGNUM   = 128,

  /* An FR-V architecture may have up to 4096 special purpose registers
     (SPRs).  In order to determine a specific constant used to access
     a particular SPR, one of the H_SPR_ prefixed offsets defined in
     opcodes/frv-desc.h should be added to SIM_FRV_SPR0_REGNUM.  So,
     for example, the number that GDB uses to fetch the link register
     from the simulator is (SIM_FRV_SPR0_REGNUM + H_SPR_LR).  */
  SIM_FRV_SPR0_REGNUM = 129,
  SIM_FRV_SPR4095_REGNUM = SIM_FRV_SPR0_REGNUM + 4095
};

#endif
