#ifndef __insert_node_at_HPP
#define __insert_node_at_HPP

namespace ft {

template <class _Tp, class _Compare, class _Allocator>
void __tree<_Tp, _Compare, _Allocator>::__insert_node_at(
    __parent_pointer __parent, __node_base_pointer& __child,
    __node_base_pointer __new_node) throw()
{
    __new_node->__left_   = NULL;
    __new_node->__right_  = NULL;
    __new_node->__parent_ = __parent;
    // __new_node->__is_black_ is initialized in __tree_balance_after_insert
    __child = __new_node;
    if (__begin_node()->__left_ != NULL)
        __begin_node() = static_cast<__iter_pointer>(__begin_node()->__left_);
    __tree_balance_after_insert(__end_node()->__left_, __child);
    ++size();
}

} // namespace ft


#endif // __insert_node_at_HPP
