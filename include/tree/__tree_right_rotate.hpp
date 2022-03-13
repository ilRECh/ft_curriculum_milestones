#ifndef __tree_right_rotate_HPP
#define __tree_right_rotate_HPP

namespace ft {

// Effects:  Makes __x->__left_ the subtree root with __x as its right child
//           while preserving in-order order.
// Precondition:  __x->__left_ != NULL
template <class _NodePtr>
void
__tree_right_rotate(_NodePtr __x) throw()
{
    _NodePtr __y = __x->__left_;
    __x->__left_ = __y->__right_;
    if (__x->__left_ != NULL)
        __x->__left_->__set_parent(__x);
    __y->__parent_ = __x->__parent_;
    if (__tree_is_left_child(__x))
        __x->__parent_->__left_ = __y;
    else
        __x->__get_parent()->__right_ = __y;
    __y->__right_ = __x;
    __x->__set_parent(__y);
}

}

#endif // __tree_right_rotate_HPP
