/* pep-dll.h: Header file for routines used to build Windows DLLs.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef PEP_DLL_H
#define PEP_DLL_H

#include "sysdep.h"
#include "bfd.h"
#include "bfdlink.h"
#include "deffile.h"

extern def_file * pep_def_file;
extern int pep_dll_export_everything;
extern int pep_dll_exclude_all_symbols;
extern int pep_dll_do_default_excludes;
extern int pep_dll_kill_ats;
extern int pep_dll_stdcall_aliases;
extern int pep_dll_warn_dup_exports;
extern int pep_dll_compat_implib;
extern int pep_dll_extra_pe_debug;
extern int pep_use_nul_prefixed_import_tables;
extern int pep_use_coff_long_section_names;
extern int pep_leading_underscore;
extern int pep_dll_enable_reloc_section;

typedef enum { EXCLUDESYMS, EXCLUDELIBS, EXCLUDEFORIMPLIB } exclude_type;

extern void pep_dll_id_target  (const char *);
extern void pep_dll_add_excludes  (const char *, const exclude_type);
extern void pep_dll_generate_def_file  (const char *);
extern void pep_dll_generate_implib  (def_file *, const char *, struct bfd_link_info *);
extern void pep_process_import_defs  (bfd *, struct bfd_link_info *);
extern bool pep_implied_import_dll  (const char *);
extern void pep_dll_build_sections  (bfd *, struct bfd_link_info *);
extern void pep_exe_build_sections  (bfd *, struct bfd_link_info *);
extern void pep_dll_fill_sections  (bfd *, struct bfd_link_info *);
extern void pep_exe_fill_sections  (bfd *, struct bfd_link_info *);
extern void pep_find_data_imports  (const char *, void (*cb) (arelent *, asection *, char *, const char *));
extern void pep_create_import_fixup  (arelent * rel, asection *, bfd_vma, char *, const char *);
extern bool pep_bfd_is_dll  (bfd *);
extern void pep_output_file_set_long_section_names (bfd *);

#endif /* PEP_DLL_H */
