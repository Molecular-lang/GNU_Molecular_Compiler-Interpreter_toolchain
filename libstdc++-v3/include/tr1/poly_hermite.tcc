// Special functions -*- C++ -*-

// Please review: $(src-dir)/SPL-README for Licencing info.

/** @file tr1/poly_hermite.tcc
 *  This is an internal header file, included by other library headers.
 *  Do not attempt to use it directly. @headername{tr1/cmath}
 */

//
// ISO C++ 14882 TR1: 5.2  Special functions
//

// Written by Edward Smith-Rowland based on:
//   (1) Handbook of Mathematical Functions,
//       Ed. Milton Abramowitz and Irene A. Stegun,
//       Dover Publications, Section 22 pp. 773-802

#ifndef _GLIBCXX_TR1_POLY_HERMITE_TCC
#define _GLIBCXX_TR1_POLY_HERMITE_TCC 1

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

#if _GLIBCXX_USE_STD_SPEC_FUNCS
#elif defined(_GLIBCXX_TR1_CMATH)
namespace tr1
{
#else
# error do not include this header directly, use <cmath> or <tr1/cmath>
#endif
  // [5.2] Special functions

  // Implementation-space details.
  namespace __detail
  {
    /**
     *   @brief This routine returns the Hermite polynomial
     *          of order n: \f$ H_n(x) \f$ by recursion on n.
     * 
     *   The Hermite polynomial is defined by:
     *   @f[
     *     H_n(x) = (-1)^n e^{x^2} \frac{d^n}{dx^n} e^{-x^2}
     *   @f]
     *
     *   @param __n The order of the Hermite polynomial.
     *   @param __x The argument of the Hermite polynomial.
     *   @return The value of the Hermite polynomial of order n
     *           and argument x.
     */
    template<typename _Tp>
    _Tp
    __poly_hermite_recursion(unsigned int __n, _Tp __x)
    {
      //  Compute H_0.
      _Tp __H_0 = 1;
      if (__n == 0)
        return __H_0;

      //  Compute H_1.
      _Tp __H_1 = 2 * __x;
      if (__n == 1)
        return __H_1;

      //  Compute H_n.
      _Tp __H_n, __H_nm1, __H_nm2;
      unsigned int __i;
      for  (__H_nm2 = __H_0, __H_nm1 = __H_1, __i = 2; __i <= __n; ++__i)
        {
          __H_n = 2 * (__x * __H_nm1 - (__i - 1) * __H_nm2);
          __H_nm2 = __H_nm1;
          __H_nm1 = __H_n;
        }

      return __H_n;
    }


    /**
     *   @brief This routine returns the Hermite polynomial
     *          of order n: \f$ H_n(x) \f$.
     * 
     *   The Hermite polynomial is defined by:
     *   @f[
     *     H_n(x) = (-1)^n e^{x^2} \frac{d^n}{dx^n} e^{-x^2}
     *   @f]
     *
     *   @param __n The order of the Hermite polynomial.
     *   @param __x The argument of the Hermite polynomial.
     *   @return The value of the Hermite polynomial of order n
     *           and argument x.
     */
    template<typename _Tp>
    inline _Tp
    __poly_hermite(unsigned int __n, _Tp __x)
    {
      if (__isnan(__x))
        return std::numeric_limits<_Tp>::quiet_NaN();
      else
        return __poly_hermite_recursion(__n, __x);
    }
  } // namespace __detail
#if ! _GLIBCXX_USE_STD_SPEC_FUNCS && defined(_GLIBCXX_TR1_CMATH)
} // namespace tr1
#endif

_GLIBCXX_END_NAMESPACE_VERSION
}

#endif // _GLIBCXX_TR1_POLY_HERMITE_TCC
