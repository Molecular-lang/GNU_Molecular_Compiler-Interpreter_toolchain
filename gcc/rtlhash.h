/* Register Transfer Language (RTL) hash functions.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef RTL_HASH_H
#define RTL_HASH_H 1


namespace inchash {

extern void add_rtx (const_rtx, hash &);

}

#endif
