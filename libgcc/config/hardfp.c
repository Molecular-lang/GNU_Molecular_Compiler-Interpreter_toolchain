/* Dummy floating-point routines for hard-float code.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#define sf float
#define df double

#if defined (OP_add3)
TYPE FUNC (TYPE x, TYPE y) { return x + y; }
#elif defined (OP_sub3)
TYPE FUNC (TYPE x, TYPE y) { return x - y; }
#elif defined (OP_neg2)
TYPE FUNC (TYPE x) { return -x; }
#elif defined (OP_mul3)
TYPE FUNC (TYPE x, TYPE y) { return x * y; }
#elif defined (OP_div3)
TYPE FUNC (TYPE x, TYPE y) { return x / y; }
#elif defined (OP_eq2) || defined (OP_ne2)
int FUNC (TYPE x, TYPE y) { return x == y ? 0 : 1; }
#elif defined (OP_ge2)
int FUNC (TYPE x, TYPE y) { return x >= y ? 0 : -1; }
#elif defined (OP_gt2)
int FUNC (TYPE x, TYPE y) { return x > y ? 1 : 0; }
#elif defined (OP_le2)
int FUNC (TYPE x, TYPE y) { return x <= y ? 0 : 1; }
#elif defined (OP_lt2)
int FUNC (TYPE x, TYPE y) { return x < y ? -1 : 0; }
#elif defined (OP_unord2)
int FUNC (TYPE x, TYPE y) { return __builtin_isunordered (x, y); }
#elif defined (OP_fixsi)
int FUNC (TYPE x) { return (int) x; }
#elif defined (OP_floatsi)
TYPE FUNC (int x) { return (TYPE) x; }
#elif defined (OP_floatunsi)
TYPE FUNC (unsigned int x) { return (TYPE) x; }
#elif defined (OP_extendsf2)
TYPE FUNC (float x) { return (TYPE) x; }
#elif defined (OP_truncdf2)
TYPE FUNC (double x) { return (TYPE) x; }
#else
#error Unknown operation
#endif
