#ifndef detach_HPP
#define detach_HPP

#include "tree.hpp"

namespace ft {

// Precondition:  size() != 0
template <class _Tp, class _Compare, class _Allocator>
typename ft::__tree<_Tp, _Compare, _Allocator>::__node_pointer
ft::__tree<_Tp, _Compare, _Allocator>::__detach()
{
    __node_pointer __cache = static_cast<__node_pointer>(__begin_node());
    __begin_node() = __end_node();
    __end_node()->__left_->__parent_ = NULL;
    __end_node()->__left_ = NULL;
    size() = 0;
    // __cache->__left_ == NULL
    if (__cache->__right_ != NULL)
        __cache = static_cast<__node_pointer>(__cache->__right_);
    // __cache->__left_ == NULL
    // __cache->__right_ == NULL
    return __cache;
}

// Precondition:  __cache != NULL
//    __cache->left_ == NULL
//    __cache->right_ == NULL
//    This is no longer a red-black tree
template <class _Tp, class _Compare, class _Allocator>
typename __tree<_Tp, _Compare, _Allocator>::__node_pointer
ft::__tree<_Tp, _Compare, _Allocator>::__detach(__node_pointer __cache)
{
    if (__cache->__parent_ == NULL)
        return NULL;
    if (__tree_is_left_child(static_cast<__node_base_pointer>(__cache)))
    {
        __cache->__parent_->__left_ = NULL;
        __cache = static_cast<__node_pointer>(__cache->__parent_);
        if (__cache->__right_ == NULL)
            return __cache;
        return static_cast<__node_pointer>(__tree_leaf(__cache->__right_));
    }
    // __cache is right child
    __cache->__get_parent()->__right_ = NULL;
    __cache = static_cast<__node_pointer>(__cache->__parent_);
    if (__cache->__left_ == NULL)
        return __cache;
    return static_cast<__node_pointer>(ft::__tree_leaf(__cache->__left_));
}

} // namespace ft


#endif // detach_HPP
