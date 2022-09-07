/* dwarf2ctf.h - DWARF interface for CTF/BTF generation.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* This file contains declarations and prototypes to define an interface
   between DWARF and CTF/BTF generation.  */

#ifndef GCC_DWARF2CTF_H
#define GCC_DWARF2CTF_H 1

#include "dwarf2out.h"
#include "flags.h"

/* Debug Format Interface.  Used in dwarf2out.cc.  */

extern void ctf_debug_init (void);
extern void ctf_debug_init_postprocess (bool);
extern bool ctf_do_die (dw_die_ref);
extern void ctf_debug_early_finish (const char *);
extern void ctf_debug_finish (const char *);

/* Wrappers for CTF/BTF to fetch information from GCC DWARF DIE.  Used in
   ctfc.cc.

   A CTF container does not store all debug information internally.  Some of
   the info is fetched indirectly via the DIE reference available in each CTF
   container entry.

   These functions will be used by the CTF container to give access to its
   consumers (CTF/BTF) to various debug information available in DWARF DIE.
   Direct access to debug information in GCC dwarf structures by the consumers
   of CTF/BTF information is not ideal.  */

/* Source location information.  */

extern const char * ctf_get_die_loc_file (dw_die_ref);
extern unsigned int ctf_get_die_loc_line (dw_die_ref);
extern unsigned int ctf_get_die_loc_col (dw_die_ref);

#endif /* GCC_DWARF2CTF_H */
