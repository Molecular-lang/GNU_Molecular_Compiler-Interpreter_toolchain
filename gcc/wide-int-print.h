/* Print wide integers.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef WIDE_INT_PRINT_H
#define WIDE_INT_PRINT_H

#include <stdio.h>

#define WIDE_INT_PRINT_BUFFER_SIZE (WIDE_INT_MAX_PRECISION / 4 + 4)

/* Printing functions.  */

extern void print_dec (const wide_int_ref &wi, char *buf, signop sgn);
extern void print_dec (const wide_int_ref &wi, FILE *file, signop sgn);
extern void print_decs (const wide_int_ref &wi, char *buf);
extern void print_decs (const wide_int_ref &wi, FILE *file);
extern void print_decu (const wide_int_ref &wi, char *buf);
extern void print_decu (const wide_int_ref &wi, FILE *file);
extern void print_hex (const wide_int_ref &wi, char *buf);
extern void print_hex (const wide_int_ref &wi, FILE *file);

#endif /* WIDE_INT_PRINT_H */
