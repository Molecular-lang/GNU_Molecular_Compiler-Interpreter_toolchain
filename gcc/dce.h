/* RTL dead code elimination.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_DCE_H
#define GCC_DCE_H

extern void run_word_dce (void);
extern void run_fast_dce (void);
extern void run_fast_df_dce (void);

#endif /* GCC_DCE_H */
