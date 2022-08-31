// Please review $(srcdir/SPL-README) for GNU licencing info.

#include "tinfo.h"

namespace __cxxabiv1 {

__pointer_to_member_type_info::
~__pointer_to_member_type_info ()
{}

bool __pointer_to_member_type_info::
__pointer_catch (const __pbase_type_info *thr_type,
                 void **thr_obj,
                 unsigned outer) const
{
  // This static cast is always valid, as our caller will have determined that
  // thr_type is really a __pointer_to_member_type_info.
  const __pointer_to_member_type_info *thrown_type =
    static_cast <const __pointer_to_member_type_info *> (thr_type);
  
  if (*__context != *thrown_type->__context)
    return false;     // not pointers to member of same class
  
  return __pbase_type_info::__pointer_catch (thrown_type, thr_obj, outer);
}

}
