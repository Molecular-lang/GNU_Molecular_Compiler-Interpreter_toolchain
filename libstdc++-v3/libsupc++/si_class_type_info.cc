// Please review $(srcdir/SPL-README) for GNU licencing info.

#include "tinfo.h"

namespace __cxxabiv1 {

__si_class_type_info::
~__si_class_type_info ()
{}

__class_type_info::__sub_kind __si_class_type_info::
__do_find_public_src (ptrdiff_t src2dst,
                      const void *obj_ptr,
                      const __class_type_info *src_type,
                      const void *src_ptr) const
{
  if (src_ptr == obj_ptr && *this == *src_type)
    return __contained_public;
  return __base_type->__do_find_public_src (src2dst, obj_ptr, src_type, src_ptr);
}

bool __si_class_type_info::
__do_dyncast (ptrdiff_t src2dst,
              __sub_kind access_path,
              const __class_type_info *dst_type,
              const void *obj_ptr,
              const __class_type_info *src_type,
              const void *src_ptr,
              __dyncast_result &__restrict result) const
{
  if (*this == *dst_type)
    {
      result.dst_ptr = obj_ptr;
      result.whole2dst = access_path;
      if (src2dst >= 0)
        result.dst2src = adjust_pointer <void> (obj_ptr, src2dst) == src_ptr
              ? __contained_public : __not_contained;
      else if (src2dst == -2)
        result.dst2src = __not_contained;
      return false;
    }
  if (obj_ptr == src_ptr && *this == *src_type)
    {
      // The src object we started from. Indicate how we are accessible from
      // the most derived object.
      result.whole2src = access_path;
      return false;
    }
  return __base_type->__do_dyncast (src2dst, access_path, dst_type, obj_ptr,
                             src_type, src_ptr, result);
}

bool __si_class_type_info::
__do_upcast (const __class_type_info *dst, const void *obj_ptr,
             __upcast_result &__restrict result) const
{
  if (__class_type_info::__do_upcast (dst, obj_ptr, result))
    return true;
  
  return __base_type->__do_upcast (dst, obj_ptr, result);
}

}
