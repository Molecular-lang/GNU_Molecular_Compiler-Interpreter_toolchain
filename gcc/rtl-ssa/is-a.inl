// is_a<> support for RTL SSA classes                               -*- C++ -*-
// Please review: $(src-dir)/SPL-README for Licencing info.

template<>
struct is_a_helper<rtl_ssa::def_info *> : static_is_a_helper<rtl_ssa::def_info *>
{
  static inline bool
  test (const rtl_ssa::access_info *ref)
  {
    return (ref->kind () == rtl_ssa::access_kind::SET
	    || ref->kind () == rtl_ssa::access_kind::PHI
	    || ref->kind () == rtl_ssa::access_kind::CLOBBER);
  }
};

template<>
struct is_a_helper<rtl_ssa::clobber_info *>
  : static_is_a_helper<rtl_ssa::clobber_info *>
{
  static inline bool
  test (const rtl_ssa::access_info *ref)
  {
    return ref->kind () == rtl_ssa::access_kind::CLOBBER;
  }
};

template<>
struct is_a_helper<rtl_ssa::use_info *>
  : static_is_a_helper<rtl_ssa::use_info *>
{
  static inline bool
  test (const rtl_ssa::access_info *ref)
  {
    return ref->kind () == rtl_ssa::access_kind::USE;
  }
};

template<>
struct is_a_helper<rtl_ssa::set_info *>
  : static_is_a_helper<rtl_ssa::set_info *>
{
  static inline bool
  test (const rtl_ssa::access_info *ref)
  {
    return (ref->kind () == rtl_ssa::access_kind::SET
	    || ref->kind () == rtl_ssa::access_kind::PHI);
  }
};

template<>
struct is_a_helper<rtl_ssa::phi_info *>
  : static_is_a_helper<rtl_ssa::phi_info *>
{
  static inline bool
  test (const rtl_ssa::access_info *ref)
  {
    return ref->kind () == rtl_ssa::access_kind::PHI;
  }
};

template<>
struct is_a_helper<rtl_ssa::set_node *>
  : static_is_a_helper<rtl_ssa::set_node *>
{
  static inline bool
  test (const rtl_ssa::def_node *node)
  {
    return node->contains_set ();
  }
};

template<>
struct is_a_helper<rtl_ssa::clobber_group *>
  : static_is_a_helper<rtl_ssa::clobber_group *>
{
  static inline bool
  test (const rtl_ssa::def_node *node)
  {
    return node->contains_clobber ();
  }
};
