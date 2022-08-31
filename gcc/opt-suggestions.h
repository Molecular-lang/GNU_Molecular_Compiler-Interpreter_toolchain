/* Provide suggestions to handle misspelled options, and implement the
   --complete option for auto-completing options from a prefix.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_OPT_PROPOSER_H
#define GCC_OPT_PROPOSER_H

/* Option proposer is class used by driver in order to provide hints
   for wrong options provided.  And it's used by --complete option that's
   intended to be invoked by BASH in order to provide better option
   completion support.  */

class option_proposer
{
public:
  /* Default constructor.  */
  option_proposer (): m_option_suggestions (NULL)
  {}

  /* Default destructor.  */
  ~option_proposer ();

  /* Helper function for driver::handle_unrecognized_options.

     Given an unrecognized option BAD_OPT (without the leading dash),
     locate the closest reasonable matching option (again, without the
     leading dash), or NULL.

     The returned string is owned by the option_proposer instance.  */
  const char *suggest_option (const char *bad_opt);

  /* Print on stdout a list of valid options that begin with OPTION_PREFIX,
     one per line, suitable for use by Bash completion.

     Implementation of the "-completion=" option.  */
  void suggest_completion (const char *option_prefix);

  /* Populate RESULTS with valid completions of options that begin
     with OPTION_PREFIX.  */
  void get_completions (const char *option_prefix, auto_string_vec &results);

private:
  /* Helper function for option_proposer::suggest_option.  Populate
     m_option_suggestions with candidate strings for misspelled options.
     The strings will be freed by the option_proposer's dtor.
     PREFIX is used for bash completion suggestions, otherwise
     it's set to NULL.  */
  void build_option_suggestions (const char *prefix);

private:
  /* Cache with all suggestions.  */
  auto_string_vec *m_option_suggestions;
};

#endif  /* GCC_OPT_PROPOSER_H */
