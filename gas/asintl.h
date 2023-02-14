/* asintl.h - gas-specific header for gettext code. */

#ifndef ENABLE_NLS
  /* The Solaris version of locale.h always includes libintl.h.  If we have
     been configured with --disable-nls then ENABLE_NLS will not be defined
     and the dummy definitions of bindtextdomain (et al) below will conflict
     with the definitions in libintl.h.  So we define these values to prevent
     the bogus inclusion of libintl.h.  */
# define _LIBINTL_H
# define _LIBGETTEXT_H
#endif
#include <locale.h>

#ifdef ENABLE_NLS
# include <libintl.h>
# define _(String) gettext (String)
# ifdef gettext_noop
#  define N_(String) gettext_noop (String)
# else
#  define N_(String) (String)
# endif
#else
# define gettext(Msgid) (Msgid)
# define dgettext(Domainname, Msgid) (Msgid)
# define dcgettext(Domainname, Msgid, Category) (Msgid)
# define ngettext(Msgid1, Msgid2, n) \
  (n == 1 ? Msgid1 : Msgid2)
# define dngettext(Domainname, Msgid1, Msgid2, n) \
  (n == 1 ? Msgid1 : Msgid2)
# define dcngettext(Domainname, Msgid1, Msgid2, n, Category) \
  (n == 1 ? Msgid1 : Msgid2)
# define textdomain(Domainname) do {} while (0)
# define bindtextdomain(Domainname, Dirname) do {} while (0)
# define _(String) (String)
# define N_(String) (String)
#endif
