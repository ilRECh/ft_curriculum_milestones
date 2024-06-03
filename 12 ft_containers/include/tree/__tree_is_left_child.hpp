#ifndef __TREE_IS_LEFT_CHILD_HPP
#define __TREE_IS_LEFT_CHILD_HPP

namespace ft {

// Returns:  true if __x is a left child of its parent, else false
// Precondition:  __x != NULL.
template <class _NodePtr>
inline bool __tree_is_left_child(_NodePtr node) throw()
{
    return node == node->__parent_->__left_;
}

} // namespace ft


#endif //__TREE_IS_LEFT_CHILD_HPP
