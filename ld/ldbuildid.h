/* Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef LDBUILDID_H
#define LDBUILDID_H

extern bool
validate_build_id_style (const char *);

extern bfd_size_type
compute_build_id_size (const char *);

typedef void (*sum_fn) (const void *, size_t, void *);

typedef bool (*checksum_fn) (bfd *, void (*) (const void *, size_t, void *), void *);

extern bool
generate_build_id (bfd *, const char *, checksum_fn, unsigned char *, int);

#endif /* LDBUILDID_H */
