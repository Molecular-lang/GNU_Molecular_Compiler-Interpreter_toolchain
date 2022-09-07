// -*- C++ -*- Helpers for calling unextected and terminate
// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <bits/c++config.h>
#include <cstdlib>
#include <bits/exception_defines.h>
#include "unwind-cxx.h"

using namespace __cxxabiv1;

#include "unwind-pe.h"


// Helper routine for when the exception handling code needs to call
// terminate.

extern "C" void
__cxa_call_terminate(_Unwind_Exception* ue_header) throw ()
{

  if (ue_header)
    {
      // terminate is classed as a catch handler.
      __cxa_begin_catch(ue_header);

      // Call the terminate handler that was in effect when we threw this
      // exception.  */
      if (__is_gxx_exception_class(ue_header->exception_class))
	{
	  __cxa_exception* xh;

	  xh = __get_exception_header_from_ue(ue_header);
	  __terminate(xh->terminateHandler);
	}
    }
  /* Call the global routine if we don't have anything better.  */
  std::terminate();
}


#ifdef __ARM_EABI_UNWINDER__
// The ARM EABI __cxa_call_unexpected has the same semantics as the generic
// routine, but the exception specification has a different format.
extern "C" void
__cxa_call_unexpected(void* exc_obj_in)
{
  _Unwind_Exception* exc_obj
    = reinterpret_cast<_Unwind_Exception*>(exc_obj_in);

  int rtti_count = 0;
  _Unwind_Word rtti_stride = 0;
  _Unwind_Word* rtti_list = NULL;
  _Unwind_Ptr rtti_base = 0;
  bool foreign_exception;
  std::unexpected_handler unexpectedHandler = NULL;
  std::terminate_handler terminateHandler = NULL;
  __cxa_exception* xh;
  if (__is_gxx_exception_class(exc_obj->exception_class))
    {
      // Save data from the EO, which may be clobbered by _cxa_begin_catch.
      xh = __get_exception_header_from_ue(exc_obj);
      unexpectedHandler = xh->unexpectedHandler;
      terminateHandler = xh->terminateHandler;
      rtti_count = exc_obj->barrier_cache.bitpattern[1];
      rtti_base = (_Unwind_Ptr) exc_obj->barrier_cache.bitpattern[2];
      rtti_stride = exc_obj->barrier_cache.bitpattern[3];
      rtti_list = (_Unwind_Word*) exc_obj->barrier_cache.bitpattern[4];
      foreign_exception = false;
    }
  else
    foreign_exception = true;

  /* This must be called after extracting data from the EO, but before
     calling unexpected().   */
  __cxa_begin_catch(exc_obj);

  // This function is a handler for our exception argument.  If we exit
  // by throwing a different exception, we'll need the original cleaned up.
  struct end_catch_protect
  {
    end_catch_protect() { }
    ~end_catch_protect() { __cxa_end_catch(); }
  } end_catch_protect_obj;


  __try
    {
      if (foreign_exception)
	std::unexpected();
      else
	__unexpected(unexpectedHandler);
    }
  __catch(...)
    {
      /* See if the new exception matches the rtti list.  */
      if (foreign_exception)
	std::terminate();

      // Get the exception thrown from unexpected.

      __cxa_eh_globals* globals = __cxa_get_globals_fast();
      __cxa_exception* new_xh = globals->caughtExceptions;
      void* new_ptr = __get_object_from_ambiguous_exception (new_xh);
      const std::type_info* catch_type;
      int n;
      bool bad_exception_allowed __attribute__((unused)) = false;
      const std::type_info& bad_exc = typeid(std::bad_exception);

      // Check the new exception against the rtti list
      for (n = 0; n < rtti_count; n++)
	{
	  _Unwind_Word offset;

	  offset = (_Unwind_Word) &rtti_list[n * (rtti_stride >> 2)];
	  offset = _Unwind_decode_typeinfo_ptr(rtti_base, offset);
	  catch_type = (const std::type_info*) (offset);

	  if (__cxa_type_match(&new_xh->unwindHeader, catch_type, false,
			       &new_ptr) != ctm_failed)
	    { __throw_exception_again; }

	  // If the exception spec allows std::bad_exception, throw that.
	  // We don't have a thrown object to compare against, but since
	  // bad_exception doesn't have virtual bases, that's OK; just pass NULL.
	  void* obj = NULL;
	  if (catch_type->__do_catch(&bad_exc, &obj, 1))
	    bad_exception_allowed = true;
	}

      // If the exception spec allows std::bad_exception, throw that.
#if __cpp_exceptions
      if (bad_exception_allowed)
	throw std::bad_exception();
#endif

      // Otherwise, die.
      __terminate(terminateHandler);
    }
}
#endif // __ARM_EABI_UNWINDER__
