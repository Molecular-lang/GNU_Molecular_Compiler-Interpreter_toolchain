/* Random host-dependent support code.
   Please review $(srcdir/SPL-README) for GNU licencing info. */

/* Do system-dependent stuff, mainly driven by autoconf-detected info.

   Well, some generic common stuff is done here too, like including
   ansidecl.h.  That's because the .h files in bfd/hosts files I'm
   trying to replace often did that.  If it can be dropped from this
   file (check in a non-ANSI environment!), it should be.  */

#ifdef PACKAGE
#error sysdep.h must be included in lieu of config.h
#endif

#include "config.h"
#include <stdlib.h>
#include <string.h>
#include "ansidecl.h"

#if !HAVE_DECL_STPCPY
extern char *stpcpy (char *__dest, const char *__src);
#endif

#define opcodes_error_handler _bfd_error_handler

/* Use sigsetjmp/siglongjmp without saving the signal mask if possible.
   It is faster than setjmp/longjmp on systems where the signal mask is
   saved.  */

#if defined(HAVE_SIGSETJMP)
#define OPCODES_SIGJMP_BUF		sigjmp_buf
#define OPCODES_SIGSETJMP(buf)		sigsetjmp((buf), 0)
#define OPCODES_SIGLONGJMP(buf,val)	siglongjmp((buf), (val))
#else
#define OPCODES_SIGJMP_BUF		jmp_buf
#define OPCODES_SIGSETJMP(buf)		setjmp(buf)
#define OPCODES_SIGLONGJMP(buf,val)	longjmp((buf), (val))
#endif

#define POISON_BFD_BOOLEAN 1
