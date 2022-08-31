/* Target-dependent costs for lower-subreg.cc.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef LOWER_SUBREG_H
#define LOWER_SUBREG_H 1

/* Information about whether, and where, lower-subreg should be applied.  */
struct lower_subreg_choices {
  /* A boolean vector for move splitting that is indexed by mode and is
     true for each mode that is to have its copies split.  */
  bool move_modes_to_split[MAX_MACHINE_MODE];

  /* True if zero-extensions from word_mode to twice_word_mode should
     be split.  */
  bool splitting_zext;

  /* Index X is true if twice_word_mode shifts by X + BITS_PER_WORD
     should be split.  */
  bool splitting_ashift[MAX_BITS_PER_WORD];
  bool splitting_lshiftrt[MAX_BITS_PER_WORD];
  bool splitting_ashiftrt[MAX_BITS_PER_WORD];

  /* True if there is at least one mode that is worth splitting.  */
  bool something_to_do;
};

/* Target-specific information for the subreg lowering pass.  */
struct target_lower_subreg {
  /* An integer mode that is twice as wide as word_mode.  */
  scalar_int_mode_pod x_twice_word_mode;

  /* What we have decided to do when optimizing for size (index 0)
     and speed (index 1).  */
  struct lower_subreg_choices x_choices[2];
};

extern struct target_lower_subreg default_target_lower_subreg;
#if SWITCHABLE_TARGET
extern struct target_lower_subreg *this_target_lower_subreg;
#else
#define this_target_lower_subreg (&default_target_lower_subreg)
#endif

#endif
