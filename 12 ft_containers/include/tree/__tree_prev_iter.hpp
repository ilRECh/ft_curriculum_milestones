#ifndef __tree_prev_iter_HPP
#define __tree_prev_iter_HPP

namespace ft {

// Returns:  pointer to the previous in-order node before __x.
// Precondition:  __x != NULL.
// Note: __x may be the end node.
template <class _NodePtr, class _EndNodePtr>
inline _NodePtr __tree_prev_iter(_EndNodePtr __endNode) throw()
{
    if (__endNode->__left_ != NULL)
        return __tree_max(__endNode->__left_);
    _NodePtr __node = static_cast<_NodePtr>(__endNode);
    while (__tree_is_left_child(__node))
        __node = __node->__get_parent();
    return __node->__get_parent();
}

} // namespace ft


#endif // __tree_prev_iter_HPP
