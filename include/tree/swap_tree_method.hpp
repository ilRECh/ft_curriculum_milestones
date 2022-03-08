#ifndef swap_tree_method_HPP
#define swap_tree_method_HPP

namespace ft {

template <class _Tp, class _Compare, class _Allocator>
void __tree<_Tp, _Compare, _Allocator>::swap(__tree& __t)
{
	using std::swap;
    swap(__begin_node_, __t.__begin_node_);
    swap(__compressedEndNode.first(), __t.__compressedEndNode.first());
    __swap_allocator(__node_alloc(), __t.__node_alloc());
    __compressedValueCompare.swap(__t.__compressedValueCompare);
    if (size() == 0)
        __begin_node() = __end_node();
    else
        __end_node()->__left_->__parent_ = static_cast<__parent_pointer>(__end_node());
    if (__t.size() == 0)
        __t.__begin_node() = __t.__end_node();
    else
        __t.__end_node()->__left_->__parent_ = static_cast<__parent_pointer>(__t.__end_node());
}

} // namespace ft


#endif // swap_tree_method_HPP
