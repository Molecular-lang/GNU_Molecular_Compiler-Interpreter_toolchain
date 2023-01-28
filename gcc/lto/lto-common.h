/* LTO common functions between lto.cc and lto-dump.cc header file.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef LTO_COMMON_H
#define LTO_COMMON_H

void lto_fe_init (void);
void read_cgraph_and_symbols (unsigned, const char **);
void print_lto_report_1 (void);

extern tree lto_eh_personality_decl;
extern GTY(()) vec<tree, va_gc> *tree_with_vars;
extern const unsigned char *lto_mode_identity_table;
extern tree first_personality_decl;

#endif

