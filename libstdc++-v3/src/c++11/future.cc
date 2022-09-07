// future -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <future>
#include <bits/functexcept.h>

#if __has_cpp_attribute(clang::require_constant_initialization)
#  define __constinit [[clang::require_constant_initialization]]
#endif

namespace
{
  struct future_error_category final : public std::error_category
  {
    const char*
    name() const noexcept final
    { return "future"; }

    _GLIBCXX_DEFAULT_ABI_TAG
    std::string
    message(int __ec) const final
    {
      std::string __msg;
      switch (std::future_errc(__ec))
      {
      case std::future_errc::broken_promise:
          __msg = "Broken promise";
          break;
      case std::future_errc::future_already_retrieved:
          __msg = "Future already retrieved";
          break;
      case std::future_errc::promise_already_satisfied:
          __msg = "Promise already satisfied";
          break;
      case std::future_errc::no_state:
          __msg = "No associated state";
          break;
      default:
          __msg = "Unknown error";
          break;
      }
      return __msg;
    }
  };

  struct constant_init
  {
    union {
      unsigned char unused;
      future_error_category cat;
    };
    constexpr constant_init() : cat() { }
    ~constant_init() { /* do nothing, union member is not destroyed */ }
  };

  __constinit constant_init future_category_instance{};
}

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  void
  __throw_future_error(int __i __attribute__((unused)))
  { _GLIBCXX_THROW_OR_ABORT(future_error(make_error_code(future_errc(__i)))); }

  const error_category& future_category() noexcept
  { return future_category_instance.cat; }

  future_error::~future_error() noexcept { }

  const char*
  future_error::what() const noexcept { return logic_error::what(); }

#ifdef _GLIBCXX_HAS_GTHREADS
  __future_base::_Result_base::_Result_base() = default;

  __future_base::_Result_base::~_Result_base() = default;

  void
  __future_base::_State_baseV2::_Make_ready::_S_run(void* p)
  {
    unique_ptr<_Make_ready> mr{static_cast<_Make_ready*>(p)};
    if (auto state = mr->_M_shared_state.lock())
      {
	// Use release MO to synchronize with observers of the ready state.
	state->_M_status._M_store_notify_all(_Status::__ready,
	    memory_order_release);
      }
  }

  // defined in src/c++11/condition_variable.cc
  extern void
  __at_thread_exit(__at_thread_exit_elt* elt);

  void
  __future_base::_State_baseV2::_Make_ready::_M_set()
  {
    _M_cb = &_Make_ready::_S_run;
    __at_thread_exit(this);
  }
#endif // _GLIBCXX_HAS_GTHREADS

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace std
