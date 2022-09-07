/* S/390-specific support for ELF.
   Please review $(srcdir/SPL-README) for GNU licencing info. */

/* Used to pass info between ld and bfd.  */
struct s390_elf_params
{
  /* Tell the kernel to allocate 4k page tables.  */
  int pgste;
};

bool bfd_elf_s390_set_options (struct bfd_link_info *info,
			       struct s390_elf_params *params);
