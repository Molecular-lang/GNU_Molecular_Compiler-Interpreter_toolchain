// -*- C++ -*- Exception handling routines for throwing.
// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <bits/c++config.h>
#include "unwind-cxx.h"
#include "eh_atomics.h"

using namespace __cxxabiv1;


static void
__gxx_exception_cleanup (_Unwind_Reason_Code code, _Unwind_Exception *exc)
{
  // This cleanup is set only for primaries.
  __cxa_refcounted_exception *header
    = __get_refcounted_exception_header_from_ue (exc);

  // We only want to be called through _Unwind_DeleteException.
  // _Unwind_DeleteException in the HP-UX IA64 libunwind library
  // returns _URC_NO_REASON and not _URC_FOREIGN_EXCEPTION_CAUGHT
  // like the GCC _Unwind_DeleteException function does.
  if (code != _URC_FOREIGN_EXCEPTION_CAUGHT && code != _URC_NO_REASON)
    __terminate (header->exc.terminateHandler);

  if (__gnu_cxx::__eh_atomic_dec (&header->referenceCount))
    {
      if (header->exc.exceptionDestructor)
	header->exc.exceptionDestructor (header + 1);

      __cxa_free_exception (header + 1);
    }
}

extern "C" __cxa_refcounted_exception*
__cxxabiv1::
__cxa_init_primary_exception(void *obj, std::type_info *tinfo,
			     void (_GLIBCXX_CDTOR_CALLABI *dest) (void *))
_GLIBCXX_NOTHROW
{
  __cxa_refcounted_exception *header
    = __get_refcounted_exception_header_from_obj (obj);
  header->referenceCount = 0;
  header->exc.exceptionType = tinfo;
  header->exc.exceptionDestructor = dest;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
  header->exc.unexpectedHandler = std::get_unexpected ();
#pragma GCC diagnostic pop
  header->exc.terminateHandler = std::get_terminate ();
  __GXX_INIT_PRIMARY_EXCEPTION_CLASS(header->exc.unwindHeader.exception_class);
  header->exc.unwindHeader.exception_cleanup = __gxx_exception_cleanup;

  return header;
}

extern "C" void
__cxxabiv1::__cxa_throw (void *obj, std::type_info *tinfo,
			 void (_GLIBCXX_CDTOR_CALLABI *dest) (void *))
{
  PROBE2 (throw, obj, tinfo);

  __cxa_eh_globals *globals = __cxa_get_globals ();
  globals->uncaughtExceptions += 1;
  // Definitely a primary.
  __cxa_refcounted_exception *header =
    __cxa_init_primary_exception(obj, tinfo, dest);
  header->referenceCount = 1;

#ifdef __USING_SJLJ_EXCEPTIONS__
  _Unwind_SjLj_RaiseException (&header->exc.unwindHeader);
#else
  _Unwind_RaiseException (&header->exc.unwindHeader);
#endif

  // Some sort of unwinding error.  Note that terminate is a handler.
  __cxa_begin_catch (&header->exc.unwindHeader);
  std::terminate ();
}

extern "C" void
__cxxabiv1::__cxa_rethrow ()
{
  __cxa_eh_globals *globals = __cxa_get_globals ();
  __cxa_exception *header = globals->caughtExceptions;

  globals->uncaughtExceptions += 1;

  // Watch for luser rethrowing with no active exception.
  if (header)
    {
      // Tell __cxa_end_catch this is a rethrow.
      if (!__is_gxx_exception_class(header->unwindHeader.exception_class))
	globals->caughtExceptions = 0;
      else
	{
	  header->handlerCount = -header->handlerCount;
	  // Only notify probe for C++ exceptions.
	  PROBE2 (rethrow, __get_object_from_ambiguous_exception(header),
		  header->exceptionType);
	}

#ifdef __USING_SJLJ_EXCEPTIONS__
      _Unwind_SjLj_Resume_or_Rethrow (&header->unwindHeader);
#else
#if defined(_LIBUNWIND_STD_ABI)
      _Unwind_RaiseException (&header->unwindHeader);
#else
      _Unwind_Resume_or_Rethrow (&header->unwindHeader);
#endif
#endif
  
      // Some sort of unwinding error.  Note that terminate is a handler.
      __cxa_begin_catch (&header->unwindHeader);
    }
  std::terminate ();
}
