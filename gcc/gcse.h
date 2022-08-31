/* Global common subexpression elimination/Partial redundancy elimination
   and global constant/copy propagation for GNU compiler.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_GCSE_H
#define GCC_GCSE_H

/* Target-dependent globals.  */
struct target_gcse {
  /* Nonzero for each mode that supports (set (reg) (reg)).
     This is trivially true for integer and floating point values.
     It may or may not be true for condition codes.  */
  char x_can_copy[(int) NUM_MACHINE_MODES];

  /* True if the previous field has been initialized.  */
  bool x_can_copy_init_p;
};

extern struct target_gcse default_target_gcse;
#if SWITCHABLE_TARGET
extern struct target_gcse *this_target_gcse;
#else
#define this_target_gcse (&default_target_gcse)
#endif

void gcse_cc_finalize (void);
extern bool gcse_or_cprop_is_too_expensive (const char *);

#endif
