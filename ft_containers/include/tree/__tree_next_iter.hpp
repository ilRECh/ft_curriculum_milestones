#ifndef __tree_next_iter_HPP
#define __tree_next_iter_HPP

namespace ft {

template <class _EndNodePtr, class _NodePtr>
inline _EndNodePtr __tree_next_iter(_NodePtr __x) throw()
{
    if (__x->__right_ != NULL)
        return static_cast<_EndNodePtr>(__tree_min(__x->__right_));
    while (not __tree_is_left_child(__x))
        __x = __x->__get_parent();
    return static_cast<_EndNodePtr>(__x->__parent_);
}

} // namespace ft


#endif // __tree_next_iter_HPP
