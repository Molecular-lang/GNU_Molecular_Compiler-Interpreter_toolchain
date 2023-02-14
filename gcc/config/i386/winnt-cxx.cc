/* Target support for C++ classes on Windows. */

#define IN_TARGET_CODE 1

#include "config.h"
#include "system.h"
#include "coretypes.h"
#include "cp/cp-tree.h" /* This is why we're a separate module.  */
#include "stringpool.h"
#include "attribs.h"

bool
i386_pe_type_dllimport_p (tree decl)
{
  gcc_assert (TREE_CODE (decl) == VAR_DECL 
	      || TREE_CODE (decl) == FUNCTION_DECL);

  if (TARGET_NOP_FUN_DLLIMPORT && TREE_CODE (decl) == FUNCTION_DECL)
    return false;

  /* We ignore the dllimport attribute for inline member functions.
     This differs from MSVC behavior which treats it like GNUC
     'extern inline' extension.  Also ignore for template
     instantiations with linkonce semantics and artificial methods.  */
  if (TREE_CODE (decl) ==  FUNCTION_DECL
      && (DECL_DECLARED_INLINE_P (decl)
	  || DECL_TEMPLATE_INSTANTIATION (decl)
	  || DECL_ARTIFICIAL (decl)))
    return false;
  
  /* Overrides of the class dllimport decls by out-of-class definitions are 
     handled by tree.cc:merge_dllimport_decl_attributes.   */
  return true;
}

bool
i386_pe_type_dllexport_p (tree decl)
{
  gcc_assert (TREE_CODE (decl) == VAR_DECL 
              || TREE_CODE (decl) == FUNCTION_DECL);

  /* Avoid exporting compiler-generated default dtors and copy ctors.
     The only artificial methods that need to be exported are virtual
     and non-virtual thunks.  */
  if (TREE_CODE (TREE_TYPE (decl)) == METHOD_TYPE
      && DECL_ARTIFICIAL (decl) && !DECL_THUNK_P (decl))
    return false;
  if (TREE_CODE (decl) == FUNCTION_DECL
      && DECL_DECLARED_INLINE_P (decl))
    {
      if (DECL_REALLY_EXTERN (decl)
	  || !flag_keep_inline_dllexport)
	return false;
    }
  return true;
}

static inline void maybe_add_dllimport (tree decl) 
{
  if (i386_pe_type_dllimport_p (decl))
    DECL_DLLIMPORT_P (decl) = 1;
}

static inline void maybe_add_dllexport (tree decl) 
{
  if (i386_pe_type_dllexport_p (decl))
    {   
      tree decl_attrs = DECL_ATTRIBUTES (decl);
      if (lookup_attribute ("dllexport", decl_attrs) != NULL_TREE)
	/* Already done.  */
	return;
      DECL_ATTRIBUTES (decl) = tree_cons (get_identifier ("dllexport"),
					  NULL_TREE, decl_attrs);
    }
}

void
i386_pe_adjust_class_at_definition (tree t)
{
  tree member;

  gcc_assert (CLASS_TYPE_P (t));
 
 
  if (lookup_attribute ("dllexport", TYPE_ATTRIBUTES (t)) != NULL_TREE)
    {
      tree tmv = TYPE_MAIN_VARIANT (t);

      /* Make sure that we set dllexport attribute to typeinfo's
	 base declaration, as otherwise it would fail to be exported as
	 it isn't a class-member.  */
      if (tmv != NULL_TREE
	  && CLASSTYPE_TYPEINFO_VAR (tmv) != NULL_TREE)
	{
	  tree na, ti_decl = CLASSTYPE_TYPEINFO_VAR (tmv);
	  na = tree_cons (get_identifier ("dllexport"), NULL_TREE,
			  NULL_TREE);
	  decl_attributes (&ti_decl, na, 0);
	}

      /* Check FUNCTION_DECL's and static VAR_DECL's.  */
      for (member = TYPE_FIELDS (t); member; member = DECL_CHAIN (member))
	if (TREE_CODE (member) == VAR_DECL)     
	  maybe_add_dllexport (member);
	else if (TREE_CODE (member) == FUNCTION_DECL)
	  {
	    tree thunk;
	    maybe_add_dllexport (member);
	  
	    /* Also add the attribute to its thunks.  */
	    for (thunk = DECL_THUNKS (member); thunk;
		 thunk = TREE_CHAIN (thunk))
	      maybe_add_dllexport (thunk);
	  }

      /* Check vtables  */
      for (member = CLASSTYPE_VTABLES (t);
	   member; member = DECL_CHAIN (member))
	if (TREE_CODE (member) == VAR_DECL) 
	  maybe_add_dllexport (member);
    }

  else if (lookup_attribute ("dllimport", TYPE_ATTRIBUTES (t)) != NULL_TREE)
    {
      /* We don't actually add the attribute to the decl, just set the flag
	 that signals that the address of this symbol is not a compile-time
	 constant.   Any subsequent out-of-class declaration of members wil
	 cause the DECL_DLLIMPORT_P flag to be unset.
	 (See  tree.cc: merge_dllimport_decl_attributes).
	 That is just right since out-of class declarations can only be a
	 definition.   */

      /* Check FUNCTION_DECL's and static VAR_DECL's.  */
      for (member = TYPE_FIELDS (t); member; member = DECL_CHAIN (member))
	if (TREE_CODE (member) == VAR_DECL)     
	  maybe_add_dllimport (member);
	else if (TREE_CODE (member) == FUNCTION_DECL)
	  {
	    tree thunk;
	    maybe_add_dllimport (member);
	  
	    /* Also add the attribute to its thunks.  */
	    for (thunk = DECL_THUNKS (member); thunk;
		 thunk = DECL_CHAIN (thunk))
	      maybe_add_dllimport (thunk);
	  }
 
      /* Check vtables  */
      for (member = CLASSTYPE_VTABLES (t);
	   member;  member = DECL_CHAIN (member))
	if (TREE_CODE (member) == VAR_DECL) 
	  maybe_add_dllimport (member);

      /* We leave typeinfo tables alone.  We can't mark TI objects as
	dllimport, since the address of a secondary VTT may be needed
	for static initialization of a primary VTT.  VTT's  of
	dllimport'd classes should always be link-once COMDAT.  */ 
    }
}
