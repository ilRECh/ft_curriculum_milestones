#ifndef __tree_leaf_HPP
#define __tree_leaf_HPP

namespace ft {

// Returns:  pointer to a node which has no children
// Precondition:  __x != NULL.
template <class _NodePtr>
_NodePtr
__tree_leaf(_NodePtr __x) throw()
{
    while (true)
    {
        if (__x->__left_ != NULL)
        {
            __x = __x->__left_;
            continue;
        }
        if (__x->__right_ != NULL)
        {
            __x = __x->__right_;
            continue;
        }
        break;
    }
    return __x;
}

} // namespace ft


#endif // __tree_leaf_HPP
