/* Operation with 128 bit bitmask.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_WIDE_INT_BITMASK_H
#define GCC_WIDE_INT_BITMASK_H

class wide_int_bitmask
{
public:
  constexpr wide_int_bitmask ();
  constexpr wide_int_bitmask (uint64_t l);
  constexpr wide_int_bitmask (uint64_t l, uint64_t h);
  inline wide_int_bitmask &operator &= (wide_int_bitmask);
  inline wide_int_bitmask &operator |= (wide_int_bitmask);
  constexpr wide_int_bitmask operator ~ () const;
  constexpr wide_int_bitmask operator & (wide_int_bitmask) const;
  constexpr wide_int_bitmask operator | (wide_int_bitmask) const;
  inline wide_int_bitmask operator >> (int);
  inline wide_int_bitmask operator << (int);
  inline bool operator == (wide_int_bitmask) const;
  inline bool operator != (wide_int_bitmask) const;
  uint64_t low, high;
};

constexpr
wide_int_bitmask::wide_int_bitmask ()
: low (0), high (0)
{
}

constexpr
wide_int_bitmask::wide_int_bitmask (uint64_t l)
: low (l), high (0)
{
}

constexpr
wide_int_bitmask::wide_int_bitmask (uint64_t l, uint64_t h)
: low (l), high (h)
{
}

inline wide_int_bitmask &
wide_int_bitmask::operator &= (wide_int_bitmask b)
{
  low &= b.low;
  high &= b.high;
  return *this;
}

inline wide_int_bitmask &
wide_int_bitmask::operator |= (wide_int_bitmask b)
{
  low |= b.low;
  high |= b.high;
  return *this;
}

constexpr wide_int_bitmask
wide_int_bitmask::operator ~ () const
{
  return wide_int_bitmask (~low, ~high);
}

constexpr wide_int_bitmask
wide_int_bitmask::operator | (wide_int_bitmask b) const
{
  return wide_int_bitmask (low | b.low, high | b.high);
}

constexpr wide_int_bitmask
wide_int_bitmask::operator & (wide_int_bitmask b) const
{
  return wide_int_bitmask (low & b.low, high & b.high);
}

inline wide_int_bitmask
wide_int_bitmask::operator << (int amount)
{
  wide_int_bitmask ret;
  if (amount >= 64)
    {
      ret.low = 0;
      ret.high = low << (amount - 64);
    }
  else if (amount == 0)
    ret = *this;
  else
    {
      ret.low = low << amount;
      ret.high = (low >> (64 - amount)) | (high << amount);
    }
  return ret;
}

inline wide_int_bitmask
wide_int_bitmask::operator >> (int amount)
{
  wide_int_bitmask ret;
  if (amount >= 64)
    {
      ret.low = high >> (amount - 64);
      ret.high = 0;
    }
  else if (amount == 0)
    ret = *this;
  else
    {
      ret.low = (high << (64 - amount)) | (low >> amount);
      ret.high = high >> amount;
    }
  return ret;
}

inline bool
wide_int_bitmask::operator == (wide_int_bitmask b) const
{
  return low == b.low && high == b.high;
}

inline bool
wide_int_bitmask::operator != (wide_int_bitmask b) const
{
  return low != b.low || high != b.high;
}

#endif /* ! GCC_WIDE_INT_BITMASK_H */
