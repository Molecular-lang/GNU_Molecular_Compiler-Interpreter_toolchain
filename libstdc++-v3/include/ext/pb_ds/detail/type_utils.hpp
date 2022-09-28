// Please review: $(src-dir)/SPL-README for Licencing info.

#ifndef PB_DS_TYPE_UTILS_HPP
#define PB_DS_TYPE_UTILS_HPP

#include <cstddef>
#include <utility>
#include <tr1/type_traits>
#include <ext/type_traits.h>
#include <ext/numeric_traits.h>

namespace __gnu_pbds
{
  namespace detail
  {
    using std::tr1::is_same;
    using std::tr1::is_const;
    using std::tr1::is_pointer;
    using std::tr1::is_reference;
    using std::tr1::is_fundamental;
    using std::tr1::is_member_object_pointer;
    using std::tr1::is_member_pointer;
    using std::tr1::is_base_of;
    using std::tr1::remove_const;
    using std::tr1::remove_reference;

    // Need integral_const<bool, true> <-> integral_const<int, 1>, so
    // because of this use the following typedefs instead of importing
    // std::tr1's.
    using std::tr1::integral_constant;
    typedef std::tr1::integral_constant<int, 1> true_type;
    typedef std::tr1::integral_constant<int, 0> false_type;

    using __gnu_cxx::__conditional_type;
    using __gnu_cxx::__numeric_traits;

    template<typename T>
    struct is_const_pointer
    {
      enum
	{
	  value = is_const<T>::value && is_pointer<T>::value
	};
    };

    template<typename T>
    struct is_const_reference
    {
      enum
	{
	  value = is_const<T>::value && is_reference<T>::value
	};
    };

    template<typename T>
    struct is_simple
    {
      enum
	{
	  value = is_fundamental<typename remove_const<T>::type>::value 
	  || is_pointer<typename remove_const<T>::type>::value 
	  || is_member_pointer<T>::value 
	};
    };

    template<typename T>
    class is_pair
    {
    private:
      template<typename U>
      struct is_pair_imp
      {
	enum
	  {
	    value = 0
	  };
      };

      template<typename U, typename V>
      struct is_pair_imp<std::pair<U,V> >
      {
	enum
	  {
	    value = 1
	  };
      };

    public:
      enum
	{
	  value = is_pair_imp<T>::value
	};
    };

    // Use C++11's static_assert if possible.
#if __cplusplus >= 201103L
#define PB_DS_STATIC_ASSERT(UNIQUE, E)  static_assert(E, #UNIQUE)
#else
    template<bool>
    struct __static_assert;

    template<>
    struct __static_assert<true>
    { };

    template<int>
    struct __static_assert_dumclass
    {
      enum
	{
	  v = 1
	};
    };

#define PB_DS_STATIC_ASSERT(UNIQUE, E)  \
    typedef __gnu_pbds::detail::__static_assert_dumclass<sizeof(__gnu_pbds::detail::__static_assert<bool(E)>)> UNIQUE##__static_assert_type

#endif

    template<typename Type>
    struct type_to_type
    {
      typedef Type type;
    };
  } // namespace detail
} // namespace __gnu_pbds

#endif 
