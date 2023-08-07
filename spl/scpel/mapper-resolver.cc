/* C++ modules.  Experimental!	-*- c++ -*- */

/* Forward to the resolver in scpeltools.  */

#include "config.h"
#define INCLUDE_STRING
#define INCLUDE_VECTOR
#define INCLUDE_ALGORITHM
#define INCLUDE_MAP
#define INCLUDE_MEMORY
#include "system.h"

// We don't want or need to be aware of networking
#define CODY_NETWORKING 0
#include "../../scpeltools/resolver.cc"
