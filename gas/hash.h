/* hash.h -- header file for gas hash table routines
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef HASH_H
#define HASH_H

/* Insert ELEMENT into HTAB.  If REPLACE is non-zero existing elements
   are overwritten.  If ELEMENT already exists, a pointer to the slot
   is returned.  Otherwise NULL is returned.  */

extern void **htab_insert (htab_t, void * /* element */, int /* replace */);

/* Print statistics about a hash table.  */

extern void htab_print_statistics (FILE *f, const char *name, htab_t table);

/* String hash table functions.  */

struct string_tuple
{
  const char *key;
  const void *value;
};

typedef struct string_tuple string_tuple_t;

/* Hash function for a string_tuple.  */

static hashval_t
hash_string_tuple (const void *e)
{
  string_tuple_t *tuple = (string_tuple_t *) e;
  return htab_hash_string (tuple->key);
}

/* Equality function for a string_tuple.  */

static int
eq_string_tuple (const void *a, const void *b)
{
  const string_tuple_t *ea = (const string_tuple_t *) a;
  const string_tuple_t *eb = (const string_tuple_t *) b;

  return strcmp (ea->key, eb->key) == 0;
}

static inline string_tuple_t *
string_tuple_alloc (const char *key, const void *value)
{
  string_tuple_t *tuple = XNEW (string_tuple_t);
  tuple->key = key;
  tuple->value = value;
  return tuple;
}

static inline void *
str_hash_find (htab_t table, const char *key)
{
  string_tuple_t needle = { key, NULL };
  string_tuple_t *tuple = htab_find (table, &needle);
  return tuple != NULL ? (void *) tuple->value : NULL;
}

static inline void *
str_hash_find_n (htab_t table, const char *key, size_t n)
{
  char *tmp = XNEWVEC (char, n + 1);
  memcpy (tmp, key, n);
  tmp[n] = '\0';
  string_tuple_t needle = { tmp, NULL };
  string_tuple_t *tuple = htab_find (table, &needle);
  free (tmp);
  return tuple != NULL ? (void *) tuple->value : NULL;
}

static inline void
str_hash_delete (htab_t table, const char *key)
{
  string_tuple_t needle = { key, NULL };
  htab_remove_elt (table, &needle);
}

static inline void **
str_hash_insert (htab_t table, const char *key, const void *value, int replace)
{
  string_tuple_t *elt = string_tuple_alloc (key, value);
  void **slot = htab_insert (table, elt, replace);
  if (slot && !replace)
    free (elt);
  return slot;
}

static inline htab_t
str_htab_create (void)
{
  return htab_create_alloc (16, hash_string_tuple, eq_string_tuple,
			    NULL, xcalloc, free);
}

#endif /* HASH_H */
