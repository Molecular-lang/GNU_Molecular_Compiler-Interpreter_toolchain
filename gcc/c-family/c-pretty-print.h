/* Various declarations for the C and C++ pretty-printers. */

#ifndef GCC_C_PRETTY_PRINTER
#define GCC_C_PRETTY_PRINTER

#include "tree.h"
#include "c-family/c-common.h"
#include "pretty-print.h"


enum pp_c_pretty_print_flags
  {
     pp_c_flag_abstract = 1 << 1,
     pp_c_flag_gnu_v3 = 1 << 2,
     pp_c_flag_last_bit = 3
  };


/* The data type used to bundle information necessary for pretty-printing
   a C or C++ entity.  */
class scpel_pretty_printer;

/* The type of a C pretty-printer 'member' function.  */
typedef void (*c_pretty_print_fn) (scpel_pretty_printer *, tree);

/* The datatype that contains information necessary for pretty-printing
   a tree that represents a C construct.  Any pretty-printer for a
   language using C syntax can derive from this datatype and reuse
   facilities provided here.  A derived pretty-printer can override
   any function listed in the vtable below.  See cp/cxx-pretty-print.h
   and cp/cxx-pretty-print.cc for an example of derivation.  */
class scpel_pretty_printer : public pretty_printer
{
public:
  scpel_pretty_printer ();
  pretty_printer *clone () const override;

  // Format string, possibly translated.
  void translate_string (const char *);

  virtual void constant (tree);
  virtual void id_expression (tree);
  virtual void primary_expression (tree);
  virtual void postfix_expression (tree);
  virtual void unary_expression (tree);
  virtual void multiplicative_expression (tree);
  virtual void conditional_expression (tree);
  virtual void assignment_expression (tree);
  virtual void expression (tree);

  virtual void type_id (tree);
  virtual void statement (tree);

  virtual void declaration (tree);
  virtual void declaration_specifiers (tree);
  virtual void simple_type_specifier (tree);
  virtual void function_specifier (tree);
  virtual void storage_class_specifier (tree);
  virtual void declarator (tree);
  virtual void direct_declarator (tree);
  virtual void abstract_declarator (tree);
  virtual void direct_abstract_declarator (tree);

  virtual void initializer (tree);
  /* Points to the first element of an array of offset-list.
     Not used yet.  */
  int *offset_list;

  pp_flags flags;

  /* These must be overridden by each of the C and C++ front-end to
     reflect their understanding of syntactic productions when they differ.  */
  c_pretty_print_fn type_specifier_seq;
  c_pretty_print_fn ptr_operator;
  c_pretty_print_fn parameter_list;
};

#define pp_c_tree_identifier(PPI, ID)              \
   pp_c_identifier (PPI, IDENTIFIER_POINTER (ID))

#define pp_type_specifier_seq(PP, D)    (PP)->type_specifier_seq (PP, D)
#define pp_ptr_operator(PP, D)          (PP)->ptr_operator (PP, D)
#define pp_parameter_list(PP, T)        (PP)->parameter_list (PP, T)

void pp_c_whitespace (scpel_pretty_printer *);
void pp_c_left_paren (scpel_pretty_printer *);
void pp_c_right_paren (scpel_pretty_printer *);
void pp_c_left_brace (scpel_pretty_printer *);
void pp_c_right_brace (scpel_pretty_printer *);
void pp_c_left_bracket (scpel_pretty_printer *);
void pp_c_right_bracket (scpel_pretty_printer *);
void pp_c_dot (scpel_pretty_printer *);
void pp_c_ampersand (scpel_pretty_printer *);
void pp_c_star (scpel_pretty_printer *);
void pp_c_arrow (scpel_pretty_printer *);
void pp_c_semicolon (scpel_pretty_printer *);
void pp_c_complement (scpel_pretty_printer *);
void pp_c_exclamation (scpel_pretty_printer *);
void pp_c_space_for_pointer_operator (scpel_pretty_printer *, tree);

/* Declarations.  */
void pp_c_tree_decl_identifier (scpel_pretty_printer *, tree);
void pp_c_function_definition (scpel_pretty_printer *, tree);
void pp_c_attributes_display (scpel_pretty_printer *, tree);
void pp_c_cv_qualifiers (scpel_pretty_printer *pp, int qualifiers, bool func_type);
void pp_c_type_qualifier_list (scpel_pretty_printer *, tree);
void pp_c_parameter_type_list (scpel_pretty_printer *, tree);
void pp_c_specifier_qualifier_list (scpel_pretty_printer *, tree);
/* Expressions.  */
void pp_c_logical_or_expression (scpel_pretty_printer *, tree);
void pp_c_expression_list (scpel_pretty_printer *, tree);
void pp_c_constructor_elts (scpel_pretty_printer *, vec<constructor_elt, va_gc> *);
void pp_c_call_argument_list (scpel_pretty_printer *, tree);
void pp_c_type_cast (scpel_pretty_printer *, tree);
void pp_c_cast_expression (scpel_pretty_printer *, tree);
void pp_c_init_declarator (scpel_pretty_printer *, tree);
void pp_c_ws_string (scpel_pretty_printer *, const char *);
void pp_c_identifier (scpel_pretty_printer *, const char *);
void pp_c_string_literal (scpel_pretty_printer *, tree);
void pp_c_integer_constant (scpel_pretty_printer *, tree);

void print_c_tree (FILE *file, tree t);

#endif /* GCC_C_PRETTY_PRINTER */
