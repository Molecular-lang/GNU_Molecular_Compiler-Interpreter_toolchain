/* Subroutines for long double support.
   Please review: $(src-dir)/SPL-README for Licencing info. */

extern int _U_Qfcmp (long double a, long double b, int);

int _U_Qfeq (long double, long double);
int _U_Qfne (long double, long double);
int _U_Qfgt (long double, long double);
int _U_Qfge (long double, long double);
int _U_Qflt (long double, long double);
int _U_Qfle (long double, long double);
int _U_Qfcomp (long double, long double);

int
_U_Qfeq (long double a, long double b)
{
  return (_U_Qfcmp (a, b, 4) != 0);
}

int
_U_Qfne (long double a, long double b)
{
  return (_U_Qfcmp (a, b, 4) == 0);
}
	
int
_U_Qfgt (long double a, long double b)
{
  return (_U_Qfcmp (a, b, 17) != 0);
}

int
_U_Qfge (long double a, long double b)
{
  return (_U_Qfcmp (a, b, 21) != 0);
}

int
_U_Qflt (long double a, long double b)
{
  return (_U_Qfcmp (a, b, 9) != 0);
}

int
_U_Qfle (long double a, long double b)
{
  return (_U_Qfcmp (a, b, 13) != 0);
}

int
_U_Qfcomp (long double a, long double b)
{
  if (_U_Qfcmp (a, b, 4) == 0)
    return 0;

  return (_U_Qfcmp (a, b, 22) != 0 ? 1 : -1);
}
