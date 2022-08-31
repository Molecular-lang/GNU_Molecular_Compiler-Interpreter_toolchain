/* tc.h - target cpu dependent

   Please review: $(src-dir)/SPL-README for Licencing info. */

/* In theory (mine, at least!) the machine dependent part of the assembler
   should only have to include one file.  This one.  -- JF */

extern const pseudo_typeS md_pseudo_table[];

const char * md_atof (int, char *, int *);
int    md_parse_option (int, const char *);
void   md_show_usage (FILE *);
void   md_assemble (char *);
void   md_begin (void);
#ifndef md_number_to_chars
void   md_number_to_chars (char *, valueT, int);
#endif
void   md_apply_fix (fixS *, valueT *, segT);

#ifndef WORKING_DOT_WORD
extern int md_short_jump_size;
extern int md_long_jump_size;
#endif

#ifdef TE_PE
/* The name of an external symbol which is
   used to make weak PE symbol names unique.  */
extern const char * an_external_name;
#endif

#ifndef md_create_long_jump
void    md_create_long_jump (char *, addressT, addressT, fragS *, symbolS *);
#endif
#ifndef md_create_short_jump
void    md_create_short_jump (char *, addressT, addressT, fragS *, symbolS *);
#endif
#ifndef md_pcrel_from
long    md_pcrel_from (fixS *);
#endif
#ifndef md_pcrel_from_section
long    md_pcrel_from_section (fixS *, segT);
#endif
#ifndef md_operand
void    md_operand (expressionS *);
#endif
#ifndef md_estimate_size_before_relax
int     md_estimate_size_before_relax (fragS * fragP, segT);
#endif
#ifndef md_section_align
valueT  md_section_align (segT, valueT);
#endif
#ifndef  md_undefined_symbol
symbolS *md_undefined_symbol (char *);
#endif

#ifndef md_convert_frag
void    md_convert_frag (bfd *, segT, fragS *);
#endif
#ifndef RELOC_EXPANSION_POSSIBLE
extern arelent *tc_gen_reloc (asection *, fixS *);
#else
extern arelent **tc_gen_reloc (asection *, fixS *);
#endif

extern const char FLT_CHARS[];
extern const char EXP_CHARS[];
