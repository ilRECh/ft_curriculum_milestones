#ifndef __LOWER_BOUND_HPP
#define __LOWER_BOUND_HPP

namespace ft {

template <class _Tp, class _Compare, class _Allocator>
template <class _Key>
typename __tree<_Tp, _Compare, _Allocator>::iterator
__tree<_Tp, _Compare, _Allocator>::__lower_bound(const _Key& __v,
                                                 __node_pointer __get_root,
                                                 __iter_pointer __result)
{
    while (__get_root != NULL)
    {
        if (not value_comp()(__get_root->__value_, __v))
        {
            __result = static_cast<__iter_pointer>(__get_root);
            __get_root = static_cast<__node_pointer>(__get_root->__left_);
        }
        else
            __get_root = static_cast<__node_pointer>(__get_root->__right_);
    }
    return iterator(__result);
}

template <class _Tp, class _Compare, class _Allocator>
template <class _Key>
typename __tree<_Tp, _Compare, _Allocator>::const_iterator
__tree<_Tp, _Compare, _Allocator>::__lower_bound(const _Key& __v,
                                                 __node_pointer __get_root,
                                                 __iter_pointer __result) const
{
    while (__get_root != NULL)
    {
        if (not value_comp()(__get_root->__value_, __v))
        {
            __result = static_cast<__iter_pointer>(__get_root);
            __get_root = static_cast<__node_pointer>(__get_root->__left_);
        }
        else
            __get_root = static_cast<__node_pointer>(__get_root->__right_);
    }
    return const_iterator(__result);
}


} // namespace ft


#endif // __LOWER_BOUND_HPP
