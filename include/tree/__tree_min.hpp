#ifndef __TREE_MIN_HPP
#define __TREE_MIN_HPP

namespace ft {

// Returns:  pointer to the left-most node under __x.
// Precondition:  __x != NULL.
template <class _NodePtr>
inline _NodePtr __tree_min(_NodePtr __x) throw()
{
    while (__x->__left_ != NULL)
        __x = __x->__left_;
    return __x;
}

} // namespace ft


#endif //__TREE_MIN_HPP
