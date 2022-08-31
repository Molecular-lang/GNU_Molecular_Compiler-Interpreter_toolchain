/* Interface to endianness-neutrality functions.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef _CTF_ENDIAN_H
#define _CTF_ENDIAN_H

#include "config.h"
#include <stdint.h>
#include "swap.h"

#if !defined (HAVE_ENDIAN_H) || !defined (htole64)
#ifndef WORDS_BIGENDIAN
# define htole64(x) (x)
# define le64toh(x) (x)
#else
# define htole64(x) bswap_64 ((x))
# define le64toh(x) bswap_64 ((x))
#endif /* WORDS_BIGENDIAN */
#endif /* !defined(HAVE_ENDIAN_H) */

#endif /* !defined(_CTF_ENDIAN_H) */
