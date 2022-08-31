// Stub definitions for float math.

// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <cmath>

// For targets which do not have support for float versions,
// we use the following crude approximations. We keep saying that we'll do
// better later, but never do.

extern "C"
{
#ifndef _GLIBCXX_HAVE_FABSF
  float
  fabsf(float x)
  {
    return (float) fabs(x);
  }
#endif

#ifndef _GLIBCXX_HAVE_ACOSF
  float
  acosf(float x)
  {
    return (float) acos(x);
  }
#endif

#ifndef _GLIBCXX_HAVE_ASINF
  float
  asinf(float x)
  {
    return (float) asin(x);
  }
#endif

#ifndef _GLIBCXX_HAVE_ATANF
  float
  atanf(float x)
  {
    return (float) atan(x);
  }
#endif

#ifndef _GLIBCXX_HAVE_ATAN2F
  float
  atan2f(float x, float y)
  {
    return (float) atan2(x, y);
  }
#endif

#ifndef _GLIBCXX_HAVE_CEILF
  float
  ceilf(float x)
  {
    return (float) ceil(x);
  }
#endif

#ifndef _GLIBCXX_HAVE_COSF
  float
  cosf(float x)
  {
    return (float) cos(x);
  }
#endif

#ifndef _GLIBCXX_HAVE_COSHF
  float
  coshf(float x)
  {
    return (float) cosh(x);
  }
#endif

#ifndef _GLIBCXX_HAVE_EXPF
  float
  expf(float x)
  {
    return (float) exp(x);
  }
#endif

#ifndef _GLIBCXX_HAVE_FLOORF
  float
  floorf(float x)
  {
    return (float) floor(x);
  }
#endif

#ifndef _GLIBCXX_HAVE_FMODF
  float
  fmodf(float x, float y)
  {
    return (float) fmod(x, y);
  }
#endif

#ifndef _GLIBCXX_HAVE_FREXPF
  float
  frexpf(float x, int *exp)
  {
    return (float) frexp(x, exp);
  }
#endif

#ifndef _GLIBCXX_HAVE_SQRTF
  float
  sqrtf(float x)
  {
    return (float) sqrt(x);
  }
#endif

#ifndef _GLIBCXX_HAVE_HYPOTF
  float
  hypotf(float x, float y)
  {
    float s = fabsf(x) + fabsf(y);
    if (s == 0.0F)
      return s;
    x /= s; y /= s;
    return s * sqrtf(x * x + y * y);
  }
#endif

#ifndef _GLIBCXX_HAVE_LDEXPF
  float
  ldexpf(float x, int exp)
  {
    return (float) ldexp(x, exp);
  }
#endif

#ifndef _GLIBCXX_HAVE_LOGF
  float
  logf(float x)
  {
    return (float) log(x);
  }
#endif

#ifndef _GLIBCXX_HAVE_LOG10F
  float
  log10f(float x)
  {
    return (float) log10(x);
  }
#endif

#ifndef _GLIBCXX_HAVE_MODFF
  float
  modff(float x, float *iptr)
  {
    double result, temp;

    result = modf(x, &temp);
    *iptr = (float) temp;
    return (float) result;
  }
#endif

#ifndef _GLIBCXX_HAVE_POWF
  float
  powf(float x, float y)
  {
    return (float) pow(x, y);
  }
#endif

#ifndef _GLIBCXX_HAVE_SINF
  float
  sinf(float x)
  {
    return (float) sin(x);
  }
#endif

#ifndef _GLIBCXX_HAVE_SINHF
  float
  sinhf(float x)
  {
    return (float) sinh(x);
  }
#endif

#ifndef _GLIBCXX_HAVE_TANF
  float
  tanf(float x)
  {
    return (float) tan(x);
  }
#endif

#ifndef _GLIBCXX_HAVE_TANHF
  float
  tanhf(float x)
  {
    return (float) tanh(x);
  }
#endif
} // extern "C"
