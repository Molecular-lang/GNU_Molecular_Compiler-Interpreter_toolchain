/* Various declarations for pretty formatting of GIMPLE statements and
   expressions.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_GIMPLE_PRETTY_PRINT_H
#define GCC_GIMPLE_PRETTY_PRINT_H

#include "tree-pretty-print.h"

/* In gimple-pretty-print.cc  */
extern void debug_gimple_stmt (gimple *);
extern void debug_gimple_seq (gimple_seq);
extern void print_gimple_seq (FILE *, gimple_seq, int, dump_flags_t);
extern void print_gimple_stmt (FILE *, gimple *, int, dump_flags_t = TDF_NONE);
extern void debug (gimple &ref);
extern void debug (gimple *ptr);
extern void print_gimple_expr (FILE *, gimple *, int, dump_flags_t = TDF_NONE);
extern void pp_gimple_stmt_1 (pretty_printer *, const gimple *, int, dump_flags_t);
extern void gimple_dump_bb (FILE *, basic_block, int, dump_flags_t);
extern void gimple_dump_bb_for_graph (pretty_printer *, basic_block);
extern void dump_ssaname_info_to_file (FILE *, tree, int);
extern void percent_G_format (text_info *);

#endif /* ! GCC_GIMPLE_PRETTY_PRINT_H */
