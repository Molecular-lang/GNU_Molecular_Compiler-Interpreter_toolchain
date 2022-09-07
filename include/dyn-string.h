/* An abstract string datatype.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef DYN_STRING_H
#define DYN_STRING_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct dyn_string
{
  int allocated;	/* The amount of space allocated for the string.  */
  int length;		/* The actual length of the string.  */
  char *s;		/* The string itself, NUL-terminated.  */
}* dyn_string_t;

/* The length STR, in bytes, not including the terminating NUL.  */
#define dyn_string_length(STR)                                          \
  ((STR)->length)

/* The NTBS in which the contents of STR are stored.  */
#define dyn_string_buf(STR)                                             \
  ((STR)->s)

/* Compare DS1 to DS2 with strcmp.  */
#define dyn_string_compare(DS1, DS2)                                    \
  (strcmp ((DS1)->s, (DS2)->s))


extern int dyn_string_init (struct dyn_string *, int);
extern dyn_string_t dyn_string_new (int);
extern void dyn_string_delete (dyn_string_t);
extern char *dyn_string_release (dyn_string_t);
extern dyn_string_t dyn_string_resize (dyn_string_t, int);
extern void dyn_string_clear (dyn_string_t);
extern int dyn_string_copy (dyn_string_t, dyn_string_t);
extern int dyn_string_copy_cstr (dyn_string_t, const char *);
extern int dyn_string_prepend (dyn_string_t, dyn_string_t);
extern int dyn_string_prepend_cstr (dyn_string_t, const char *);
extern int dyn_string_insert (dyn_string_t, int, dyn_string_t);
extern int dyn_string_insert_cstr (dyn_string_t, int, const char *);
extern int dyn_string_insert_char (dyn_string_t, int, int);
extern int dyn_string_append (dyn_string_t, dyn_string_t);
extern int dyn_string_append_cstr (dyn_string_t, const char *);
extern int dyn_string_append_char (dyn_string_t, int);
extern int dyn_string_substring (dyn_string_t,  dyn_string_t, int, int);
extern int dyn_string_eq (dyn_string_t, dyn_string_t);

#ifdef __cplusplus
}
#endif

#endif /* !defined (DYN_STRING_H) */
