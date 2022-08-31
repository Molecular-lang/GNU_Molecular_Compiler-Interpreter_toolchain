/* Command line option handling.  Interactions with diagnostics code.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_OPTS_DIAGNOSTIC_H
#define GCC_OPTS_DIAGNOSTIC_H

extern char *option_name (diagnostic_context *context, int option_index,
			  diagnostic_t orig_diag_kind, diagnostic_t diag_kind);

extern char *get_option_url (diagnostic_context *context, int option_index);

#endif
