/* unwind-ia64.h -- dump IA-64 unwind info. */

#include "elf/ia64.h"
#include "ansidecl.h"

#define UNW_VER(x)		((x) >> 48)
#define UNW_FLAG_MASK		0x0000ffff00000000LL
#define UNW_FLAG_OSMASK		0x0000f00000000000LL
#define UNW_FLAG_EHANDLER(x)	((x) & 0x0000000100000000LL)
#define UNW_FLAG_UHANDLER(x)	((x) & 0x0000000200000000LL)
#define UNW_LENGTH(x)		((x) & 0x00000000ffffffffLL)

extern const unsigned char *unw_decode (const unsigned char *, int, void *, const unsigned char *);
