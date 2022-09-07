// Support routines for the -*- C++ -*- dynamic memory management.

// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <bits/c++config.h>
#include <stdlib.h>
#include <stdint.h>
#include <bit>
#include "new"

#if !_GLIBCXX_HAVE_ALIGNED_ALLOC && !_GLIBCXX_HAVE__ALIGNED_MALLOC \
  && !_GLIBCXX_HAVE_POSIX_MEMALIGN && _GLIBCXX_HAVE_MEMALIGN
# if _GLIBCXX_HOSTED && __has_include(<malloc.h>)
// Some C libraries declare memalign in <malloc.h>
#  include <malloc.h>
# else
extern "C" void *memalign(std::size_t boundary, std::size_t size);
# endif
#endif

using std::new_handler;
using std::bad_alloc;

#if ! _GLIBCXX_HOSTED
using std::size_t;
extern "C"
{
# if _GLIBCXX_HAVE_ALIGNED_ALLOC
  void *aligned_alloc(size_t alignment, size_t size);
# elif _GLIBCXX_HAVE__ALIGNED_MALLOC
  void *_aligned_malloc(size_t size, size_t alignment);
# elif _GLIBCXX_HAVE_POSIX_MEMALIGN
  void *posix_memalign(void **, size_t alignment, size_t size);
# elif _GLIBCXX_HAVE_MEMALIGN
  void *memalign(size_t alignment, size_t size);
# else
  // A freestanding C runtime may not provide "malloc" -- but there is no
  // other reasonable way to implement "operator new".
  void *malloc(size_t);
# endif
}
#endif

namespace __gnu_cxx {
#if _GLIBCXX_HAVE_ALIGNED_ALLOC
using ::aligned_alloc;
#elif _GLIBCXX_HAVE__ALIGNED_MALLOC
static inline void*
aligned_alloc (std::size_t al, std::size_t sz)
{ return _aligned_malloc(sz, al); }
#elif _GLIBCXX_HAVE_POSIX_MEMALIGN
static inline void*
aligned_alloc (std::size_t al, std::size_t sz)
{
  void *ptr;
  // posix_memalign has additional requirement, not present on aligned_alloc:
  // The value of alignment shall be a power of two multiple of sizeof(void *).
  if (al < sizeof(void*))
    al = sizeof(void*);
  int ret = posix_memalign (&ptr, al, sz);
  if (ret == 0)
    return ptr;
  return nullptr;
}
#elif _GLIBCXX_HAVE_MEMALIGN
static inline void*
aligned_alloc (std::size_t al, std::size_t sz)
{
  // Solaris requires al >= sizeof a word and QNX requires >= sizeof(void*)
  // but they both provide posix_memalign, so will use the definition above.
  return memalign (al, sz);
}
#else // !HAVE__ALIGNED_MALLOC && !HAVE_POSIX_MEMALIGN && !HAVE_MEMALIGN
// The C library doesn't provide any aligned allocation functions, define one.
// This is a modified version of code from gcc/config/i386/gmm_malloc.h
static inline void*
aligned_alloc (std::size_t al, std::size_t sz)
{
  // We need extra bytes to store the original value returned by malloc.
  if (al < sizeof(void*))
    al = sizeof(void*);
  void* const malloc_ptr = malloc(sz + al);
  if (!malloc_ptr)
    return nullptr;
  // Align to the requested value, leaving room for the original malloc value.
  void* const aligned_ptr = (void *) (((uintptr_t) malloc_ptr + al) & -al);

  // Store the original malloc value where it can be found by operator delete.
  ((void **) aligned_ptr)[-1] = malloc_ptr;

  return aligned_ptr;
}
#endif
} // namespace __gnu_cxx

_GLIBCXX_WEAK_DEFINITION void *
operator new (std::size_t sz, std::align_val_t al)
{
  std::size_t align = (std::size_t)al;

  /* Alignment must be a power of two.  */
  /* XXX This should be checked by the compiler (PR 86878).  */
  if (__builtin_expect (!std::__has_single_bit(align), false))
    _GLIBCXX_THROW_OR_ABORT(bad_alloc());

  /* malloc (0) is unpredictable; avoid it.  */
  if (__builtin_expect (sz == 0, false))
    sz = 1;

#if _GLIBCXX_HAVE_ALIGNED_ALLOC
# if defined _AIX || defined __APPLE__
  /* AIX 7.2.0.0 aligned_alloc incorrectly has posix_memalign's requirement
   * that alignment is a multiple of sizeof(void*).
   * OS X 10.15 has the same requirement.  */
  if (align < sizeof(void*))
    align = sizeof(void*);
# endif
  /* C11: the value of size shall be an integral multiple of alignment.  */
  sz = (sz + align - 1) & ~(align - 1);
#endif

  void *p;

  while ((p = __gnu_cxx::aligned_alloc (align, sz)) == nullptr)
    {
      new_handler handler = std::get_new_handler ();
      if (! handler)
	_GLIBCXX_THROW_OR_ABORT(bad_alloc());
      handler ();
    }

  return p;
}
