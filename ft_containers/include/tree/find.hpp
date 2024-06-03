#ifndef find_HPP
#define find_HPP

namespace ft {

template <class _Tp, class _Compare, class _Allocator>
template <class _Key>
typename __tree<_Tp, _Compare, _Allocator>::iterator
__tree<_Tp, _Compare, _Allocator>::find(const _Key& __v)
{
    iterator __p = __lower_bound(__v, __get_root(), __end_node());
    if (__p != end() and not value_comp()(__v, *__p))
        return __p;
    return end();
}

template <class _Tp, class _Compare, class _Allocator>
template <class _Key>
typename __tree<_Tp, _Compare, _Allocator>::const_iterator
__tree<_Tp, _Compare, _Allocator>::find(const _Key& __v) const
{
    const_iterator __p = __lower_bound(__v, __get_root(), __end_node());
    if (__p != end() and not value_comp()(__v, *__p))
        return __p;
    return end();
}

} // namespace ft


#endif // find_HPP
