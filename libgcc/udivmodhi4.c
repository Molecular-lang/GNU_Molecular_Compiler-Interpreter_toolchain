unsigned short
__udivmodhi4(unsigned short num, unsigned short den, int modwanted)
{
  unsigned short bit = 1;
  unsigned short res = 0;

  while (den < num && bit && !(den & (1U<<15)))
    {
      den <<=1;
      bit <<=1;
    }
  while (bit)
    {
      if (num >= den)
	{
	  num -= den;
	  res |= bit;
	}
      bit >>=1;
      den >>=1;
    }
  if (modwanted) return num;
  return res;
}
