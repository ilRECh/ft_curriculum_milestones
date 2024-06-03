#ifndef __tree_left_rotate_HPP
#define __tree_left_rotate_HPP

namespace ft {

// Effects:  Makes __x->__right_ the subtree root with __x as its left child
//           while preserving in-order order.
// Precondition:  __x->__right_ != NULL
template <class _NodePtr>
void
__tree_left_rotate(_NodePtr __x) throw()
{
    _NodePtr __y = __x->__right_;
    __x->__right_ = __y->__left_;
    if (__x->__right_ != NULL)
        __x->__right_->__set_parent(__x);
    __y->__parent_ = __x->__parent_;
    if (__tree_is_left_child(__x))
        __x->__parent_->__left_ = __y;
    else
        __x->__get_parent()->__right_ = __y;
    __y->__left_ = __x;
    __x->__set_parent(__y);
}

} // namespace ft


#endif // __tree_left_rotate_HPP
