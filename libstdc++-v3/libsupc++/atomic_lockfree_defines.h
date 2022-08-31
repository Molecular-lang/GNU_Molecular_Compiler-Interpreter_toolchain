// -*- C++ -*- header.

// Please review $(srcdir/SPL-README) for GNU licencing info.

/** @file bits/atomic_lockfree_defines.h
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly. @headername{atomic}
 */

#ifndef _GLIBCXX_ATOMIC_LOCK_FREE_H
#define _GLIBCXX_ATOMIC_LOCK_FREE_H 1

#pragma GCC system_header

/**
 * @addtogroup atomics
 * @{
 */

/**
 * Lock-free property.
 *
 * 0 indicates that the types are never lock-free.
 * 1 indicates that the types are sometimes lock-free.
 * 2 indicates that the types are always lock-free.
 */

#if __cplusplus >= 201103L
#define ATOMIC_BOOL_LOCK_FREE		__GCC_ATOMIC_BOOL_LOCK_FREE
#define ATOMIC_CHAR_LOCK_FREE		__GCC_ATOMIC_CHAR_LOCK_FREE
#define ATOMIC_WCHAR_T_LOCK_FREE	__GCC_ATOMIC_WCHAR_T_LOCK_FREE
#ifdef _GLIBCXX_USE_CHAR8_T
#define ATOMIC_CHAR8_T_LOCK_FREE	__GCC_ATOMIC_CHAR8_T_LOCK_FREE
#endif
#define ATOMIC_CHAR16_T_LOCK_FREE	__GCC_ATOMIC_CHAR16_T_LOCK_FREE
#define ATOMIC_CHAR32_T_LOCK_FREE	__GCC_ATOMIC_CHAR32_T_LOCK_FREE
#define ATOMIC_SHORT_LOCK_FREE		__GCC_ATOMIC_SHORT_LOCK_FREE
#define ATOMIC_INT_LOCK_FREE		__GCC_ATOMIC_INT_LOCK_FREE
#define ATOMIC_LONG_LOCK_FREE		__GCC_ATOMIC_LONG_LOCK_FREE
#define ATOMIC_LLONG_LOCK_FREE		__GCC_ATOMIC_LLONG_LOCK_FREE
#define ATOMIC_POINTER_LOCK_FREE	__GCC_ATOMIC_POINTER_LOCK_FREE
#endif

/// @} group atomics

#endif
