// mutex -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <mutex>

#ifdef _GLIBCXX_HAS_GTHREADS

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

#ifdef _GLIBCXX_HAVE_TLS
  __thread void* __once_callable;
  __thread void (*__once_call)();

  extern "C" void __once_proxy()
  {
    // The caller stored a function pointer in __once_call. If it requires
    // any state, it gets it from __once_callable.
    __once_call();
  }

#else // ! TLS

  // Explicit instantiation due to -fno-implicit-instantiation.
  template class function<void()>;

  function<void()> __once_functor;

  mutex&
  __get_once_mutex()
  {
    static mutex once_mutex;
    return once_mutex;
  }

namespace
{
  // Store ptr in a global variable and return the previous value.
  inline unique_lock<mutex>*
  set_lock_ptr(unique_lock<mutex>* ptr)
  {
    static unique_lock<mutex>* __once_functor_lock_ptr = nullptr;
    return std::__exchange(__once_functor_lock_ptr, ptr);
  }
}

  // code linked against ABI 3.4.12 and later uses this
  void
  __set_once_functor_lock_ptr(unique_lock<mutex>* __ptr)
  {
    (void) set_lock_ptr(__ptr);
  }

  // unsafe - retained for compatibility with ABI 3.4.11
  unique_lock<mutex>&
  __get_once_functor_lock()
  {
    static unique_lock<mutex> once_functor_lock(__get_once_mutex(), defer_lock);
    return once_functor_lock;
  }

  // This is called via pthread_once while __get_once_mutex() is locked.
  extern "C" void
  __once_proxy()
  {
    // Get the callable out of the global functor.
    function<void()> callable = std::move(__once_functor);

    // Then unlock the global mutex
    if (unique_lock<mutex>* lock = set_lock_ptr(nullptr))
    {
      // Caller is using the new ABI and provided a pointer to its lock.
      lock->unlock();
    }
    else
      __get_once_functor_lock().unlock();  // global lock

    // Finally, invoke the callable.
    callable();
  }
#endif // ! TLS

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace std

#endif // _GLIBCXX_HAS_GTHREADS
