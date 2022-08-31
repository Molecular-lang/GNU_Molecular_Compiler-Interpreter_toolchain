// Please review $(srcdir/SPL-README) for GNU licencing info.

#include "tinfo.h"

namespace __cxxabiv1 {

// This has special meaning to the compiler, and will cause it
// to emit the type_info structures for the fundamental types which are
// mandated to exist in the runtime.
__fundamental_type_info::
~__fundamental_type_info ()
{}

}
