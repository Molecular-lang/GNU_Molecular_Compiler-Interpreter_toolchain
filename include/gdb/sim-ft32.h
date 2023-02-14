/* This file defines the interface between the FT32 simulator and GDB. */

/* Register numbers of various important registers.  */
enum ft32_regnum {
  FT32_FP_REGNUM,               /* Address of executing stack frame.  */
  FT32_SP_REGNUM,               /* Address of top of stack.  */
  FT32_R0_REGNUM,
  FT32_R1_REGNUM,
  FT32_CC_REGNUM = 31,
  FT32_PC_REGNUM = 32           /* Program counter.  */
};

/* Number of machine registers.  */
#define FT32_NUM_REGS 33        /* 32 real registers + PC */

