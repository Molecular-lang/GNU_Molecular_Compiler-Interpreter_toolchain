/* IPA handling of references. */

#ifndef GCC_IPA_REFERENCE_H
#define GCC_IPA_REFERENCE_H

/* In ipa-reference.cc  */
bitmap ipa_reference_get_read_global (struct cgraph_node *fn);
bitmap ipa_reference_get_written_global (struct cgraph_node *fn);
void ipa_reference_cc_finalize (void);
int ipa_reference_var_uid (tree t);

#endif  /* GCC_IPA_REFERENCE_H  */

