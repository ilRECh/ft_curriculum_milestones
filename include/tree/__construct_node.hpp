#ifndef __construct_node_HPP
#define __construct_node_HPP

namespace ft {

template <class _Tp, class _Compare, class _Allocator>
typename __tree<_Tp, _Compare, _Allocator>::__node_holder
__tree<_Tp, _Compare, _Allocator>::__construct_node(const __container_value_type& __v)
{
    __node_allocator& __na = __node_alloc();
    __node_holder __h(__node_traits::allocate(__na, 1), _Dp(__na));
    __node_traits::construct(__na, _NodeTypes::__get_ptr(__h->__value_), __v);
    __h.get_deleter().__value_constructed = true;
    return __node_holder(std::__rv<__node_holder>(__h));
}

} // namespace ft


#endif // __construct_node_HPP
