// C++ includes used for precompiling extensions -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

#if __cplusplus < 201103L
#include <bits/stdtr1c++.h>
#else
#include <bits/stdc++.h>
#endif

#include <ext/algorithm>
#if __cplusplus >= 201103L
# include <ext/aligned_buffer.h>
#endif
#include <ext/alloc_traits.h>
#include <ext/atomicity.h>
#include <ext/bitmap_allocator.h>
#include <ext/cast.h>
#if __cplusplus >= 201103L
# include <ext/cmath>
#endif
#include <ext/concurrence.h>
#include <ext/debug_allocator.h>
#include <ext/extptr_allocator.h>
#include <ext/functional>
#include <ext/iterator>
#include <ext/malloc_allocator.h>
#include <ext/memory>
#include <ext/mt_allocator.h>
#include <ext/new_allocator.h>
#include <ext/numeric>
#include <ext/numeric_traits.h>
#include <ext/pod_char_traits.h>
#include <ext/pointer.h>
#include <ext/pool_allocator.h>
#if __cplusplus >= 201103L
# include <ext/random>
#endif
#include <ext/rb_tree>
#include <ext/rope>
#include <ext/slist>
#include <ext/stdio_filebuf.h>
#include <ext/stdio_sync_filebuf.h>
#include <ext/throw_allocator.h>
#include <ext/typelist.h>
#include <ext/type_traits.h>
#include <ext/vstring.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/exception.hpp>
#include <ext/pb_ds/hash_policy.hpp>
#include <ext/pb_ds/list_update_policy.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>

#ifdef _GLIBCXX_HAVE_ICONV
 #include <ext/codecvt_specializations.h>
 #include <ext/enc_filebuf.h>
#endif
