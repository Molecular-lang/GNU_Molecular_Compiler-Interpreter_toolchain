/* SHA-1 thunks.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef _CTF_SHA1_H
#define _CTF_SHA1_H

#include "config.h"
#include "sha1.h"

#define CTF_SHA1_SIZE 41

typedef struct sha1_ctx ctf_sha1_t;

static inline void
ctf_sha1_init (ctf_sha1_t *sha1)
{
  sha1_init_ctx (sha1);
}

static inline void
ctf_sha1_add (ctf_sha1_t *sha1, const void *buf, size_t len)
{
  sha1_process_bytes (buf, len, sha1);
}
#endif
