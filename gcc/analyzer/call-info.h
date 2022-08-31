/* Subclasses of custom_edge_info for describing outcomes of function calls.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef GCC_ANALYZER_CALL_INFO_H
#define GCC_ANALYZER_CALL_INFO_H

namespace ana {

/* Subclass of custom_edge_info for an outcome of a call.
   This is still abstract; the update_model and get_desc vfuncs must be
   implemented.  */

class call_info : public custom_edge_info
{
public:
  void print (pretty_printer *pp) const final override;
  void add_events_to_path (checker_path *emission_path,
			   const exploded_edge &eedge) const final override;

  const gcall *get_call_stmt () const { return m_call_stmt; }
  tree get_fndecl () const { return m_fndecl; }

  virtual label_text get_desc (bool can_colorize) const = 0;

  call_details get_call_details (region_model *model,
				 region_model_context *ctxt) const;

protected:
  call_info (const call_details &cd);

private:
  const gcall *m_call_stmt;
  tree m_fndecl;
};

/* Subclass of call_info for a "success" outcome of a call,
   adding a "when `FNDECL' succeeds" message.
   This is still abstract: the custom_edge_info::update_model vfunc
   must be implemented.  */

class success_call_info : public call_info
{
public:
  label_text get_desc (bool can_colorize) const final override;

protected:
  success_call_info (const call_details &cd) : call_info (cd) {}
};

/* Subclass of call_info for a "failure" outcome of a call,
   adding a "when `FNDECL' fails" message.
   This is still abstract: the custom_edge_info::update_model vfunc
   must be implemented.  */

class failed_call_info : public call_info
{
public:
  label_text get_desc (bool can_colorize) const final override;

protected:
  failed_call_info (const call_details &cd) : call_info (cd) {}
};

} // namespace ana

#endif /* GCC_ANALYZER_CALL_INFO_H */
