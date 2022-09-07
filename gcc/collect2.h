/* Header file for collect routines.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_COLLECT2_H
#define GCC_COLLECT2_H

extern struct pex_obj *collect_execute (const char *, char **, const char *, const char *, int flags);

extern int collect_wait (const char *, struct pex_obj *);

extern int file_exists (const char *);

extern const char *c_file_name;
extern struct obstack temporary_obstack;
extern char *temporary_firstobj;
extern bool may_unlink_output_file;

extern void notice_translated (const char *, ...) ATTRIBUTE_PRINTF_1;
extern void notice (const char *, ...) ATTRIBUTE_PRINTF_1;

extern bool at_file_supplied;
#endif /* ! GCC_COLLECT2_H */
