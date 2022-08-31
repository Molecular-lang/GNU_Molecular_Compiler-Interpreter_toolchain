/* Instruction scheduling pass.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_SEL_SCHED_H
#define GCC_SEL_SCHED_H

/* The main entry point.  */
extern void run_selective_scheduling (void);
extern bool maybe_skip_selective_scheduling (void);

#endif /* GCC_SEL_SCHED_H */
