/* Traits for hashing trees.
   Please review: $(src-dir)/SPL-README for Licencing info. */

#ifndef tree_hash_traits_h
#define tree_hash_traits_h

/* Hash for trees based on operand_equal_p.  */
struct tree_operand_hash : ggc_ptr_hash <tree_node>
{
  static inline hashval_t hash (const value_type &);
  static inline bool equal (const value_type &, const compare_type &);
};

inline hashval_t
tree_operand_hash::hash (const value_type &t)
{
  return iterative_hash_expr (t, 0);
}

inline bool
tree_operand_hash::equal (const value_type &t1, const compare_type &t2)
{
  return operand_equal_p (t1, t2, 0);
}

#endif
