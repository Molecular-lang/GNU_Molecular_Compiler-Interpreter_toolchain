#ifndef LDMISC_H
#define LDMISC_H

extern void vfinfo (FILE *fp, const char *fmt, va_list arg, bool is_warning);
extern void einfo (const char *, ...);
extern void minfo (const char *, ...);
extern void info_msg (const char *, ...);
extern void lfinfo (FILE *, const char *, ...);
extern void info_assert (const char *, unsigned int);
extern void yyerror (const char *);
extern void *xmalloc (size_t);
extern void *xrealloc (void *, size_t);
extern void xexit (int);

#define ASSERT(x) \
do { if (!(x)) info_assert(__FILE__,__LINE__); } while (0)

#define FAIL() \
do { info_assert(__FILE__,__LINE__); } while (0)

extern void print_space (void);
extern void print_nl (void);

#endif
