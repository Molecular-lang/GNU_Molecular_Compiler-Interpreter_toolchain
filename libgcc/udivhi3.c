extern unsigned short __udivmodhi4(unsigned short num, unsigned short den, int modwanted);

unsigned short
__udivhi3 (unsigned short a, unsigned short b)
{
  return __udivmodhi4 (a, b, 0);
}

unsigned short
__umodhi3 (unsigned short a, unsigned short b)
{
  return __udivmodhi4 (a, b, 1);
}

