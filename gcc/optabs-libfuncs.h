/* Mapping from optabs to underlying library functions
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_OPTABS_LIBFUNCS_H
#define GCC_OPTABS_LIBFUNCS_H

#include "insn-opinit.h"

rtx convert_optab_libfunc (convert_optab, machine_mode, machine_mode);
rtx optab_libfunc (optab, machine_mode);

void gen_int_libfunc (optab, const char *, char, machine_mode);
void gen_fp_libfunc (optab, const char *, char, machine_mode);
void gen_fixed_libfunc (optab, const char *, char, machine_mode);
void gen_signed_fixed_libfunc (optab, const char *, char, machine_mode);
void gen_unsigned_fixed_libfunc (optab, const char *, char, machine_mode);
void gen_int_fp_libfunc (optab, const char *, char, machine_mode);
void gen_intv_fp_libfunc (optab, const char *, char, machine_mode);
void gen_int_fp_fixed_libfunc (optab, const char *, char, machine_mode);
void gen_int_fp_signed_fixed_libfunc (optab, const char *, char, machine_mode);
void gen_int_fixed_libfunc (optab, const char *, char, machine_mode);
void gen_int_signed_fixed_libfunc (optab, const char *, char, machine_mode);
void gen_int_unsigned_fixed_libfunc (optab, const char *, char, machine_mode);

void gen_interclass_conv_libfunc (convert_optab, const char *, machine_mode, machine_mode);
void gen_int_to_fp_conv_libfunc (convert_optab, const char *, machine_mode, machine_mode);
void gen_ufloat_conv_libfunc (convert_optab, const char *, machine_mode, machine_mode);
void gen_int_to_fp_nondecimal_conv_libfunc (convert_optab, const char *, machine_mode, machine_mode);
void gen_fp_to_int_conv_libfunc (convert_optab, const char *, machine_mode, machine_mode);
void gen_intraclass_conv_libfunc (convert_optab, const char *, machine_mode, machine_mode);
void gen_trunc_conv_libfunc (convert_optab, const char *, machine_mode, machine_mode);
void gen_extend_conv_libfunc (convert_optab, const char *, machine_mode, machine_mode);
void gen_fract_conv_libfunc (convert_optab, const char *, machine_mode, machine_mode);
void gen_fractuns_conv_libfunc (convert_optab, const char *, machine_mode, machine_mode);
void gen_satfract_conv_libfunc (convert_optab, const char *, machine_mode, machine_mode);
void gen_satfractuns_conv_libfunc (convert_optab, const char *, machine_mode, machine_mode);

tree build_libfunc_function_visibility (const char *, symbol_visibility);
tree build_libfunc_function (const char *);
rtx init_one_libfunc_visibility (const char *, symbol_visibility);
rtx init_one_libfunc (const char *);
rtx set_user_assembler_libfunc (const char *, const char *);

void set_optab_libfunc (optab, machine_mode, const char *);
void set_conv_libfunc (convert_optab, machine_mode, machine_mode, const char *);

void init_optabs (void);
void init_sync_libfuncs (int max);

#endif
