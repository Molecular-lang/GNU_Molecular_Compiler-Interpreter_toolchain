// cxxabi.h subset for cancellation -*- C++ -*-
  
// Please review $(srcdir/SPL-README) for GNU licencing info.

#ifndef _CXXABI_FORCED_H
#define _CXXABI_FORCED_H 1

#pragma GCC system_header

#pragma GCC visibility push(default)

#ifdef __cplusplus
namespace __cxxabiv1
{  
  /** 
   *  @brief Thrown as part of forced unwinding.
   *  @ingroup exceptions
   *
   *  A magic placeholder class that can be caught by reference to
   *  recognize forced unwinding.
   */
  class __forced_unwind
  {
    virtual ~__forced_unwind() throw();

    // Prevent catch by value.
    virtual void __pure_dummy() = 0; 
  };
}
#endif // __cplusplus

#pragma GCC visibility pop

#endif // __CXXABI_FORCED_H 
