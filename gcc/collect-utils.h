/* Utility functions used by tools like collect2 and lto-wrapper.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_COLLECT_UTILS_H
#define GCC_COLLECT_UTILS_H

/* Provided in collect-utils.cc.  */
extern void notice (const char *, ...)
  __attribute__ ((format (printf, 1, 2)));
extern void fatal_signal (int);
extern void setup_signals (void);

extern struct pex_obj *collect_execute (const char *, char **,
					const char *, const char *,
					int, bool, const char *);
extern int collect_wait (const char *, struct pex_obj *);
extern void do_wait (const char *, struct pex_obj *);
extern void fork_execute (const char *, char **, bool, const char *);
extern void utils_cleanup (bool);


extern bool debug;
extern bool verbose;
extern bool save_temps;
extern const char *dumppfx;

/* Provided by the tool itself.  */

/* The name of the tool, printed in error messages.  */
extern const char tool_name[];
/* Called by utils_cleanup.  */
extern void tool_cleanup (bool);
extern void maybe_unlink (const char *);

#endif /* GCC_COLLECT_UTILS_H */
