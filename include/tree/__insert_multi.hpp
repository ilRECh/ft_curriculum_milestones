#ifndef __insert_multi_HPP
#define __insert_multi_HPP

namespace ft {

template <class _Tp, class _Compare, class _Allocator>
typename __tree<_Tp, _Compare, _Allocator>::iterator
__tree<_Tp, _Compare, _Allocator>::__insert_multi(const __container_value_type& __v)
{
    __parent_pointer __parent;
    __node_base_pointer& __child = __find_leaf_high(__parent, _NodeTypes::__get_key(__v));
    __node_holder __h = __construct_node(__v);
    __insert_node_at(__parent, __child, static_cast<__node_base_pointer>(__h.get()));
    return iterator(__h.release());
}


} // namespace ft


#endif // __insert_multi_HPP
