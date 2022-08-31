/* Support for suggestions about missing #include directives.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_KNOWN_HEADERS_H
#define GCC_KNOWN_HEADERS_H

extern const char *get_c_stdlib_header_for_name (const char *name);
extern const char *get_cp_stdlib_header_for_name (const char *name);

extern const char *get_c_stdlib_header_for_string_macro_name (const char *n);
extern const char *get_cp_stdlib_header_for_string_macro_name (const char *n);

/* Subclass of deferred_diagnostic for suggesting to the user
   that they have missed a #include.  */

class suggest_missing_header : public deferred_diagnostic
{
	public:
		suggest_missing_header(location_t loc, const char *name, const char *header_hint);
		~suggest_missing_header();
	
		private:
			const char *m_name_str;
			const char *m_header_hint;
};

#endif /* GCC_KNOWN_HEADERS_H */
