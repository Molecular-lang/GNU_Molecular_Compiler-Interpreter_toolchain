/* Various declarations for language-independent diagnostics
   subroutines that are only for use in the compilers proper and not
   the driver or other programs.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_TREE_DIAGNOSTIC_H
#define GCC_TREE_DIAGNOSTIC_H

/* TREE_BLOCK if the diagnostic is to be reported in some inline
   function inlined into other function, otherwise NULL.  */
#define diagnostic_abstract_origin(DI)		\
  ((tree) diagnostic_info_auxiliary_data (DI))

/* Function of last diagnostic message; more generally, function such
   that if next diagnostic message is in it then we don't have to
   mention the function name.  */
#define diagnostic_last_function(DC)			\
  ((tree) diagnostic_context_auxiliary_data (DC))

/* True if the last function in which a diagnostic was reported is
   different from the current one.  */
#define diagnostic_last_function_changed(DC, DI)			\
  (diagnostic_last_function (DC) != (diagnostic_abstract_origin (DI)	\
				     ? diagnostic_abstract_origin (DI)	\
				     : current_function_decl))

/* Remember the current function as being the last one in which we report
   a diagnostic.  */
#define diagnostic_set_last_function(DC, DI)		\
  diagnostic_context_auxiliary_data (DC)		\
    = (((DI) && diagnostic_abstract_origin (DI))	\
       ? diagnostic_abstract_origin (DI)		\
       : current_function_decl)

void diagnostic_report_current_function (diagnostic_context *,
					 diagnostic_info *);
void virt_loc_aware_diagnostic_finalizer (diagnostic_context *,
					  diagnostic_info *);

void tree_diagnostics_defaults (diagnostic_context *context);
bool default_tree_printer (pretty_printer *, text_info *, const char *,
			   int, bool, bool, bool, bool *, const char **);

extern void default_tree_diagnostic_path_printer (diagnostic_context *,
						  const diagnostic_path *);
extern json::value *default_tree_make_json_for_path (diagnostic_context *,
						     const diagnostic_path *);

extern void maybe_unwind_expanded_macro_loc (diagnostic_context *context,
					     location_t where);

#endif /* ! GCC_TREE_DIAGNOSTIC_H */
