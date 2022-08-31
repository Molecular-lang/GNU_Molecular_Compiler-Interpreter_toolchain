/* This file defines the interface between the m32c simulator and gdb.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef SIM_M32C_H
#define SIM_M32C_H

enum m32c_sim_reg {
  m32c_sim_reg_r0_bank0,
  m32c_sim_reg_r1_bank0,
  m32c_sim_reg_r2_bank0,
  m32c_sim_reg_r3_bank0,
  m32c_sim_reg_a0_bank0,
  m32c_sim_reg_a1_bank0,
  m32c_sim_reg_fb_bank0,
  m32c_sim_reg_sb_bank0,
  m32c_sim_reg_r0_bank1,
  m32c_sim_reg_r1_bank1,
  m32c_sim_reg_r2_bank1,
  m32c_sim_reg_r3_bank1,
  m32c_sim_reg_a0_bank1,
  m32c_sim_reg_a1_bank1,
  m32c_sim_reg_fb_bank1,
  m32c_sim_reg_sb_bank1,
  m32c_sim_reg_usp,
  m32c_sim_reg_isp,
  m32c_sim_reg_pc,
  m32c_sim_reg_intb,
  m32c_sim_reg_flg,
  m32c_sim_reg_svf,
  m32c_sim_reg_svp,
  m32c_sim_reg_vct,
  m32c_sim_reg_dmd0,
  m32c_sim_reg_dmd1,
  m32c_sim_reg_dct0,
  m32c_sim_reg_dct1,
  m32c_sim_reg_drc0,
  m32c_sim_reg_drc1,
  m32c_sim_reg_dma0,
  m32c_sim_reg_dma1,
  m32c_sim_reg_dsa0,
  m32c_sim_reg_dsa1,
  m32c_sim_reg_dra0,
  m32c_sim_reg_dra1,
  m32c_sim_reg_num_regs
};

#endif /* SIM_M32C_H */
