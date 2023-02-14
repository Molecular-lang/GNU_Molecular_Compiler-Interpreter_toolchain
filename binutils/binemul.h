/* Binutils emulation layer. */

#ifndef BINEMUL_H
#define BINEMUL_H

#include "sysdep.h"
#include "bfd.h"
#include "bucomm.h"

extern void ar_emul_usage (FILE *);
extern void ar_emul_default_usage (FILE *);
extern bool ar_emul_append (bfd **, char *, const char *, bool, bool);
extern bool ar_emul_append_bfd (bfd **, bfd *, bool, bool);
extern bool ar_emul_default_append (bfd **, bfd *, bool, bool);
extern bool do_ar_emul_append (bfd **, bfd *, bool, bool, bool (*)(bfd *));
extern bool ar_emul_replace (bfd **, char *, const char *, bool);
extern bool ar_emul_replace_bfd (bfd **, bfd *, bool);
extern bool ar_emul_default_replace (bfd **, bfd *, bool);
extern bool ar_emul_parse_arg (char *);
extern bool ar_emul_default_parse_arg (char *);

/* Macros for common output.  */

#define AR_EMUL_USAGE_PRINT_OPTION_HEADER(fp) \
  /* xgettext:c-format */                     \
  fprintf (fp, _(" emulation options: \n"))

#define AR_EMUL_ELEMENT_CHECK(abfd, file_name) \
  do { if ((abfd) == NULL) bfd_fatal (file_name); } while (0)

#define AR_EMUL_APPEND_PRINT_VERBOSE(verbose, file_name) \
  do { if (verbose) printf ("a - %s\n", file_name); } while (0)

#define AR_EMUL_REPLACE_PRINT_VERBOSE(verbose, file_name) \
  do { if (verbose) printf ("r - %s\n", file_name); } while (0)

typedef struct bin_emulation_xfer_struct
{
  /* Print out the extra options.  */
  void (*ar_usage) (FILE *fp);
  bool (*ar_append) (bfd **, bfd *, bool, bool);
  bool (*ar_replace) (bfd **, bfd *, bool);
  bool (*ar_parse_arg) (char *);
}
bin_emulation_xfer_type;

#endif
