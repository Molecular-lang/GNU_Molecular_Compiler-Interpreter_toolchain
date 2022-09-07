/* sim-rx.h --- interface between rl78 simulator and GDB.

   Please review: $(src-dir)/SPL-README for Licencing info. */

#if !defined (SIM_RL78_H)
#define SIM_RL78_H

enum sim_rl78_regnum
{
  sim_rl78_bank0_r0_regnum,
  sim_rl78_bank0_r1_regnum,
  sim_rl78_bank0_r2_regnum,
  sim_rl78_bank0_r3_regnum,
  sim_rl78_bank0_r4_regnum,
  sim_rl78_bank0_r5_regnum,
  sim_rl78_bank0_r6_regnum,
  sim_rl78_bank0_r7_regnum,

  sim_rl78_bank1_r0_regnum,
  sim_rl78_bank1_r1_regnum,
  sim_rl78_bank1_r2_regnum,
  sim_rl78_bank1_r3_regnum,
  sim_rl78_bank1_r4_regnum,
  sim_rl78_bank1_r5_regnum,
  sim_rl78_bank1_r6_regnum,
  sim_rl78_bank1_r7_regnum,

  sim_rl78_bank2_r0_regnum,
  sim_rl78_bank2_r1_regnum,
  sim_rl78_bank2_r2_regnum,
  sim_rl78_bank2_r3_regnum,
  sim_rl78_bank2_r4_regnum,
  sim_rl78_bank2_r5_regnum,
  sim_rl78_bank2_r6_regnum,
  sim_rl78_bank2_r7_regnum,

  sim_rl78_bank3_r0_regnum,
  sim_rl78_bank3_r1_regnum,
  sim_rl78_bank3_r2_regnum,
  sim_rl78_bank3_r3_regnum,
  sim_rl78_bank3_r4_regnum,
  sim_rl78_bank3_r5_regnum,
  sim_rl78_bank3_r6_regnum,
  sim_rl78_bank3_r7_regnum,

  sim_rl78_psw_regnum,
  sim_rl78_es_regnum,
  sim_rl78_cs_regnum,
  sim_rl78_pc_regnum,

  sim_rl78_spl_regnum,
  sim_rl78_sph_regnum,
  sim_rl78_pmc_regnum,
  sim_rl78_mem_regnum,

  sim_rl78_num_regs
};

#endif /* SIM_RL78_H */
