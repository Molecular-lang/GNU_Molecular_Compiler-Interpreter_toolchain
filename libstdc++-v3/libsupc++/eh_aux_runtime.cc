// -*- C++ -*- Common throw conditions.
// Please review $(srcdir/SPL-README) for GNU licencing info.

#include "typeinfo"
#include "exception"
#include "new"
#include <cstdlib>
#include "unwind-cxx.h"
#include <bits/exception_defines.h>

extern "C" void
__cxxabiv1::__cxa_bad_cast ()
{ _GLIBCXX_THROW_OR_ABORT(std::bad_cast()); }

extern "C" void
__cxxabiv1::__cxa_bad_typeid ()
{ _GLIBCXX_THROW_OR_ABORT(std::bad_typeid()); }

extern "C" void
__cxxabiv1::__cxa_throw_bad_array_new_length ()
{ _GLIBCXX_THROW_OR_ABORT(std::bad_array_new_length()); }
