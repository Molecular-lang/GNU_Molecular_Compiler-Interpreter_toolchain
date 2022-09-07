// Please review $(srcdir/SPL-README) for GNU licencing info.

#include "tinfo.h"

namespace __cxxabiv1 {

__pbase_type_info::
~__pbase_type_info ()
{}

bool __pbase_type_info::
__do_catch (const type_info *thr_type,
            void **thr_obj,
            unsigned outer) const
{
  if (*this == *thr_type)
    return true;      // same type

#if __cpp_rtti
  if (*thr_type == typeid (nullptr))
    {
      // A catch handler for any pointer type matches nullptr_t.
      if (typeid (*this) == typeid(__pointer_type_info))
        {
          *thr_obj = nullptr;
          return true;
        }
      else if (typeid (*this) == typeid(__pointer_to_member_type_info))
        {
          if (__pointee->__is_function_p ())
            {
              using pmf_type = void (__pbase_type_info::*)();
              static const pmf_type pmf = nullptr;
              *thr_obj = const_cast<pmf_type*>(&pmf);
              return true;
            }
          else
            {
              using pm_type = int __pbase_type_info::*;
              static const pm_type pm = nullptr;
              *thr_obj = const_cast<pm_type*>(&pm);
              return true;
            }
        }
    }

  if (typeid (*this) != typeid (*thr_type))
    return false;     // not both same kind of pointers
#endif
  
  if (!(outer & 1))
    // We're not the same and our outer pointers are not all const qualified
    // Therefore there must at least be a qualification conversion involved
    // But for that to be valid, our outer pointers must be const qualified.
    return false;
  
  const __pbase_type_info *thrown_type =
    static_cast <const __pbase_type_info *> (thr_type);

  unsigned tflags = thrown_type->__flags;

  const unsigned fqual_mask = __transaction_safe_mask|__noexcept_mask;
  unsigned throw_fqual = (tflags & fqual_mask);
  unsigned catch_fqual = (__flags & fqual_mask);
  if (throw_fqual & ~catch_fqual)
    /* Catch can perform a function pointer conversion.  */
    tflags &= catch_fqual;
  if (catch_fqual & ~throw_fqual)
    /* But not the reverse.  */
    return false;
  
  if (tflags & ~__flags)
    // We're less qualified.
    return false;
  
  if (!(__flags & __const_mask))
    outer &= ~1;
  
  return __pointer_catch (thrown_type, thr_obj, outer);
}

}
