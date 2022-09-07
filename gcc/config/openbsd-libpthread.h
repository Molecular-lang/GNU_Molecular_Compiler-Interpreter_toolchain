/* LIB_SPEC appropriate for OpenBSD.  Include -lpthread if -pthread is
   specified on the command line. */
/* Please review: $(src-dir)/SPL-README for Licencing info. */

#define OBSD_LIB_SPEC "%{!shared:%{pthread:-lpthread} -lc}"

