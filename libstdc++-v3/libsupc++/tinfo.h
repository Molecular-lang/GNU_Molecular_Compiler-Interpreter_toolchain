// RTTI support internals for -*- C++ -*-
// Please review $(srcdir/SPL-README) for GNU licencing info.

#include "typeinfo"
#include <cstddef>

// Class declarations shared between the typeinfo implementation files.

#include <cxxabi.h>

namespace __cxxabiv1 {

namespace {

using namespace std;
using namespace abi;

// Initial part of a vtable, this structure is used with offsetof, so we don't
// have to keep alignments consistent manually.
struct vtable_prefix 
{
  // Offset to most derived object.
  ptrdiff_t whole_object;

  // Additional padding if necessary.
#ifdef _GLIBCXX_VTABLE_PADDING
  ptrdiff_t padding1;               
#endif

  // Pointer to most derived type_info.
  const __class_type_info *whole_type;  

  // Additional padding if necessary.
#ifdef _GLIBCXX_VTABLE_PADDING
  ptrdiff_t padding2;               
#endif

  // What a class's vptr points to.
  const void *origin;               
};

template <typename T>
inline const T *
adjust_pointer (const void *base, ptrdiff_t offset)
{
  return reinterpret_cast <const T *>
    (reinterpret_cast <const char *> (base) + offset);
}

// ADDR is a pointer to an object.  Convert it to a pointer to a base,
// using OFFSET. IS_VIRTUAL is true, if we are getting a virtual base.
inline void const *
convert_to_base (void const *addr, bool is_virtual, ptrdiff_t offset)
{
  if (is_virtual)
    {
      const void *vtable = *static_cast <const void *const *> (addr);
      
      offset = *adjust_pointer<ptrdiff_t> (vtable, offset);
    }

  return adjust_pointer<void> (addr, offset);
}

// some predicate functions for __class_type_info::__sub_kind
inline bool contained_p (__class_type_info::__sub_kind access_path)
{
  return access_path >= __class_type_info::__contained_mask;
}
inline bool public_p (__class_type_info::__sub_kind access_path)
{
  return access_path & __class_type_info::__contained_public_mask;
}
inline bool virtual_p (__class_type_info::__sub_kind access_path)
{
  return (access_path & __class_type_info::__contained_virtual_mask);
}
inline bool contained_public_p (__class_type_info::__sub_kind access_path)
{
  return ((access_path & __class_type_info::__contained_public)
          == __class_type_info::__contained_public);
}
inline bool contained_nonpublic_p (__class_type_info::__sub_kind access_path)
{
  return ((access_path & __class_type_info::__contained_public)
          == __class_type_info::__contained_mask);
}
inline bool contained_nonvirtual_p (__class_type_info::__sub_kind access_path)
{
  return ((access_path & (__class_type_info::__contained_mask
                          | __class_type_info::__contained_virtual_mask))
          == __class_type_info::__contained_mask);
}

static const __class_type_info *const nonvirtual_base_type =
    static_cast <const __class_type_info *> (0) + 1;

} // namespace

// __upcast_result is used to hold information during traversal of a class
// hierarchy when catch matching.
struct __class_type_info::__upcast_result
{
  const void *dst_ptr;        // pointer to caught object
  __sub_kind part2dst;        // path from current base to target
  int src_details;            // hints about the source type hierarchy
  const __class_type_info *base_type; // where we found the target,
                              // if in vbase the __class_type_info of vbase
                              // if a non-virtual base then 1
                              // else NULL
  __upcast_result (int d)
    :dst_ptr (NULL), part2dst (__unknown), src_details (d), base_type (NULL)
    {}
};

// __dyncast_result is used to hold information during traversal of a class
// hierarchy when dynamic casting.
struct __class_type_info::__dyncast_result
{
  const void *dst_ptr;        // pointer to target object or NULL
  __sub_kind whole2dst;       // path from most derived object to target
  __sub_kind whole2src;       // path from most derived object to sub object
  __sub_kind dst2src;         // path from target to sub object
  int whole_details;          // details of the whole class hierarchy
  
  __dyncast_result (int details_ = __vmi_class_type_info::__flags_unknown_mask)
    :dst_ptr (NULL), whole2dst (__unknown),
     whole2src (__unknown), dst2src (__unknown),
     whole_details (details_)
    {}

protected:
  __dyncast_result(const __dyncast_result&);
  
  __dyncast_result&
  operator=(const __dyncast_result&);
};

inline __class_type_info::__sub_kind __class_type_info::
__find_public_src (ptrdiff_t src2dst,
                   const void *obj_ptr,
                   const __class_type_info *src_type,
                   const void *src_ptr) const
{
  if (src2dst >= 0)
    return adjust_pointer <void> (obj_ptr, src2dst) == src_ptr
            ? __contained_public : __not_contained;
  if (src2dst == -2)
    return __not_contained;
  return __do_find_public_src (src2dst, obj_ptr, src_type, src_ptr);
}

}
