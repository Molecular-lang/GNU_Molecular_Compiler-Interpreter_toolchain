// Support for pointer abstractions -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <memory>

#include "mutex_pool.h"

namespace __gnu_internal _GLIBCXX_VISIBILITY(hidden)
{
  /* Returns different instances of __mutex depending on the passed index
   * in order to limit contention.
   */
  __gnu_cxx::__mutex&
  get_mutex(unsigned char i)
  {
    // increase alignment to put each lock on a separate cache line
    struct alignas(64) M : __gnu_cxx::__mutex { };
    static M m[mask + 1];
    return m[i];
  }
}

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  bad_weak_ptr::~bad_weak_ptr() noexcept = default;

  char const*
  bad_weak_ptr::what() const noexcept
  { return "bad_weak_ptr"; }

#ifdef __GTHREADS
  namespace
  {
    inline unsigned char key(const void* addr)
    { return _Hash_impl::hash(addr) & __gnu_internal::mask; }
  }

  _Sp_locker::_Sp_locker(const void* p) noexcept
  {
    if (__gthread_active_p())
      {
	_M_key1 = _M_key2 = key(p);
        __gnu_internal::get_mutex(_M_key1).lock();
      }
    else
      _M_key1 = _M_key2 = __gnu_internal::invalid;
  }

  _Sp_locker::_Sp_locker(const void* p1, const void* p2) noexcept
  {
    if (__gthread_active_p())
      {
	_M_key1 = key(p1);
	_M_key2 = key(p2);
	if (_M_key2 < _M_key1)
	  __gnu_internal::get_mutex(_M_key2).lock();
	__gnu_internal::get_mutex(_M_key1).lock();
	if (_M_key2 > _M_key1)
	  __gnu_internal::get_mutex(_M_key2).lock();
      }
    else
      _M_key1 = _M_key2 = __gnu_internal::invalid;
  }

  _Sp_locker::~_Sp_locker()
  {
    if (_M_key1 != __gnu_internal::invalid)
      {
	__gnu_internal::get_mutex(_M_key1).unlock();
	if (_M_key2 != _M_key1)
	  __gnu_internal::get_mutex(_M_key2).unlock();
      }
  }
#endif

  bool
  _Sp_make_shared_tag::_S_eq(const type_info& ti [[gnu::unused]]) noexcept
  {
#if __cpp_rtti
    return ti == typeid(_Sp_make_shared_tag);
#else
    // If libstdc++ itself is built with -fno-rtti then just assume that
    // make_shared and allocate_shared will never be used with -frtti.
    return false;
#endif
  }

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace
