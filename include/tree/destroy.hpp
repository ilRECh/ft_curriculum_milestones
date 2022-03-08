#ifndef destroy_HPP
#define destroy_HPP

namespace ft {

template <class _Tp, class _Compare, class _Allocator>
void
ft::__tree<_Tp, _Compare, _Allocator>::destroy(__node_pointer __nd) throw()
{
    if (__nd != NULL)
    {
        destroy(static_cast<__node_pointer>(__nd->__left_));
        destroy(static_cast<__node_pointer>(__nd->__right_));
        __node_allocator& __na = __node_alloc();
        __node_traits::destroy(__na, _NodeTypes::__get_ptr(__nd->__value_));
        __node_traits::deallocate(__na, __nd, 1);
    }
}

} // namespace ft


#endif // destroy_HPP
