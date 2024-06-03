#ifndef __count_unique_HPP
#define __count_unique_HPP

namespace ft {

template <class _Tp, class _Compare, class _Allocator>
template <class _Key>
typename __tree<_Tp, _Compare, _Allocator>::size_type
__tree<_Tp, _Compare, _Allocator>::__count_unique(const _Key& __k) const
{
    __node_pointer __root = __get_root();
    while (__root != NULL)
    {
        if (value_comp()(__k, __root->__value_))
        {
            __root = static_cast<__node_pointer>(__root->__left_);
        }
        else if (value_comp()(__root->__value_, __k))
            __root = static_cast<__node_pointer>(__root->__right_);
        else
            return 1;
    }
    return 0;
}


} // namespace ft

#endif // __count_unique_HPP
