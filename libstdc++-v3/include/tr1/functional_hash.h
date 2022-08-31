// TR1 functional_hash.h header -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

/** @file tr1/functional_hash.h
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly. @headername{tr1/functional}
 */

#ifndef _GLIBCXX_TR1_FUNCTIONAL_HASH_H
#define _GLIBCXX_TR1_FUNCTIONAL_HASH_H 1

#pragma GCC system_header

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

namespace tr1
{
// Ignore warnings about std::unary_function and std::binary_function.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

  /// Class template hash.
  // Declaration of default hash functor std::tr1::hash.  The types for
  // which std::tr1::hash<T> is well-defined is in clause 6.3.3. of the PDTR.
  template<typename _Tp>
    struct hash : public std::unary_function<_Tp, size_t>
    {
      size_t
      operator()(_Tp __val) const;
    };

  /// Partial specializations for pointer types.
  template<typename _Tp>
    struct hash<_Tp*> : public std::unary_function<_Tp*, size_t>
    {
      size_t
      operator()(_Tp* __p) const
      { return reinterpret_cast<size_t>(__p); }
    };
#pragma GCC diagnostic pop

  /// Explicit specializations for integer types.
#define _TR1_hashtable_define_trivial_hash(_Tp) 	\
  template<>						\
    inline size_t					\
    hash<_Tp>::operator()(_Tp __val) const		\
    { return static_cast<size_t>(__val); }

  _TR1_hashtable_define_trivial_hash(bool);
  _TR1_hashtable_define_trivial_hash(char);
  _TR1_hashtable_define_trivial_hash(signed char);
  _TR1_hashtable_define_trivial_hash(unsigned char);
  _TR1_hashtable_define_trivial_hash(wchar_t);
  _TR1_hashtable_define_trivial_hash(short);
  _TR1_hashtable_define_trivial_hash(int);
  _TR1_hashtable_define_trivial_hash(long);
  _TR1_hashtable_define_trivial_hash(long long);
  _TR1_hashtable_define_trivial_hash(unsigned short);
  _TR1_hashtable_define_trivial_hash(unsigned int);
  _TR1_hashtable_define_trivial_hash(unsigned long);
  _TR1_hashtable_define_trivial_hash(unsigned long long);

#undef _TR1_hashtable_define_trivial_hash

  // Fowler / Noll / Vo (FNV) Hash (type FNV-1a)
  // (Used by the next specializations of std::tr1::hash.)

  // N.B. These functions should work on unsigned char, otherwise they do not
  // correctly implement the FNV-1a algorithm (see PR59406).
  // The existing behaviour is retained for backwards compatibility.

  /// Dummy generic implementation (for sizeof(size_t) != 4, 8).
  template<size_t>
    struct _Fnv_hash_base
    {
      template<typename _Tp>
        static size_t
        hash(const _Tp* __ptr, size_t __clength)
        {
	  size_t __result = 0;
	  const char* __cptr = reinterpret_cast<const char*>(__ptr);
	  for (; __clength; --__clength)
	    __result = (__result * 131) + *__cptr++;
	  return __result;
	}
    };

  template<>
    struct _Fnv_hash_base<4>
    {
      template<typename _Tp>
        static size_t
        hash(const _Tp* __ptr, size_t __clength)
        {
	  size_t __result = static_cast<size_t>(2166136261UL);
	  const char* __cptr = reinterpret_cast<const char*>(__ptr);
	  for (; __clength; --__clength)
	    {
	      __result ^= static_cast<size_t>(*__cptr++);
	      __result *= static_cast<size_t>(16777619UL);
	    }
	  return __result;
	}
    };
  
  template<>
    struct _Fnv_hash_base<8>
    {
      template<typename _Tp>
        static size_t
        hash(const _Tp* __ptr, size_t __clength)
        {
	  size_t __result
	    = static_cast<size_t>(14695981039346656037ULL);
	  const char* __cptr = reinterpret_cast<const char*>(__ptr);
	  for (; __clength; --__clength)
	    {
	      __result ^= static_cast<size_t>(*__cptr++);
	      __result *= static_cast<size_t>(1099511628211ULL);
	    }
	  return __result;
	}
    };

  struct _Fnv_hash
  : public _Fnv_hash_base<sizeof(size_t)>
  {
    using _Fnv_hash_base<sizeof(size_t)>::hash;

    template<typename _Tp>
      static size_t
      hash(const _Tp& __val)
      { return hash(&__val, sizeof(__val)); }
  };

  /// Explicit specializations for float.
  template<>
    inline size_t
    hash<float>::operator()(float __val) const
    {
      // 0 and -0 both hash to zero.
      return __val != 0.0f ? std::tr1::_Fnv_hash::hash(__val) : 0;
    }

  /// Explicit specializations for double.
  template<>
    inline size_t
    hash<double>::operator()(double __val) const
    {
      // 0 and -0 both hash to zero.
      return __val != 0.0 ? std::tr1::_Fnv_hash::hash(__val) : 0;
    }

  /// Explicit specializations for long double.
  template<>
    _GLIBCXX_PURE size_t
    hash<long double>::operator()(long double __val) const;

  /// Explicit specialization of member operator for non-builtin types.
  template<>
    _GLIBCXX_PURE size_t
    hash<string>::operator()(string) const;

  template<>
    _GLIBCXX_PURE size_t
    hash<const string&>::operator()(const string&) const;

#ifdef _GLIBCXX_USE_WCHAR_T
  template<>
    _GLIBCXX_PURE size_t
    hash<wstring>::operator()(wstring) const;

  template<>
    _GLIBCXX_PURE size_t
    hash<const wstring&>::operator()(const wstring&) const;
#endif
}

_GLIBCXX_END_NAMESPACE_VERSION
}

#endif // _GLIBCXX_TR1_FUNCTIONAL_HASH_H
