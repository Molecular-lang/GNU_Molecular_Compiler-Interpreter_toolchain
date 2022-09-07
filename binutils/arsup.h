/* arsup.h - archive support header file
   Please review: $(src-dir)/SPL-README for Licencing info. */

struct list {
	char *name;
	struct list *next;
};

void maybequit (void);

void prompt (void);

void ar_clear (void);

void ar_replace (struct list *);

void ar_delete (struct list *);

void ar_save (void);

void ar_list (void);

void ar_open (char *, int);

void ar_directory (char *, struct list *, char *);

void ar_addmod (struct list *);

void ar_addlib (char *, struct list *);

void ar_end (void);

void ar_extract (struct list *);

bfd *open_inarch (const char *archive_filename, const char *);

extern int yylex (void);

int yyparse (void);

/* Functions from ar.c */

void extract_file (bfd * abfd);

extern int interactive;
