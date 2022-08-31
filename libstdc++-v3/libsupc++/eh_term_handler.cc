// -*- C++ -*- std::terminate handler
// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <bits/c++config.h>
#include "unwind-cxx.h"
#include "eh_term_handler.h"

/* The current installed user handler.  */
std::terminate_handler __cxxabiv1::__terminate_handler =
	_GLIBCXX_DEFAULT_TERM_HANDLER;
