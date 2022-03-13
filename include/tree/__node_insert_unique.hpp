#ifndef __node_insert_unique_HPP
#define __node_insert_unique_HPP

namespace ft {


template <class _Tp, class _Compare, class _Allocator>
pair<typename __tree<_Tp, _Compare, _Allocator>::iterator, bool>
__tree<_Tp, _Compare, _Allocator>::__node_insert_unique(__node_pointer __nd)
{
    __parent_pointer __parent;
    __node_base_pointer& __child = __find_equal(__parent, __nd->__value_);
    __node_pointer __r = static_cast<__node_pointer>(__child);
    bool __inserted = false;
    if (__child == NULL)
    {
        __insert_node_at(__parent, __child, static_cast<__node_base_pointer>(__nd));
        __r = __nd;
        __inserted = true;
    }
    return ft::pair<iterator, bool>(iterator(__r), __inserted);
}

template <class _Tp, class _Compare, class _Allocator>
typename __tree<_Tp, _Compare, _Allocator>::iterator
__tree<_Tp, _Compare, _Allocator>::__node_insert_unique(const_iterator __p,
                                                        __node_pointer __nd)
{
    __parent_pointer __parent;
    __node_base_pointer __dummy;
    __node_base_pointer& __child = __find_equal(__p, __parent, __nd->__value_);
    __node_pointer __r = static_cast<__node_pointer>(__child);
    if (__child == NULL)
    {
        __insert_node_at(__parent, __child, static_cast<__node_base_pointer>(__nd));
        __r = __nd;
    }
    return iterator(__r);
}


} // namespace ft


#endif // __node_insert_unique_HPP
