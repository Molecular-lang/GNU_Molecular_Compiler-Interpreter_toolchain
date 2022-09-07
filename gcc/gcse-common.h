/* Structures and prototypes common across the normal GCSE
   implementation and the post-reload implementation.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_GCSE_COMMON_H
#define GCC_GCSE_COMMON_H

typedef vec<rtx_insn *> vec_rtx_heap;
struct modify_pair
{
  rtx dest;                     /* A MEM.  */
  rtx dest_addr;                /* The canonical address of `dest'.  */
};

typedef vec<modify_pair> vec_modify_pair_heap;

struct gcse_note_stores_info
{
  rtx_insn *insn;
  vec<modify_pair> *canon_mem_list;
};

extern void compute_transp (const_rtx, int, sbitmap *, bitmap, bitmap, vec<modify_pair> *);
extern void record_last_mem_set_info_common (rtx_insn *,
					     vec<rtx_insn *> *,
					     vec<modify_pair> *,
					     bitmap, bitmap);


#endif
