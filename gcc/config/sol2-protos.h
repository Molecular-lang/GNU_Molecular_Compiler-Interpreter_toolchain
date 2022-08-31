/* Operating system specific prototypes to be used when targeting GCC for any
   Solaris 2 system.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* In sol2.cc.  */
extern void solaris_assemble_visibility (tree, int);
extern void solaris_elf_asm_comdat_section (const char *, unsigned int, tree);
extern void solaris_file_end (void);
extern void solaris_insert_attributes (tree, tree *);
extern void solaris_output_init_fini (FILE *, tree);
extern void solaris_override_options (void);

/* In sol2-c.cc.  */
extern void solaris_register_pragmas (void);

/* In sol2-cxx.cc.  */
extern tree solaris_cxx_decl_mangling_context (const_tree);
