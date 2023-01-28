/* Definitions for c-indentation.cc.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_C_INDENTATION_H
#define GCC_C_INDENTATION_H

/* Token information used by the -Wmisleading-indentation implementation.  */

struct token_indent_info
{
  location_t location;
  ENUM_BITFIELD (cpp_ttype) type : 8;
  ENUM_BITFIELD (rid) keyword : 8;
};

/* Extract token information from TOKEN, which ought to either be a
   cp_token * or a c_token *.  */

template <typename T>
inline token_indent_info
get_token_indent_info (const T *token)
{
  token_indent_info info;
  info.location = token->location;
  info.type = token->type;
  info.keyword = token->keyword;

  return info;
}

extern void
warn_for_misleading_indentation (const token_indent_info &guard_tinfo,
				 const token_indent_info &body_tinfo,
				 const token_indent_info &next_tinfo);
extern const char *
guard_tinfo_to_string (enum rid keyword);

#endif  /* ! GCC_C_INDENTATION_H  */
