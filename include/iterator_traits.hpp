#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "type_traits.hpp"
#include "utility.hpp"

namespace ft
{

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag       : public ft::input_iterator_tag {};
struct bidirectional_iterator_tag : public ft::forward_iterator_tag {};
struct random_access_iterator_tag : public ft::bidirectional_iterator_tag {};

template <class _Iter, bool> struct __iterator_traits_impl {};

template <class _Iter>
struct __iterator_traits_impl<_Iter, true>
{
    typedef typename _Iter::difference_type   difference_type;
    typedef typename _Iter::value_type        value_type;
    typedef typename _Iter::pointer           pointer;
    typedef typename _Iter::reference         reference;
    typedef typename _Iter::iterator_category iterator_category;
};

template <class _Iter, bool> struct __iterator_traits {};

template <class _Iter>
struct __iterator_traits<_Iter, true>
    :  ft::__iterator_traits_impl
      <
        _Iter,
        std::is_convertible<typename _Iter::iterator_category, ft::input_iterator_tag>::value ||
        std::is_convertible<typename _Iter::iterator_category, ft::output_iterator_tag>::value
      >
{};

// iterator_traits<Iterator> will only have the nested types if Iterator::iterator_category
//    exists.  Else iterator_traits<Iterator> will be an empty class.  This is a
//    conforming extension which allows some programs to compile and behave as
//    the client expects instead of failing at compile time.

template <class _Iter>
struct iterator_traits
    : __iterator_traits<_Iter, std::__has_iterator_typedefs<_Iter>::value> {};

template<class _Tp>
struct iterator_traits<_Tp*>
{
    typedef ptrdiff_t difference_type;
    typedef typename ft::remove_cv<_Tp>::type value_type;
    typedef _Tp* pointer;
    typedef _Tp& reference;
    typedef std::random_access_iterator_tag iterator_category;
};

} // namespace ft


#endif // ITERATOR_HPP
