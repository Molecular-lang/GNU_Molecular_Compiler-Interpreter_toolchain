/* Macros to support INSN_ADDRESSES
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_INSN_ADDR_H
#define GCC_INSN_ADDR_H

extern vec<int> insn_addresses_;
extern int insn_current_address;

#define INSN_ADDRESSES(id) (insn_addresses_[id])
#define INSN_ADDRESSES_ALLOC(size)			\
  do							\
    {							\
      insn_addresses_.create (size);			\
      insn_addresses_.safe_grow_cleared (size, true);	\
      memset (insn_addresses_.address (),		\
	      0, sizeof (int) * size);			\
    }							\
  while (0)
#define INSN_ADDRESSES_FREE() (insn_addresses_.release ())
#define INSN_ADDRESSES_SET_P() (insn_addresses_.exists ())
#define INSN_ADDRESSES_SIZE() (insn_addresses_.length ())

static inline void
insn_addresses_new (rtx_insn *insn, int insn_addr)
{
  unsigned insn_uid = INSN_UID ((insn));

  if (INSN_ADDRESSES_SET_P ())
    {
      size_t size = INSN_ADDRESSES_SIZE ();
      if (size <= insn_uid)
	{
	  int *p;
	  insn_addresses_.safe_grow (insn_uid + 1, true);
	  p = insn_addresses_.address ();
	  memset (&p[size],
		  0, sizeof (int) * (insn_uid + 1 - size));
	}
      INSN_ADDRESSES (insn_uid) = insn_addr;
    }
}

#define INSN_ADDRESSES_NEW(insn, addr)		\
  (insn_addresses_new (insn, addr))

#endif /* ! GCC_INSN_ADDR_H */
