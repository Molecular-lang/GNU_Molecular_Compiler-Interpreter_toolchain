/* Communication between the Local Register Allocator (LRA) and
   the rest of the compiler.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_LRA_H
#define GCC_LRA_H

extern bool lra_simple_p;

/* Return the allocno reg class of REGNO.  If it is a reload pseudo,
   the pseudo should finally get hard register of the allocno
   class.  */
static inline enum reg_class
lra_get_allocno_class (int regno)
{
  resize_reg_info ();
  return reg_allocno_class (regno);
}

extern rtx lra_eliminate_regs (rtx, machine_mode, rtx);
extern void lra (FILE *);
extern void lra_init_once (void);
extern void lra_finish_once (void);

#endif /* GCC_LRA_H */
