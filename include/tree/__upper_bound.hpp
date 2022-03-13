#ifndef __UPPER_BOUND_HPP
#define __UPPER_BOUND_HPP

namespace ft {

template <class _Tp, class _Compare, class _Allocator>
template <class _Key>
typename __tree<_Tp, _Compare, _Allocator>::iterator
__tree<_Tp, _Compare, _Allocator>::__upper_bound(const _Key& __v,
                                                 __node_pointer __get_root,
                                                 __iter_pointer __result)
{
    while (__get_root != NULL)
    {
        if (value_comp()(__v, __get_root->__value_))
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
__tree<_Tp, _Compare, _Allocator>::__upper_bound(const _Key& __v,
                                                 __node_pointer __get_root,
                                                 __iter_pointer __result) const
{
    while (__get_root != NULL)
    {
        if (value_comp()(__v, __get_root->__value_))
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


#endif // __UPPER_BOUND_HPP
