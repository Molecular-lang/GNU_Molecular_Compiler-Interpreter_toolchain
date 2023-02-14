/* testlib.h -- Header for test functions for libbacktrace library */

#ifndef LIBBACKTRACE_TESTLIB_H
#define LIBBACKTRACE_TESTLIB_H

/* Portable attribute syntax.  Actually some of these tests probably
   won't work if the attributes are not recognized.  */

#ifndef GCC_VERSION
# define GCC_VERSION (__GNUC__ * 1000 + __GNUC_MINOR__)
#endif

#if (GCC_VERSION < 2007)
# define __attribute__(x)
#endif

#ifndef ATTRIBUTE_UNUSED
# define ATTRIBUTE_UNUSED __attribute__ ((__unused__))
#endif

/* Used to collect backtrace info.  */

struct info
{
  char *filename;
  int lineno;
  char *function;
};

/* Passed to backtrace callback function.  */

struct bdata
{
  struct info *all;
  size_t index;
  size_t max;
  int failed;
};

/* Passed to backtrace_simple callback function.  */

struct sdata
{
  uintptr_t *addrs;
  size_t index;
  size_t max;
  int failed;
};

/* Passed to backtrace_syminfo callback function.  */

struct symdata
{
  const char *name;
  uintptr_t val, size;
  int failed;
};

/* The backtrace state.  */

extern void *state;

/* The number of failures.  */

extern int failures;

extern const char *base (const char *p);
extern void check (const char *name, int index, const struct info *all,
		   int want_lineno, const char *want_function,
		   const char *want_file, int *failed);
extern int callback_one (void *, uintptr_t, const char *, int, const char *);
extern void error_callback_one (void *, const char *, int);
extern int callback_two (void *, uintptr_t);
extern void error_callback_two (void *, const char *, int);
extern void callback_three (void *, uintptr_t, const char *, uintptr_t,
			    uintptr_t);
extern void error_callback_three (void *, const char *, int);
extern void error_callback_create (void *, const char *, int);

#endif /* !defined(LIBBACKTRACE_TESTLIB_H) */
