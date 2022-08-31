/* LTO symbol table merging.
   Please review: $(src-dir)/SPL-README for Licencing info. */

extern void lto_symtab_merge_decls (void);
extern void lto_symtab_merge_symbols (void);
extern tree lto_symtab_prevailing_decl (tree decl);
extern tree lto_symtab_prevailing_virtual_decl (tree decl);

/* Mark DECL to be previailed by PREVAILING.
   Use DECL_LANG_FLAG_0 and DECL_CHAIN as special markers; those do not
   disturb debug_tree and diagnostics.
   We are safe to modify them as we wish, because the declarations disappear
   from the IL after the merging.  */

inline void
lto_symtab_prevail_decl (tree prevailing, tree decl)
{
  gcc_checking_assert (! DECL_LANG_FLAG_0 (decl));
  gcc_assert (TREE_PUBLIC (decl) || DECL_EXTERNAL (decl));
  DECL_CHAIN (decl) = prevailing;
  DECL_LANG_FLAG_0 (decl) = 1;
}

/* Given the decl DECL, return the prevailing decl with the same name. */

inline tree
lto_symtab_prevailing_decl (tree decl)
{
  if (DECL_LANG_FLAG_0 (decl))
    return DECL_CHAIN (decl);
  else
    {
      if ((TREE_CODE (decl) == VAR_DECL || TREE_CODE (decl) == FUNCTION_DECL)
	  && DECL_VIRTUAL_P (decl)
	  && (TREE_PUBLIC (decl) || DECL_EXTERNAL (decl))
	  && !symtab_node::get (decl))
	return lto_symtab_prevailing_virtual_decl (decl);
      return decl;
    }
}
