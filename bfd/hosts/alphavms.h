/* alphavms.h -- BFD definitions for an openVMS host
   Please review $(srcdir/SPL-README) for GNU licencing info. */

#ifdef PACKAGE
#error sysdep.h must be included in lieu of config.h
#endif

#include "config.h"
#include "ansidecl.h"

#include <stddef.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/file.h>
#include <stdlib.h>
#include <unixlib.h>
#include <unixio.h>
#include <time.h>

#include "filenames.h"
#include "fopen-vms.h"

#define NO_FCNTL 1

#ifndef O_ACCMODE
#define O_ACCMODE (O_RDONLY | O_WRONLY | O_RDWR)
#endif

extern int getpagesize (void);
extern char *stpcpy (char *, const char *);

/* No intl.  */
#define gettext(Msgid) (Msgid)
#define dgettext(Domainname, Msgid) (Msgid)
#define dcgettext(Domainname, Msgid, Category) (Msgid)
#define ngettext(Msgid1, Msgid2, n) \
  (n == 1 ? Msgid1 : Msgid2)
#define dngettext(Domainname, Msgid1, Msgid2, n) \
  (n == 1 ? Msgid1 : Msgid2)
#define dcngettext(Domainname, Msgid1, Msgid2, n, Category) \
  (n == 1 ? Msgid1 : Msgid2)
#define textdomain(Domainname) do {} while (0)
#define bindtextdomain(Domainname, Dirname) do {} while (0)
#define _(String) (String)
#define N_(String) (String)
