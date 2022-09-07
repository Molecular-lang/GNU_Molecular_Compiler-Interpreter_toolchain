/* intl.h - internationalization
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_INTL_H
#define GCC_INTL_H

#ifdef HAVE_LOCALE_H
# include <locale.h>
#endif

#ifndef HAVE_SETLOCALE
# define setlocale(category, locale) (locale)
#endif

#ifdef ENABLE_NLS
#include <libintl.h>
extern void gcc_init_libintl (void);
extern size_t gcc_gettext_width (const char *);
#else
/* Stubs.  */
# undef textdomain
# define textdomain(domain) (domain)
# undef bindtextdomain
# define bindtextdomain(domain, directory) (domain)
# undef gettext
# define gettext(msgid) (msgid)
# define ngettext(singular,plural,n) fake_ngettext (singular, plural, n)
# define gcc_init_libintl()	/* nothing */
# define gcc_gettext_width(s) strlen (s)

extern const char *fake_ngettext (const char *singular, const char *plural,
				  unsigned long int n);

#endif

/* Used to immediately translate the argument.  */
#ifndef _
# define _(msgid) gettext (msgid)
#endif

/* Used to mark strings that will be translated later.  */
#ifndef N_
# define N_(msgid) msgid
#endif

/* Like N_, but for GCC diagnostic format strings.  See ABOUT-GCC-NLS for
   details.  */
#ifndef G_
# define G_(gmsgid) gmsgid
#endif

extern char *get_spaces (const char *);

extern const char *open_quote;
extern const char *close_quote;
extern const char *locale_encoding;
extern bool locale_utf8;

#endif /* intl.h */
