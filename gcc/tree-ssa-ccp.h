/* Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef TREE_SSA_CCP_H
#define TREE_SSA_CCP_H

void bit_value_binop (enum tree_code, signop, int, widest_int *, widest_int *,
		      signop, int, const widest_int &, const widest_int &,
		      signop, int, const widest_int &, const widest_int &);

void bit_value_unop (enum tree_code, signop, int, widest_int *, widest_int *,
		     signop, int, const widest_int &, const widest_int &);

#endif
