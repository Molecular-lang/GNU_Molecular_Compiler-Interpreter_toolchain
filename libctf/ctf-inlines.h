/* Inline functions. */

#ifndef	_CTF_INLINES_H
#define	_CTF_INLINES_H

#ifdef	__cplusplus
extern "C"
{
#endif

#include "config.h"

#ifndef _libctf_malloc_
#error "ctf-inlines.h" should not be included directly: include "ctf-impl.h".
#endif

static inline ssize_t
ctf_get_ctt_size (const ctf_dict_t *fp,
		  const ctf_type_t *tp,
		  ssize_t *sizep,
		  ssize_t *incrementp)
{
  return (fp->ctf_dictops->ctfo_get_ctt_size (fp, tp, sizep, incrementp));
}

static inline int
ctf_forwardable_kind (int kind)
{
  return (kind == CTF_K_STRUCT || kind == CTF_K_UNION || kind == CTF_K_ENUM);
}

static inline int
ctf_dynhash_cnext_sorted (ctf_dynhash_t *h, ctf_next_t **i, const void **key,
			  const void **value, ctf_hash_sort_f sort_fun,
			  void *sort_arg)
{
  return ctf_dynhash_next_sorted (h, i, (void **) key, (void **) value,
				  sort_fun, sort_arg);
}

static inline int
ctf_dynhash_cnext (ctf_dynhash_t *h, ctf_next_t **it,
		  const void **key, const void **value)
{
  return ctf_dynhash_next (h, it, (void **) key, (void **) value);
}

static inline int
ctf_dynhash_cinsert (ctf_dynhash_t *h, const void *k, const void *v)
{
  return ctf_dynhash_insert (h, (void *) k, (void *) v);
}

static inline int
ctf_dynset_cnext (ctf_dynset_t *h, ctf_next_t **it, const void **key)
{
  return ctf_dynset_next (h, it, (void **) key);
}

static inline int
ctf_dynset_cinsert (ctf_dynset_t *h, const void *k)
{
  return ctf_dynset_insert (h, (void *) k);
}

static inline int
ctf_assert_internal (ctf_dict_t *fp, const char *file, size_t line,
		     const char *exprstr, int expr)
{
  if (_libctf_unlikely_ (!expr))
    ctf_assert_fail_internal (fp, file, line, exprstr);

  return expr;
}

#ifdef	__cplusplus
}
#endif

#endif /* _CTF_INLINES_H */
