#ifndef vector_assign_HPP
#define vector_assign_HPP

#include "../../vector.hpp"

namespace ft {

template <class _Tp, class _Allocator>
template <class _InputIterator>
typename ft::enable_if
<
    std::__is_input_iterator  <_InputIterator>::value &&
    not std::__is_forward_iterator<_InputIterator>::value &&
    std::is_constructible<
       _Tp,
       typename iterator_traits<_InputIterator>::reference>::value,
    void
>::type
ft::vector<_Tp, _Allocator>::assign(_InputIterator __first, _InputIterator __last)
{
    clear();
    for (; __first != __last; ++__first)
        __emplace_back(*__first);
}

template <class _Tp, class _Allocator>
template <class _ForwardIterator>
typename ft::enable_if
<
    std::__is_forward_iterator<_ForwardIterator>::value &&
    std::is_constructible<
       _Tp,
       typename iterator_traits<_ForwardIterator>::reference>::value,
    void
>::type
ft::vector<_Tp, _Allocator>::assign(_ForwardIterator __first, _ForwardIterator __last)
{
    size_type __new_size = static_cast<size_type>(_VSTD::distance(__first, __last));
    if (__new_size <= capacity())
    {
        _ForwardIterator __mid = __last;
        bool __growing = false;
        if (__new_size > size())
        {
            __growing = true;
            __mid =  __first;
            _VSTD::advance(__mid, size());
        }
        pointer __m = _VSTD::copy(__first, __mid, this->__begin_);
        if (__growing)
            __construct_at_end(__mid, __last, __new_size - size());
        else
            this->__destruct_at_end(__m);
    }
    else
    {
        __vdeallocate();
        __vallocate(__recommend(__new_size));
        __construct_at_end(__first, __last, __new_size);
    }
    __invalidate_all_iterators();
}

template <class _Tp, class _Allocator>
void
vector<_Tp, _Allocator>::assign(size_type __n, const_reference __u)
{
    if (__n <= capacity())
    {
        size_type __s = size();
        _VSTD::fill_n(this->__begin_, _VSTD::min(__n, __s), __u);
        if (__n > __s)
            __construct_at_end(__n - __s, __u);
        else
            this->__destruct_at_end(this->__begin_ + __n);
    }
    else
    {
        __vdeallocate();
        __vallocate(__recommend(static_cast<size_type>(__n)));
        __construct_at_end(__n, __u);
    }
    __invalidate_all_iterators();
}

} // namespace ft


#endif // vector_assign_HPP
