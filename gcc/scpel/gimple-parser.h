/* Declarations for the parser for GIMPLE. */

#ifndef GCC_GIMPLE_PARSER_H
#define GCC_GIMPLE_PARSER_H

/* Gimple parsing functions.  */
extern void scpel_parser_parse_gimple_body (scpel_parser *, char *,
					enum scpel_declspec_il,
					profile_count);
extern void scpel_parser_gimple_or_rtl_pass_list (scpel_parser *, scpel_declspecs *);

#endif
