/* Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef LDFILE_H
#define LDFILE_H

extern bool ldfile_assumed_script;
extern unsigned long ldfile_output_machine;
extern enum bfd_architecture ldfile_output_architecture;
extern const char *ldfile_output_machine_name;

/* Structure used to hold the list of directories to search for libraries.  */

typedef struct search_dirs {
	/* Next directory on list.  */
	struct search_dirs *next;
	/* Name of directory.  */
	const char *name;
	/* TRUE if this is from the command line.  */
	bool cmdline;
} search_dirs_type;

extern search_dirs_type *search_head;

extern void ldfile_add_arch(const char *);
extern void ldfile_add_library_path(const char *, bool cmdline);
extern void ldfile_open_command_file(const char *name);
extern void ldfile_open_script_file(const char *name);
extern void ldfile_open_default_command_file(const char *name);
extern void ldfile_open_file(struct lang_input_statement_struct *);
extern bool ldfile_try_open_bfd(const char *, struct lang_input_statement_struct *);
extern void ldfile_set_output_arch(const char *, enum bfd_architecture);
extern bool ldfile_open_file_search(const char *arch, struct lang_input_statement_struct *, const char *lib, const char *suffix);

#endif
