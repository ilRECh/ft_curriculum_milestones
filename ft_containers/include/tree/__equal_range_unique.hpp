#ifndef __EQUAL_RANGE_UNIQUE_HPP
#define __EQUAL_RANGE_UNIQUE_HPP

namespace ft {

template <class _Tp, class _Compare, class _Allocator>
template <class _Key>
ft::pair<typename __tree<_Tp, _Compare, _Allocator>::iterator,
     typename __tree<_Tp, _Compare, _Allocator>::iterator>
__tree<_Tp, _Compare, _Allocator>::__equal_range_unique(const _Key& __k)
{
    __iter_pointer __result = __end_node();
    __node_pointer __root = __get_root();
    while (__root != NULL)
    {
        if (value_comp()(__k, __root->__value_))
        {
            __result = static_cast<__iter_pointer>(__root);
            __root = static_cast<__node_pointer>(__root->__left_);
        }
        else if (value_comp()(__root->__value_, __k))
        {
            __root = static_cast<__node_pointer>(__root->__right_);
        }
        else
        {
            return ft::pair<iterator, iterator>(
                iterator(__root),
                iterator(
                    __root->__right_ != NULL ?
                    static_cast<__iter_pointer>(__tree_min(__root->__right_)) :
                    __result));
        }
    }
    return ft::pair<iterator, iterator>(iterator(__result), iterator(__result));
}

template <class _Tp, class _Compare, class _Allocator>
template <class _Key>
ft::pair<typename __tree<_Tp, _Compare, _Allocator>::const_iterator,
     typename __tree<_Tp, _Compare, _Allocator>::const_iterator>
__tree<_Tp, _Compare, _Allocator>::__equal_range_unique(const _Key& __k) const
{
    __iter_pointer __result = __end_node();
    __node_pointer __root = __get_root();
    while (__root != NULL)
    {
        if (value_comp()(__k, __root->__value_))
        {
            __result = static_cast<__iter_pointer>(__root);
            __root = static_cast<__node_pointer>(__root->__left_);
        }
        else if (value_comp()(__root->__value_, __k))
        {
            __root = static_cast<__node_pointer>(__root->__right_);
        }
        else
        {
            return ft::pair<const_iterator, const_iterator>(
                const_iterator(__root),
                const_iterator(
                    __root->__right_ != NULL ?
                    static_cast<__iter_pointer>(__tree_min(__root->__right_)) :
                    __result));
        }
    }
    return ft::pair<const_iterator, const_iterator>(const_iterator(__result), const_iterator(__result));
}

} // namespace ft

#endif // __EQUAL_RANGE_UNIQUE_HPP
