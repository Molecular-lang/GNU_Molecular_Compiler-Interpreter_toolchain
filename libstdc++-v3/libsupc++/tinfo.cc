// Methods for type_info for -*- C++ -*- Run Time Type Identification.
// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <bits/c++config.h>
#include <cstddef>
#include "tinfo.h"

std::type_info::
~type_info ()
{ }

#if !__GXX_TYPEINFO_EQUALITY_INLINE

#if __cplusplus > 202002L
# error "this file must be compiled with C++20 or older to define operator=="
#endif

// We can't rely on common symbols being shared between shared objects.
bool std::type_info::
operator== (const std::type_info& arg) const _GLIBCXX_NOEXCEPT
{
#if __GXX_MERGED_TYPEINFO_NAMES
  return name () == arg.name ();
#else
  /* The name() method will strip any leading '*' prefix. Therefore
     take care to look at __name rather than name() when looking for
     the "pointer" prefix.  */
  return (&arg == this)
    || (__name[0] != '*' && (__builtin_strcmp (name (), arg.name ()) == 0));
#endif
}

bool
std::type_info::__equal (const std::type_info& arg) const _GLIBCXX_NOEXCEPT
__attribute__((alias("_ZNKSt9type_infoeqERKS_")));
#endif

namespace std {

// return true if this is a type_info for a pointer type
bool type_info::
__is_pointer_p () const
{
  return false;
}

// return true if this is a type_info for a function type
bool type_info::
__is_function_p () const
{
  return false;
}

// try and catch a thrown object.
bool type_info::
__do_catch (const type_info *thr_type, void **, unsigned) const
{
  return *this == *thr_type;
}

// upcast from this type to the target. __class_type_info will override
bool type_info::
__do_upcast (const abi::__class_type_info *, void **) const
{
  return false;
}

}
