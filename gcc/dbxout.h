/* dbxout.h - Various declarations for functions found in dbxout.cc
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_DBXOUT_H
#define GCC_DBXOUT_H

extern int dbxout_symbol (tree, int);
extern void dbxout_parms (tree);
extern void dbxout_reg_parms (tree);
extern int dbxout_syms (tree);

extern void default_stabs_asm_out_destructor (rtx, int);
extern void default_stabs_asm_out_constructor (rtx, int);

/* dbxout helper functions */
#if defined DBX_DEBUGGING_INFO || defined XCOFF_DEBUGGING_INFO

extern void dbxout_int (int);
extern void dbxout_stabd (int, int);
extern void dbxout_begin_stabn (int);
extern void dbxout_begin_stabn_sline (int);
extern void dbxout_begin_empty_stabs (int);
extern void dbxout_begin_simple_stabs (const char *, int);
extern void dbxout_begin_simple_stabs_desc (const char *, int, int);

extern void dbxout_stab_value_zero (void);
extern void dbxout_stab_value_label (const char *);
extern void dbxout_stab_value_label_diff (const char *, const char *);
extern void dbxout_stab_value_internal_label (const char *, int *);
extern void dbxout_stab_value_internal_label_diff (const char *, int *,
						   const char *);
#endif

/* Language description for N_SO stabs.  */
#define N_SO_AS          1
#define N_SO_C           2
#define N_SO_ANSI_C      3
#define N_SO_CC          4 /* c++*/
#define N_SO_FORTRAN     5
#define N_SO_FORTRAN90   7
#define N_SO_OBJC        50
#define N_SO_OBJCPLUS    51

#endif /* GCC_DBXOUT_H */
