// condition_variable -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <condition_variable>
#include <cstdlib>

#ifdef _GLIBCXX_HAS_GTHREADS

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  condition_variable::condition_variable() noexcept = default;

  condition_variable::~condition_variable() noexcept = default;

  void
  condition_variable::wait(unique_lock<mutex>& __lock)
  {
    _M_cond.wait(*__lock.mutex());
  }

  void
  condition_variable::notify_one() noexcept
  {
    _M_cond.notify_one();
  }

  void
  condition_variable::notify_all() noexcept
  {
    _M_cond.notify_all();
  }

  extern void
  __at_thread_exit(__at_thread_exit_elt*);

  namespace
  {
    __gthread_key_t key;

    void run(void* p)
    {
      auto elt = (__at_thread_exit_elt*)p;
      while (elt)
	{
	  auto next = elt->_M_next;
	  elt->_M_cb(elt);
	  elt = next;
	}
    }

    void run()
    {
      auto elt = (__at_thread_exit_elt*)__gthread_getspecific(key);
      __gthread_setspecific(key, nullptr);
      run(elt);
    }

    struct notifier final : __at_thread_exit_elt
    {
      notifier(condition_variable& cv, unique_lock<mutex>& l)
      : cv(&cv), mx(l.release())
      {
	_M_cb = &notifier::run;
	__at_thread_exit(this);
      }

      ~notifier()
      {
	mx->unlock();
	cv->notify_all();
      }

      condition_variable* cv;
      mutex* mx;

      static void run(void* p) { delete static_cast<notifier*>(p); }
    };


    void key_init() {
      struct key_s {
	key_s() { __gthread_key_create (&key, run); }
	~key_s() { __gthread_key_delete (key); }
      };
      static key_s ks;
      // Also make sure the callbacks are run by std::exit.
      std::atexit (run);
    }
  }

  void
  __at_thread_exit(__at_thread_exit_elt* elt)
  {
    static __gthread_once_t once = __GTHREAD_ONCE_INIT;
    __gthread_once (&once, key_init);

    elt->_M_next = (__at_thread_exit_elt*)__gthread_getspecific(key);
    __gthread_setspecific(key, elt);
  }

  void
  notify_all_at_thread_exit(condition_variable& cv, unique_lock<mutex> l)
  {
    (void) new notifier{cv, l};
  }

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace

#endif // _GLIBCXX_HAS_GTHREADS
