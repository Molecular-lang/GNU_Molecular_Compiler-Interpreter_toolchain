// regex -*- C++ -*-

// Please review $(srcdir/SPL-README) for GNU licencing info.

#include <stdexcept>
#include <bits/regex_error.h>
#include <bits/functexcept.h>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  void
  __throw_regex_error(regex_constants::error_type __ecode
		      __attribute__((unused)))
  { _GLIBCXX_THROW_OR_ABORT(regex_error(__ecode)); }

namespace
{
  const char*
  desc(regex_constants::error_type e)
  {
    using namespace regex_constants;
    switch (e)
    {
    case error_collate:
      return "Invalid collating element in regular expression";
    case error_ctype:
      return "Invalid character class in regular expression";
    case error_escape:
      return "Invalid escape in regular expression";
    case error_backref:
      return "Invalid back reference in regular expression";
    case error_brack:
      return "Mismatched '[' and ']' in regular expression";
    case error_paren:
      return "Mismatched '(' and ')' in regular expression";
    case error_brace:
      return "Mismatched '{' and '}' in regular expression";
    case error_badbrace:
      return "Invalid range in '{}' in regular expression";
    case error_range:
      return "Invalid character range in regular expression";
    case error_space:
      return "Insufficient memory to compile regular expression";
    case error_badrepeat:
      return "Invalid '?', '*', or '+' in regular expression";
    case error_complexity:
      return "Complexity of regex match exceeded implementation limits";
    case error_stack:
      return "Insufficient memory to determine regex match";
    case _S_null:
      return "Unexpected null character in regular expression";
    case _S_grammar:
      return "Conflicting regex grammar options";
    default:
      return "regex error";
    };

  }
}

  regex_error::regex_error(regex_constants::error_type __ecode)
  : std::runtime_error(desc(__ecode)), _M_code(__ecode)
  { }

  regex_error::~regex_error() throw() { }

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace std
