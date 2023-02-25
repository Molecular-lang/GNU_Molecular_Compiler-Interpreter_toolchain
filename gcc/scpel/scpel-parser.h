/* Declarations for the parser for Scpel */
#ifndef GCC_C_PARSER_H
#define GCC_C_PARSER_H

/* The Scpel lexer intermediates between the lexer in cpplib and scpel-lex.cc
   and the Scpel parser.  Unlike the C++ lexer, the parser structure
   stores the lexer information instead of using a separate structure.
   Identifiers are separated into ordinary identifiers, type names,
   keywords and some other Objective-C types of identifiers, and some
   look-ahead is maintained.

   ??? It might be a good idea to lex the whole file up front (as for
   C++).  It would then be possible to share more of the Scpel and C++
   lexer code, if desired.  */

/* More information about the type of a CPP_NAME token. */
enum scpel_id_kind {
	/* An ordinary identifier. */
	C_ID_ID,
	/* An identifier declared as a typedef name. */
	C_ID_TYPENAME,
	/* An identifier declared as an Objective-C class name. */
	C_ID_CLASSNAME,
	/* An address space identifier. */
	C_ID_ADDRSPACE,
	/* Not an identifier. */
	C_ID_NONE
};

/* A single Scpel token after string literal concatenation and conversion
   of preprocessing tokens to tokens. */
struct GTY (()) scpel_token {
	/* The kind of token. */
	ENUM_BITFIELD (cpp_ttype) type : 8;
	/* If this token is a CPP_NAME, this value indicates whether also
	   declared as some kind of type. Otherwise, it is C_ID_NONE. */
	ENUM_BITFIELD (scpel_id_kind) id_kind : 8;
	/* If this token is a keyword, this value indicates which keyword.
	   Otherwise, this value is RID_MAX. */
	ENUM_BITFIELD (rid) keyword : 8;
	/* If this token is a CPP_PRAGMA, this indicates the pragma that
	   was seen.  Otherwise it is PRAGMA_NONE. */
	ENUM_BITFIELD (pragma_kind) pragma_kind : 8;
	/* The location at which this token was found. */
	location_t location;
	/* The value associated with this token, if any. */
	tree value;
	/* Token flags. */
	unsigned char flags;

	source_range get_range () const {
		return get_range_from_loc (line_table, location);
	}

	location_t get_finish () const {
		return get_range ().m_finish;
	}
};

/* The parser.  */
struct scpel_parser;

/* Possibly kinds of declarator to parse.  */
enum scpel_dtr_syn {
  /* A normal declarator with an identifier.  */
  C_DTR_NORMAL,
  /* An abstract declarator (maybe empty).  */
  C_DTR_ABSTRACT,
  /* A parameter declarator: may be either, but after a type name does
     not redeclare a typedef name as an identifier if it can
     alternatively be interpreted as a typedef name; see DR#009,
     applied in C90 TC1, omitted from C99 and reapplied in C99 TC2
     following DR#249.  For example, given a typedef T, "int T" and
     "int *T" are valid parameter declarations redeclaring T, while
     "int (T)" and "int * (T)" and "int (T[])" and "int (T (int))" are
     abstract declarators rather than involving redundant parentheses;
     the same applies with attributes inside the parentheses before
     "T".  */
  C_DTR_PARM
};

/* The binary operation precedence levels, where 0 is a dummy lowest level
   used for the bottom of the stack.  */
enum scpel_parser_prec {
  PREC_NONE,
  PREC_LOGOR,
  PREC_LOGAND,
  PREC_BITOR,
  PREC_BITXOR,
  PREC_BITAND,
  PREC_EQ,
  PREC_REL,
  PREC_SHIFT,
  PREC_ADD,
  PREC_MULT,
  NUM_PRECS
};

enum scpel_lookahead_kind {
  /* Always treat unknown identifiers as typenames.  */
  cla_prefer_type,

  /* Could be parsing a nonabstract declarator.  Only treat an identifier
     as a typename if followed by another identifier or a star.  */
  cla_nonabstract_decl,

  /* Never treat identifiers as typenames.  */
  cla_prefer_id
};


extern scpel_token * scpel_parser_peek_token (scpel_parser *parser);
extern scpel_token * scpel_parser_peek_2nd_token (scpel_parser *parser);
extern scpel_token * scpel_parser_peek_nth_token (scpel_parser *parser, unsigned int n);
extern bool scpel_parser_require (scpel_parser *parser, enum cpp_ttype type,
			      const char *msgid,
			      location_t matching_location = UNKNOWN_LOCATION,
			      bool type_is_unique=true);
extern bool scpel_parser_error (scpel_parser *parser, const char *gmsgid);
extern void scpel_parser_consume_token (scpel_parser *parser);
extern void scpel_parser_skip_until_found (scpel_parser *parser, enum cpp_ttype type,
				       const char *msgid,
				       location_t = UNKNOWN_LOCATION);
extern bool scpel_parser_next_token_starts_declspecs (scpel_parser *parser);
bool scpel_parser_next_tokens_start_declaration (scpel_parser *parser);
bool scpel_token_starts_typename (scpel_token *token);

/* Abstraction to avoid defining scpel_parser here which messes up gengtype
   output wrt ObjC due to vec<scpel_token> routines being put in gtype-c.h
   but not gtype-objc.h.  */
extern scpel_token * scpel_parser_tokens_buf (scpel_parser *parser, unsigned n);
extern bool scpel_parser_error (scpel_parser *parser);
extern void scpel_parser_set_error (scpel_parser *parser, bool);

/* A bit of a hack to have this here.  It would be better in a c-decl.h.  */
extern bool old_style_parameter_scope (void);

/* Return true if the next token from PARSER has the indicated
   TYPE.  */

inline bool
scpel_parser_next_token_is (scpel_parser *parser, enum cpp_ttype type)
{
  return scpel_parser_peek_token (parser)->type == type;
}

/* Return true if the next token from PARSER does not have the
   indicated TYPE.  */

inline bool
scpel_parser_next_token_is_not (scpel_parser *parser, enum cpp_ttype type)
{
  return !scpel_parser_next_token_is (parser, type);
}

/* Return true if the next token from PARSER is the indicated
   KEYWORD.  */

inline bool
scpel_parser_next_token_is_keyword (scpel_parser *parser, enum rid keyword)
{
  return scpel_parser_peek_token (parser)->keyword == keyword;
}

struct scpel_expr scpel_parser_string_literal (scpel_parser *, bool, bool);
extern struct scpel_declarator *
scpel_parser_declarator (scpel_parser *parser, bool type_seen_p, scpel_dtr_syn kind,
		     bool *seen_id);
extern void scpel_parser_declspecs (scpel_parser *, struct scpel_declspecs *, bool, bool,
				bool, bool, bool, bool, bool,
				enum scpel_lookahead_kind);
extern struct scpel_type_name *scpel_parser_type_name (scpel_parser *, bool = false);

#endif
