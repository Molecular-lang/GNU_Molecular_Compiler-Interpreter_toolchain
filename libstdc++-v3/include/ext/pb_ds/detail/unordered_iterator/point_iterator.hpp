// Please review: $(src-dir)/SPL-README for Licencing info.

/**
 * @file point_iterator.hpp
 * Contains an iterator class returned by the tables' find and insert
 * methods.
 *
 * This file is intended to be included inside a class definition, with
 * PB_DS_CLASS_C_DEC defined to the name of the enclosing class.
 */

#ifdef PB_DS_CLASS_C_DEC
/// Find type iterator.
class point_iterator_
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

  /// Default constructor.
  inline
  point_iterator_()
  : m_p_value(0)
  { }

  /// Copy constructor.
  inline
  point_iterator_(const point_iterator_& other)
  : m_p_value(other.m_p_value)
  { }

  /// Access.
  pointer
  operator->() const
  {
    _GLIBCXX_DEBUG_ASSERT(m_p_value != 0);
    return (m_p_value);
  }

  /// Access.
  reference
  operator*() const
  {
    _GLIBCXX_DEBUG_ASSERT(m_p_value != 0);
    return (*m_p_value);
  }

  /// Compares content to a different iterator object.
  bool
  operator==(const point_iterator_& other) const
  { return m_p_value == other.m_p_value; }

  /// Compares content to a different iterator object.
  bool
  operator==(const point_const_iterator_& other) const
  { return m_p_value == other.m_p_value; }

  /// Compares content to a different iterator object.
  bool
  operator!=(const point_iterator_& other) const
  { return m_p_value != other.m_p_value; }

  /// Compares content (negatively) to a different iterator object.
  bool
  operator!=(const point_const_iterator_& other) const
  { return m_p_value != other.m_p_value; }

  inline
  point_iterator_(pointer p_value) : m_p_value(p_value)
  { }

protected:
  friend class point_const_iterator_;

  friend class PB_DS_CLASS_C_DEC;

protected:
  pointer m_p_value;
};
#endif
