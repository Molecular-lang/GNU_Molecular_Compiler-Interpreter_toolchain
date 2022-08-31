/* budbg.c -- Interfaces to the generic debugging information routines.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef BUDBG_H
#define BUDBG_H

/* Routine used to read generic debugging information.  */

extern void *read_debugging_info (bfd *, asymbol **, long, bool);

/* Routine used to print generic debugging information.  */

extern bool print_debugging_info
  (FILE *, void *, bfd *, asymbol **,
   char * (*) (struct bfd *, const char *, int), bool);

/* Routines used to read and write stabs information.  */

extern void *start_stab (void *, bfd *, bool, asymbol **, long);

extern bool finish_stab (void *, void *);

extern bool parse_stab
  (void *, void *, int, int, bfd_vma, const char *);

extern bool write_stabs_in_sections_debugging_info
  (bfd *, void *, bfd_byte **, bfd_size_type *, bfd_byte **, bfd_size_type *);

/* Routine used to read COFF debugging information.  */

extern bool parse_coff (bfd *, asymbol **, long, void *);

#endif
