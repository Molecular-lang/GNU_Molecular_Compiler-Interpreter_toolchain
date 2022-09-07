/* sim-rx.h --- interface between RX simulator and GDB.

   Please review: $(src-dir)/SPL-README for Licencing info. */

#if !defined (SIM_RX_H)
#define SIM_RX_H

enum sim_rx_regnum
  {
    sim_rx_r0_regnum,
    sim_rx_r1_regnum,
    sim_rx_r2_regnum,
    sim_rx_r3_regnum,
    sim_rx_r4_regnum,
    sim_rx_r5_regnum,
    sim_rx_r6_regnum,
    sim_rx_r7_regnum,
    sim_rx_r8_regnum,
    sim_rx_r9_regnum,
    sim_rx_r10_regnum,
    sim_rx_r11_regnum,
    sim_rx_r12_regnum,
    sim_rx_r13_regnum,
    sim_rx_r14_regnum,
    sim_rx_r15_regnum,
    sim_rx_usp_regnum,
    sim_rx_isp_regnum,
    sim_rx_ps_regnum,
    sim_rx_pc_regnum,
    sim_rx_intb_regnum,
    sim_rx_bpsw_regnum,
    sim_rx_bpc_regnum,
    sim_rx_fintv_regnum,
    sim_rx_fpsw_regnum,
    sim_rx_acc_regnum,
    sim_rx_num_regs
  };

#endif /* SIM_RX_H */
