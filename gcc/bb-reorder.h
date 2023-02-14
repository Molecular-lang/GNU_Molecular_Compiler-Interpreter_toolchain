/* Basic block reordering routines for the GNU compiler.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_BB_REORDER
#define GCC_BB_REORDER

/* Target-specific globals.  */
struct target_bb_reorder {
  /* Length of unconditional jump instruction.  */
  int x_uncond_jump_length;
};

extern struct target_bb_reorder default_target_bb_reorder;
#if SWITCHABLE_TARGET
extern struct target_bb_reorder *this_target_bb_reorder;
#else
#define this_target_bb_reorder (&default_target_bb_reorder)
#endif

extern int get_uncond_jump_length (void);

extern void insert_section_boundary_note (void);

#endif
