/* Basic error reporting routines.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* warning, error, and fatal.  These definitions are suitable for use
   in the generator programs; eventually we would like to use them in
   cc1 too, but that's a longer term project.

   N.B. We cannot presently use ATTRIBUTE_PRINTF with these functions,
   because they can be extended with additional format specifiers which
   GCC does not know about.  */

#ifndef GCC_ERRORS_H
#define GCC_ERRORS_H

extern void warning (const char *, ...) ATTRIBUTE_PRINTF_1 ATTRIBUTE_COLD;
extern void error (const char *, ...) ATTRIBUTE_PRINTF_1 ATTRIBUTE_COLD;
extern void fatal (const char *, ...) ATTRIBUTE_NORETURN ATTRIBUTE_PRINTF_1 ATTRIBUTE_COLD;
extern void internal_error (const char *, ...) ATTRIBUTE_NORETURN ATTRIBUTE_PRINTF_1 ATTRIBUTE_COLD;
extern const char *trim_filename (const char *);

extern int have_error;
extern const char *progname;

#endif /* ! GCC_ERRORS_H */
