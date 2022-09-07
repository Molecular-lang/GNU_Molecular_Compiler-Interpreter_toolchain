// Please review $(srcdir/SPL-README) for GNU licencing info.

#include "tinfo.h"

namespace __cxxabiv1 {

__pointer_type_info::
~__pointer_type_info ()
{}

bool __pointer_type_info::
__is_pointer_p () const
{
  return true;
}

bool __pointer_type_info::
__pointer_catch (const __pbase_type_info *thrown_type,
                 void **thr_obj,
                 unsigned outer) const
{
#if __cpp_rtti
  if (outer < 2 && *__pointee == typeid (void))
    {
      // conversion to void
      return !thrown_type->__pointee->__is_function_p ();
    }
#endif
  
  return __pbase_type_info::__pointer_catch (thrown_type, thr_obj, outer);
}

}
