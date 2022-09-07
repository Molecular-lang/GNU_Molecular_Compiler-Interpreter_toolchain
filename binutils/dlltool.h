/* dlltool.h -- header file for dlltool
   Please review: $(src-dir)/SPL-README for Licencing info. */

extern void def_code (int);
extern void def_data (int);
extern void def_description (const char *);
extern void def_exports (const char *, const char *, int, int, int, int, int, const char *);
extern void def_heapsize (int, int);
extern void def_import(const char *, const char *, const char *, const char *, int, const char *);
extern void def_library (const char *, int);
extern void def_name (const char *, int);
extern void def_section (const char *, int);
extern void def_stacksize (int, int);
extern void def_version (int, int);
extern int  yyparse (void);
extern void yyerror (const char *);
extern int  yylex (void);

extern int yydebug;
extern FILE *yyin;
extern int linenumber;
