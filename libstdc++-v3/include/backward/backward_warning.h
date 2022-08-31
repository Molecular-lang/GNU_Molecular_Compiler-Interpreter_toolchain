// Please review: $(src-dir)/SPL-README for Licencing info.

/** @file backward/backward_warning.h
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly. @headername{iosfwd}
 */

#ifndef _BACKWARD_BACKWARD_WARNING_H
#define _BACKWARD_BACKWARD_WARNING_H 1

#ifdef __DEPRECATED
#warning \
  This file includes at least one deprecated or antiquated header which \
  may be removed without further notice at a future date. Please use a \
  non-deprecated interface with equivalent functionality instead. For a \
  listing of replacement headers and interfaces, consult the file \
  backward_warning.h. To disable this warning use -Wno-deprecated.

/*
  A list of valid replacements is as follows:

  Use:					Instead of:
  <sstream>, basic_stringbuf	   	<strstream>, strstreambuf
  <sstream>, basic_istringstream	<strstream>, istrstream
  <sstream>, basic_ostringstream	<strstream>, ostrstream
  <sstream>, basic_stringstream		<strstream>, strstream
  <unordered_set>, unordered_set     	<ext/hash_set>, hash_set
  <unordered_set>, unordered_multiset	<ext/hash_set>, hash_multiset
  <unordered_map>, unordered_map	<ext/hash_map>, hash_map
  <unordered_map>, unordered_multimap	<ext/hash_map>, hash_multimap
  <functional>, bind			<functional>, binder1st
  <functional>, bind			<functional>, binder2nd
  <functional>, bind			<functional>, bind1st
  <functional>, bind			<functional>, bind2nd
  <memory>, unique_ptr       		<memory>, auto_ptr
*/

#endif

#endif
