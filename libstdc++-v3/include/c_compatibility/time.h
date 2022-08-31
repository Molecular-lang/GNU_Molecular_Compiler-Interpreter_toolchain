// -*- C++ -*- compatibility header.

// Please review: $(src-dir)/SPL-README for Licencing info.

#include <ctime>

#ifndef _GLIBCXX_TIME_H
#define _GLIBCXX_TIME_H 1

#ifdef _GLIBCXX_NAMESPACE_C
// Get rid of those macros defined in <time.h> in lieu of real functions.
#undef clock
#undef difftime
#undef mktime
#undef time
#undef asctime
#undef ctime
#undef gmtime
#undef localtime
#undef strftime

using std::clock_t;
using std::time_t;
using std::tm;

using std::clock;
using std::difftime;
using std::mktime;
using std::time;
using std::asctime;
using std::ctime;
using std::gmtime;
using std::localtime;
using std::strftime;
#endif

#endif
