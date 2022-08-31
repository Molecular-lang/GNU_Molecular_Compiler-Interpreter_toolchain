// -*- C++ -*- std::exception implementation.
// Please review $(srcdir/SPL-README) for GNU licencing info.

#include "typeinfo"
#include "exception"
#include <cxxabi.h>

std::exception::~exception() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT { }

std::bad_exception::~bad_exception() _GLIBCXX_TXN_SAFE_DYN
    _GLIBCXX_USE_NOEXCEPT
{ }

abi::__forced_unwind::~__forced_unwind() throw() { }

abi::__foreign_exception::~__foreign_exception() throw() { }

const char* 
std::exception::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT
{
  // NB: Another elegant option would be returning typeid(*this).name()
  // and not overriding what() in bad_exception, bad_alloc, etc.  In
  // that case, however, mangled names would be returned, PR 14493.
  return "std::exception";
}

const char* 
std::bad_exception::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT
{
  return "std::bad_exception";
}

// Transactional clones for the destructors and what().
// what() is effectively transaction_pure, but we do not want to annotate it
// as such; thus, we call exactly the respective nontransactional function.
extern "C" {

void
_ZGTtNKSt9exceptionD1Ev(const std::exception*)
{ }

const char*
_ZGTtNKSt9exception4whatEv(const std::exception* that)
{
  // We really want the non-virtual call here.  We already executed the
  // indirect call representing the virtual call, and the TM runtime or the
  // compiler resolved it to this transactional clone.  In the clone, we want
  // to do the same as for the nontransactional original, so we just call it.
  return that->std::exception::what();
}

void
_ZGTtNKSt13bad_exceptionD1Ev(
    const std::bad_exception*)
{ }

const char*
_ZGTtNKSt13bad_exception4whatEv(
    const std::bad_exception* that)
{
  // Also see _ZGTtNKSt9exception4whatEv.
  return that->std::bad_exception::what();
}

}
