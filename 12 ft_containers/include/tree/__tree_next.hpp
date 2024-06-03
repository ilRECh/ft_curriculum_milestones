#ifndef __TREE_NEXT_HPP
#define __TREE_NEXT_HPP

namespace ft {

// Returns:  pointer to the next in-order node after __x.
// Precondition:  __x != NULL.
template <class _NodePtr>
_NodePtr __tree_next(_NodePtr __x) throw()
{
    if (__x->__right_ != NULL)
        return ft::__tree_min(__x->__right_);
    while (not ft::__tree_is_left_child(__x))
        __x = __x->__get_parent();
    return __x->__get_parent();
}

} // namespace ft


#endif //__TREE_NEXT_HPP
