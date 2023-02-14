/* ELF emulation code for targets using elf.em. */

extern const char *ldelf_emit_note_gnu_build_id;
extern const char *ldelf_emit_note_fdo_package_metadata;

extern void ldelf_after_parse (void);
extern bool ldelf_load_symbols (lang_input_statement_type *);
extern void ldelf_before_plugin_all_symbols_read (int, int, int, int, int, const char *);
extern void ldelf_after_open (int, int, int, int, int, const char *);
extern bool ldelf_setup_build_id (bfd *);
extern bool ldelf_setup_package_metadata (bfd *);
extern void ldelf_append_to_separated_string (char **, char *);
extern void ldelf_before_allocation (char *, char *, const char *);
extern bool ldelf_open_dynamic_archive(const char *, search_dirs_type *, lang_input_statement_type *);
extern lang_output_section_statement_type *ldelf_place_orphan(asection *, const char *, int);
extern void ldelf_before_place_orphans (void);
extern void ldelf_set_output_arch (void);
