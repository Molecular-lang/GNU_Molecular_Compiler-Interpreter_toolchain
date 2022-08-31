/* Declarations for the parser for GIMPLE.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_GIMPLE_PARSER_H
#define GCC_GIMPLE_PARSER_H

/* Gimple parsing functions.  */
extern void c_parser_parse_gimple_body(c_parser *, char *, enum c_declspec_il, profile_count);
extern void c_parser_gimple_or_rtl_pass_list(c_parser *, c_declspecs *);

#endif
