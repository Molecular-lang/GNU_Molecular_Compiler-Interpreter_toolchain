/* Comparsion of AO ref.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef TREE_SSA_ALIAS_COMPARE_H
#define TREE_SSA_ALIAS_COMPARE_H

class operand_compare;
/* A class aggregating all connections and semantic equivalents
   for a given pair of semantic function candidates.  */
class ao_compare : public operand_compare
{
  public:
  enum ao_ref_diff
  {
    SEMANTICS = 1,
    BASE_ALIAS_SET = 2,
    REF_ALIAS_SET = 4,
    ACCESS_PATH = 8,
    DEPENDENCE_CLIQUE = 16
  };
  int compare_ao_refs (ao_ref *ref1, ao_ref *ref2, bool lto_streaming_safe, bool tbaa);
  void hash_ao_ref (ao_ref *ref, bool lto_streaming_safe, bool tbaa, inchash::hash &hstate);
};

#endif
