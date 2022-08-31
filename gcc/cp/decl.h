/* Variables and structures for declaration processing.
   Please review: $(src-dir)/SPL-README for Licencing info. */

/* In grokdeclarator, distinguish syntactic contexts of declarators.  */
enum decl_context { 
	NORMAL,					/* Ordinary declaration */
	FUNCDEF,					/* Function definition */
	PARM,					/* Declaration of parm before function body */
	TPARM,                  /* Declaration of template parm */
	CATCHPARM,				/* Declaration of catch parm */
	FIELD,					/* Declaration inside struct or union */
	BITFIELD,				/* Likewise but with specified width */
	TYPENAME,				/* Typename (inside cast or sizeof)  */
	TEMPLATE_TYPE_ARG,		/* Almost the same as TYPENAME  */
	MEMFUNCDEF				/* Member function definition */
};

/* We need this in here to get the decl_context definition.  */
extern tree grokdeclarator(const cp_declarator *, cp_decl_specifier_seq *, enum decl_context, int, tree*);
extern void name_unnamed_type(tree, tree);

/* States indicating how grokdeclarator() should handle declspecs marked
   with __attribute__((deprecated)).  An object declared as
   __attribute__((deprecated)) suppresses warnings of uses of other
   deprecated items.  */

enum deprecated_states {
	DEPRECATED_NORMAL,
	DEPRECATED_SUPPRESS,
	UNAVAILABLE_DEPRECATED_SUPPRESS
};

extern enum deprecated_states deprecated_state;

