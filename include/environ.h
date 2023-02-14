/* Declare the environ system variable. */

/* On OSX, the environ variable can be used directly in the code of an
   executable, but cannot be used in the code of a shared library (such as
   GCC's liblto_plugin, which links in libiberty code).  Instead, the
   function _NSGetEnviron can be called to get the address of environ.  */

#ifndef HAVE_ENVIRON_DECL
#  ifdef __APPLE__
#     include <crt_externs.h>
#     define environ (*_NSGetEnviron ())
#  else
#    ifndef environ
extern char **environ;
#    endif
#  endif
#  define HAVE_ENVIRON_DECL
#endif
