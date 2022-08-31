// -*- C++ -*- header.

// Please review: $(src-dir)/SPL-README for Licencing info.

/** @file bits/atomic_futex.h
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly.
 */

#ifndef _GLIBCXX_ATOMIC_FUTEX_H
#define _GLIBCXX_ATOMIC_FUTEX_H 1

#pragma GCC system_header

#include <atomic>
#if ! (defined(_GLIBCXX_HAVE_LINUX_FUTEX) && ATOMIC_INT_LOCK_FREE > 1)
#include <mutex>
#include <condition_variable>
#endif
#include <bits/chrono.h>

#ifndef _GLIBCXX_ALWAYS_INLINE
#define _GLIBCXX_ALWAYS_INLINE inline __attribute__((__always_inline__))
#endif

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

#ifdef _GLIBCXX_HAS_GTHREADS
#if defined(_GLIBCXX_HAVE_LINUX_FUTEX) && ATOMIC_INT_LOCK_FREE > 1
  struct __atomic_futex_unsigned_base
  {
    // __s and __ns are measured against CLOCK_REALTIME. Returns false
    // iff a timeout occurred.
    bool
    _M_futex_wait_until(unsigned *__addr, unsigned __val, bool __has_timeout,
	chrono::seconds __s, chrono::nanoseconds __ns);

    // __s and __ns are measured against CLOCK_MONOTONIC. Returns
    // false iff a timeout occurred.
    bool
    _M_futex_wait_until_steady(unsigned *__addr, unsigned __val,
	bool __has_timeout, chrono::seconds __s, chrono::nanoseconds __ns);

    // This can be executed after the object has been destroyed.
    static void _M_futex_notify_all(unsigned* __addr);
  };

  template <unsigned _Waiter_bit = 0x80000000>
  class __atomic_futex_unsigned : __atomic_futex_unsigned_base
  {
    typedef chrono::steady_clock __clock_t;

    // This must be lock-free and at offset 0.
    atomic<unsigned> _M_data;

  public:
    explicit
    __atomic_futex_unsigned(unsigned __data) : _M_data(__data)
    { }

    _GLIBCXX_ALWAYS_INLINE unsigned
    _M_load(memory_order __mo)
    {
      return _M_data.load(__mo) & ~_Waiter_bit;
    }

  private:
    // If a timeout occurs, returns a current value after the timeout;
    // otherwise, returns the operand's value if equal is true or a different
    // value if equal is false.
    // The assumed value is the caller's assumption about the current value
    // when making the call.
    // __s and __ns are measured against CLOCK_REALTIME.
    unsigned
    _M_load_and_test_until(unsigned __assumed, unsigned __operand,
	bool __equal, memory_order __mo, bool __has_timeout,
	chrono::seconds __s, chrono::nanoseconds __ns)
    {
      for (;;)
	{
	  // Don't bother checking the value again because we expect the caller
	  // to have done it recently.
	  // memory_order_relaxed is sufficient because we can rely on just the
	  // modification order (store_notify uses an atomic RMW operation too),
	  // and the futex syscalls synchronize between themselves.
	  _M_data.fetch_or(_Waiter_bit, memory_order_relaxed);
	  bool __ret = _M_futex_wait_until((unsigned*)(void*)&_M_data,
					   __assumed | _Waiter_bit,
					   __has_timeout, __s, __ns);
	  // Fetch the current value after waiting (clears _Waiter_bit).
	  __assumed = _M_load(__mo);
	  if (!__ret || ((__operand == __assumed) == __equal))
	    return __assumed;
	  // TODO adapt wait time
	}
    }

    // If a timeout occurs, returns a current value after the timeout;
    // otherwise, returns the operand's value if equal is true or a different
    // value if equal is false.
    // The assumed value is the caller's assumption about the current value
    // when making the call.
    // __s and __ns are measured against CLOCK_MONOTONIC.
    unsigned
    _M_load_and_test_until_steady(unsigned __assumed, unsigned __operand,
	bool __equal, memory_order __mo, bool __has_timeout,
	chrono::seconds __s, chrono::nanoseconds __ns)
    {
      for (;;)
	{
	  // Don't bother checking the value again because we expect the caller
	  // to have done it recently.
	  // memory_order_relaxed is sufficient because we can rely on just the
	  // modification order (store_notify uses an atomic RMW operation too),
	  // and the futex syscalls synchronize between themselves.
	  _M_data.fetch_or(_Waiter_bit, memory_order_relaxed);
	  bool __ret = _M_futex_wait_until_steady((unsigned*)(void*)&_M_data,
					   __assumed | _Waiter_bit,
					   __has_timeout, __s, __ns);
	  // Fetch the current value after waiting (clears _Waiter_bit).
	  __assumed = _M_load(__mo);
	  if (!__ret || ((__operand == __assumed) == __equal))
	    return __assumed;
	  // TODO adapt wait time
	}
    }

    // Returns the operand's value if equal is true or a different value if
    // equal is false.
    // The assumed value is the caller's assumption about the current value
    // when making the call.
    unsigned
    _M_load_and_test(unsigned __assumed, unsigned __operand,
	bool __equal, memory_order __mo)
    {
      return _M_load_and_test_until(__assumed, __operand, __equal, __mo,
				    false, {}, {});
    }

    // If a timeout occurs, returns a current value after the timeout;
    // otherwise, returns the operand's value if equal is true or a different
    // value if equal is false.
    // The assumed value is the caller's assumption about the current value
    // when making the call.
    template<typename _Dur>
    unsigned
    _M_load_and_test_until_impl(unsigned __assumed, unsigned __operand,
	bool __equal, memory_order __mo,
	const chrono::time_point<std::chrono::system_clock, _Dur>& __atime)
    {
      auto __s = chrono::time_point_cast<chrono::seconds>(__atime);
      auto __ns = chrono::duration_cast<chrono::nanoseconds>(__atime - __s);
      // XXX correct?
      return _M_load_and_test_until(__assumed, __operand, __equal, __mo,
	  true, __s.time_since_epoch(), __ns);
    }

    template<typename _Dur>
    unsigned
    _M_load_and_test_until_impl(unsigned __assumed, unsigned __operand,
	bool __equal, memory_order __mo,
	const chrono::time_point<std::chrono::steady_clock, _Dur>& __atime)
    {
      auto __s = chrono::time_point_cast<chrono::seconds>(__atime);
      auto __ns = chrono::duration_cast<chrono::nanoseconds>(__atime - __s);
      // XXX correct?
      return _M_load_and_test_until_steady(__assumed, __operand, __equal, __mo,
	  true, __s.time_since_epoch(), __ns);
    }

  public:

    _GLIBCXX_ALWAYS_INLINE unsigned
    _M_load_when_not_equal(unsigned __val, memory_order __mo)
    {
      unsigned __i = _M_load(__mo);
      if ((__i & ~_Waiter_bit) != __val)
	return (__i & ~_Waiter_bit);
      // TODO Spin-wait first.
      return _M_load_and_test(__i, __val, false, __mo);
    }

    _GLIBCXX_ALWAYS_INLINE void
    _M_load_when_equal(unsigned __val, memory_order __mo)
    {
      unsigned __i = _M_load(__mo);
      if ((__i & ~_Waiter_bit) == __val)
	return;
      // TODO Spin-wait first.
      _M_load_and_test(__i, __val, true, __mo);
    }

    // Returns false iff a timeout occurred.
    template<typename _Rep, typename _Period>
      _GLIBCXX_ALWAYS_INLINE bool
      _M_load_when_equal_for(unsigned __val, memory_order __mo,
	  const chrono::duration<_Rep, _Period>& __rtime)
      {
	using __dur = typename __clock_t::duration;
	return _M_load_when_equal_until(__val, __mo,
		    __clock_t::now() + chrono::__detail::ceil<__dur>(__rtime));
      }

    // Returns false iff a timeout occurred.
    template<typename _Clock, typename _Duration>
      _GLIBCXX_ALWAYS_INLINE bool
      _M_load_when_equal_until(unsigned __val, memory_order __mo,
	  const chrono::time_point<_Clock, _Duration>& __atime)
      {
	typename _Clock::time_point __c_entry = _Clock::now();
	do {
	  const __clock_t::time_point __s_entry = __clock_t::now();
	  const auto __delta = __atime - __c_entry;
	  const auto __s_atime = __s_entry +
	      chrono::__detail::ceil<__clock_t::duration>(__delta);
	  if (_M_load_when_equal_until(__val, __mo, __s_atime))
	    return true;
	  __c_entry = _Clock::now();
	} while (__c_entry < __atime);
	return false;
      }

    // Returns false iff a timeout occurred.
    template<typename _Duration>
    _GLIBCXX_ALWAYS_INLINE bool
    _M_load_when_equal_until(unsigned __val, memory_order __mo,
	const chrono::time_point<std::chrono::system_clock, _Duration>& __atime)
    {
      unsigned __i = _M_load(__mo);
      if ((__i & ~_Waiter_bit) == __val)
	return true;
      // TODO Spin-wait first.  Ignore effect on timeout.
      __i = _M_load_and_test_until_impl(__i, __val, true, __mo, __atime);
      return (__i & ~_Waiter_bit) == __val;
    }

    // Returns false iff a timeout occurred.
    template<typename _Duration>
    _GLIBCXX_ALWAYS_INLINE bool
    _M_load_when_equal_until(unsigned __val, memory_order __mo,
	const chrono::time_point<std::chrono::steady_clock, _Duration>& __atime)
    {
      unsigned __i = _M_load(__mo);
      if ((__i & ~_Waiter_bit) == __val)
	return true;
      // TODO Spin-wait first.  Ignore effect on timeout.
      __i = _M_load_and_test_until_impl(__i, __val, true, __mo, __atime);
      return (__i & ~_Waiter_bit) == __val;
    }

    _GLIBCXX_ALWAYS_INLINE void
    _M_store_notify_all(unsigned __val, memory_order __mo)
    {
      unsigned* __futex = (unsigned *)(void *)&_M_data;
      if (_M_data.exchange(__val, __mo) & _Waiter_bit)
	_M_futex_notify_all(__futex);
    }
  };

#else // ! (_GLIBCXX_HAVE_LINUX_FUTEX && ATOMIC_INT_LOCK_FREE > 1)

  // If futexes are not available, use a mutex and a condvar to wait.
  // Because we access the data only within critical sections, all accesses
  // are sequentially consistent; thus, we satisfy any provided memory_order.
  template <unsigned _Waiter_bit = 0x80000000>
  class __atomic_futex_unsigned
  {
    typedef chrono::system_clock __clock_t;

    unsigned _M_data;
    mutex _M_mutex;
    condition_variable _M_condvar;

  public:
    explicit
    __atomic_futex_unsigned(unsigned __data) : _M_data(__data)
    { }

    _GLIBCXX_ALWAYS_INLINE unsigned
    _M_load(memory_order __mo)
    {
      unique_lock<mutex> __lock(_M_mutex);
      return _M_data;
    }

    _GLIBCXX_ALWAYS_INLINE unsigned
    _M_load_when_not_equal(unsigned __val, memory_order __mo)
    {
      unique_lock<mutex> __lock(_M_mutex);
      while (_M_data == __val)
	_M_condvar.wait(__lock);
      return _M_data;
    }

    _GLIBCXX_ALWAYS_INLINE void
    _M_load_when_equal(unsigned __val, memory_order __mo)
    {
      unique_lock<mutex> __lock(_M_mutex);
      while (_M_data != __val)
	_M_condvar.wait(__lock);
    }

    template<typename _Rep, typename _Period>
      _GLIBCXX_ALWAYS_INLINE bool
      _M_load_when_equal_for(unsigned __val, memory_order __mo,
	  const chrono::duration<_Rep, _Period>& __rtime)
      {
	unique_lock<mutex> __lock(_M_mutex);
	return _M_condvar.wait_for(__lock, __rtime,
				   [&] { return _M_data == __val;});
      }

    template<typename _Clock, typename _Duration>
      _GLIBCXX_ALWAYS_INLINE bool
      _M_load_when_equal_until(unsigned __val, memory_order __mo,
	  const chrono::time_point<_Clock, _Duration>& __atime)
      {
	unique_lock<mutex> __lock(_M_mutex);
	return _M_condvar.wait_until(__lock, __atime,
				     [&] { return _M_data == __val;});
      }

    _GLIBCXX_ALWAYS_INLINE void
    _M_store_notify_all(unsigned __val, memory_order __mo)
    {
      unique_lock<mutex> __lock(_M_mutex);
      _M_data = __val;
      _M_condvar.notify_all();
    }
  };

#endif // _GLIBCXX_HAVE_LINUX_FUTEX && ATOMIC_INT_LOCK_FREE > 1
#endif // _GLIBCXX_HAS_GTHREADS

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace std

#endif
