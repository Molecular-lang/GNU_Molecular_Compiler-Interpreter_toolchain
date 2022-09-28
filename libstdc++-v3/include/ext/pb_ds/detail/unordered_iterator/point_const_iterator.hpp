// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file unordered_iterator/point_const_iterator.hpp
 * Contains an iterator class returned by the tables' const find and insert
 * methods.
 *
 * * This file is intended to be included inside a class definition, with
 * PB_DS_CLASS_C_DEC defined to the name of the enclosing class.
 */

#ifdef PB_DS_CLASS_C_DEC
class point_iterator_;

/// Const point-type iterator.
class point_const_iterator_
{
public:
  /// Category.
  typedef trivial_iterator_tag iterator_category;

  /// Difference type.
  typedef trivial_iterator_difference_type difference_type;

  /// Iterator's value type.
  typedef value_type_ value_type;

  /// Iterator's pointer type.
  typedef pointer_ pointer;

  /// Iterator's const pointer type.
  typedef const_pointer_ const_pointer;

  /// Iterator's reference type.
  typedef reference_ reference;

  /// Iterator's const reference type.
  typedef const_reference_ const_reference;

  inline
  point_const_iterator_(const_pointer p_value) : m_p_value(p_value)
  { }

  /// Default constructor.
  inline
  point_const_iterator_() : m_p_value(0)
  { }

  /// Copy constructor.
  inline
  point_const_iterator_(const point_const_iterator_& other)
  : m_p_value(other.m_p_value)
  { }

  /// Copy constructor.
  inline
  point_const_iterator_(const point_iterator_& other)
  : m_p_value(other.m_p_value)
  { }

  /// Access.
  const_pointer
  operator->() const
  {
    _GLIBCXX_DEBUG_ASSERT(m_p_value != 0);
    return m_p_value;
  }

  /// Access.
  const_reference
  operator*() const
  {
    _GLIBCXX_DEBUG_ASSERT(m_p_value != 0);
    return *m_p_value;
  }

  /// Compares content to a different iterator object.
  bool
  operator==(const point_iterator_& other) const
  { return m_p_value == other.m_p_value; }

  /// Compares content to a different iterator object.
  bool
  operator==(const point_const_iterator_& other) const
  { return m_p_value == other.m_p_value; }

  /// Compares content (negatively) to a different iterator object.
  bool
  operator!=(const point_iterator_& other) const
  { return m_p_value != other.m_p_value; }

  /// Compares content (negatively) to a different iterator object.
  bool
  operator!=(const point_const_iterator_& other) const
  { return m_p_value != other.m_p_value; }

protected:
  const_pointer m_p_value;

  friend class point_iterator_;

  friend class PB_DS_CLASS_C_DEC;
};
#endif
