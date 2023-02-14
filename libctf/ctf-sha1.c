/* SHA-1 thunks. */

#include <ctf-impl.h>
#include <ctf-sha1.h>

static const char hex[] = "0123456789abcdef";

char *
ctf_sha1_fini (ctf_sha1_t *sha1, char *buf)
{
  size_t i;

  /* Alignment suitable for a uint32_t. */
  union
  {
    uint32_t align;
    unsigned char digest[((CTF_SHA1_SIZE - 1) / 2) + 1];
  } align;

  sha1_finish_ctx (sha1, align.digest);

  if (!buf)
    return NULL;

  buf[CTF_SHA1_SIZE - 1] = '\0';

  for (i = 0; i < (CTF_SHA1_SIZE - 1) / 2; i++)
    {
      buf[2 * i] = hex[align.digest[i] >> 4];
      buf[2 * i + 1] = hex[align.digest[i] & 0xf];
    }
  return buf;
}
