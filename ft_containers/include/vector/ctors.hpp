#ifndef ctors_HPP
#define ctors_HPP

#include "../../vector.hpp"

namespace ft {

template <class _Tp, class _Allocator>
ft::vector<_Tp, _Allocator>::vector(size_type __n)
{
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__n);
    }
}

template <class _Tp, class _Allocator>
ft::vector<_Tp, _Allocator>::vector(size_type __n, const value_type& __x)
{
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__n, __x);
    }
}

template <class _Tp, class _Allocator>
ft::vector<_Tp, _Allocator>::vector(size_type __n, const value_type& __x, const allocator_type& __a)
    : __base(__a)
{
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__n, __x);
    }
}

template <class _Tp, class _Allocator>
template <class _InputIterator>
ft::vector<_Tp, _Allocator>::vector(_InputIterator __first,
       typename enable_if<std::__is_input_iterator  <_InputIterator>::value &&
                         !std::__is_forward_iterator<_InputIterator>::value &&
                         std::is_constructible<
                            value_type,
                            typename ft::iterator_traits<_InputIterator>::reference>::value,
                          _InputIterator>::type __last)
{
    for (; __first != __last; ++__first)
        __emplace_back(*__first);
}

template <class _Tp, class _Allocator>
template <class _InputIterator>
ft::vector<_Tp, _Allocator>::vector(_InputIterator __first, _InputIterator __last, const allocator_type& __a,
       typename enable_if<std::__is_input_iterator  <_InputIterator>::value &&
                         !std:: __is_forward_iterator<_InputIterator>::value &&
                         std::is_constructible<
                            value_type,
                            typename iterator_traits<_InputIterator>::reference>::value>::type*)
    : __base(__a)
{
    for (; __first != __last; ++__first)
        __emplace_back(*__first);
}

template <class _Tp, class _Allocator>
template <class _ForwardIterator>
ft::vector<_Tp, _Allocator>::vector(_ForwardIterator __first,
                                typename enable_if<std::__is_forward_iterator<_ForwardIterator>::value &&
                                std::is_constructible<
                                   value_type,
                                   typename iterator_traits<_ForwardIterator>::reference>::value,
                                                   _ForwardIterator>::type __last)
{
    size_type __n = static_cast<size_type>(_VSTD::distance(__first, __last));
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__first, __last, __n);
    }
}

template <class _Tp, class _Allocator>
template <class _ForwardIterator>
ft::vector<_Tp, _Allocator>::vector(_ForwardIterator __first, _ForwardIterator __last, const allocator_type& __a,
                                typename enable_if<std::__is_forward_iterator<_ForwardIterator>::value &&
                                std::is_constructible<
                                   value_type,
                                   typename iterator_traits<_ForwardIterator>::reference>::value>::type*)
    : __base(__a)
{
    size_type __n = static_cast<size_type>(__last - __first);
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__first, __last, __n);
    }
}

template <class _Tp, class _Allocator>
ft::vector<_Tp, _Allocator>::vector(const vector& __x)
    : __base(__alloc_traits::select_on_container_copy_construction(__x.__alloc()))
{
    size_type __n = __x.size();
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__x.__begin_, __x.__end_, __n);
    }
}

template <class _Tp, class _Allocator>
ft::vector<_Tp, _Allocator>::vector(const ft::vector& __x, const std::allocator_type& __a)
    : __base(__a)
{
    size_type __n = __x.size();
    if (__n > 0)
    {
        __vallocate(__n);
        __construct_at_end(__x.__begin_, __x.__end_, __n);
    }
}

} // namespace ft


#endif // ctors_HPP
