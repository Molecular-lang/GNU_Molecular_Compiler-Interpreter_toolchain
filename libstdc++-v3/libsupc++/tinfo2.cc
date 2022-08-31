// Methods for type_info for -*- C++ -*- Run Time Type Identification.

// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <cstddef>
#include "tinfo.h"

using std::type_info;

#if !__GXX_TYPEINFO_EQUALITY_INLINE

bool
type_info::before (const type_info &arg) const _GLIBCXX_NOEXCEPT
{
#if __GXX_MERGED_TYPEINFO_NAMES
  return name () < arg.name ();
#else
  /* The name() method will strip any leading '*' prefix. Therefore
     take care to look at __name rather than name() when looking for
     the "pointer" prefix.  */
  return (__name[0] == '*') ? name () < arg.name ()
    :  __builtin_strcmp (name (), arg.name ()) < 0;
#endif
}

#endif
