/* sb.h - header file for string buffer manipulation routines
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef SB_H

#define SB_H

/* String blocks

   I had a couple of choices when deciding upon this data structure.
   gas uses null terminated strings for all its internal work.  This
   often means that parts of the program that want to examine
   substrings have to manipulate the data in the string to do the
   right thing (a common operation is to single out a bit of text by
   saving away the character after it, nulling it out, operating on
   the substring and then replacing the character which was under the
   null).  This is a pain and I remember a load of problems that I had with
   code in gas which almost got this right.  Also, it's harder to grow and
   allocate null terminated strings efficiently.

   Obstacks provide all the functionality needed, but are too
   complicated, hence the sb.

   An sb is allocated by the caller.  */

typedef struct sb
{
  char *ptr;			/* Points to the current block.  */
  size_t len;			/* How much is used.  */
  size_t max;			/* The maximum length.  */
}
sb;

extern void sb_new (sb *);
extern void sb_build (sb *, size_t);
extern void sb_kill (sb *);
extern void sb_add_sb (sb *, sb *);
extern void sb_scrub_and_add_sb (sb *, sb *);
extern void sb_reset (sb *);
extern void sb_add_char (sb *, size_t);
extern void sb_add_string (sb *, const char *);
extern void sb_add_buffer (sb *, const char *, size_t);
extern char *sb_terminate (sb *);
extern size_t sb_skip_white (size_t, sb *);
extern size_t sb_skip_comma (size_t, sb *);

/* Actually in input-scrub.c.  */
extern void input_scrub_include_sb (sb *, char *, int);

#endif /* SB_H */
