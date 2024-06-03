#ifndef __TREE_MAX_HPP
#define __TREE_MAX_HPP

namespace ft {

// Returns:  pointer to the right-most node under __x.
// Precondition:  __x != NULL.
template <class _NodePtr>
inline _NodePtr __tree_max(_NodePtr __x) throw()
{
    while (__x->__right_ != NULL)
        __x = __x->__right_;
    return __x;
}

} // namespace ft


#endif //__TREE_MAX_HPP
