#ifndef __node_insert_multi_HPP
#define __node_insert_multi_HPP

namespace ft {

template <class _Tp, class _Compare, class _Allocator>
typename __tree<_Tp, _Compare, _Allocator>::iterator
__tree<_Tp, _Compare, _Allocator>::__node_insert_multi(__node_pointer __nd)
{
    __parent_pointer __parent;
    __node_base_pointer& __child = __find_leaf_high(__parent, _NodeTypes::__get_key(__nd->__value_));
    __insert_node_at(__parent, __child, static_cast<__node_base_pointer>(__nd));
    return iterator(__nd);
}

} // namespace ft


#endif // __node_insert_multi_HPP
