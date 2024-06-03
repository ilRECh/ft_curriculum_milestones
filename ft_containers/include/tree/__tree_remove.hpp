#ifndef __tree_remove_HPP
#define __tree_remove_HPP

namespace ft {
    
// Precondition:  __get_root != NULL && __z != NULL.
//                __tree_invariant(__get_root) == true.
//                __z == __get_root or == a direct or indirect child of __get_root.
// Effects:  unlinks __z from the tree rooted at __get_root, rebalancing as needed.
// Postcondition: __tree_invariant(end_node->__left_) == true && end_node->__left_
//                nor any of its children refer to __z.  end_node->__left_
//                may be different than the value passed in as __get_root.
template <class _NodePtr>
void
__tree_remove(_NodePtr __get_root, _NodePtr __z) throw()
{
    // __z will be removed from the tree.  Client still needs to destruct/deallocate it
    // __y is either __z, or if __z has two children, __tree_next(__z).
    // __y will have at most one child.
    // __y will be the initial hole in the tree (make the hole at a leaf)
    _NodePtr __y = (__z->__left_ == NULL || __z->__right_ == NULL) ?
                    __z : ft::__tree_next(__z);
    // __x is __y's possibly null single child
    _NodePtr __x = __y->__left_ != NULL ? __y->__left_ : __y->__right_;
    // __w is __x's possibly null uncle (will become __x's sibling)
    _NodePtr __w = NULL;
    // link __x to __y's parent, and find __w
    if (__x != NULL)
        __x->__parent_ = __y->__parent_;
    if (ft::__tree_is_left_child(__y))
    {
        __y->__parent_->__left_ = __x;
        if (__y != __get_root)
            __w = __y->__get_parent()->__right_;
        else
            __get_root = __x;  // __w == NULL
    }
    else
    {
        __y->__get_parent()->__right_ = __x;
        // __y can't be root if it is a right child
        __w = __y->__parent_->__left_;
    }
    bool __removed_black = __y->__is_black_;
    // If we didn't remove __z, do so now by splicing in __y for __z,
    //    but copy __z's color.  This does not impact __x or __w.
    if (__y != __z)
    {
        // __z->__left_ != nulptr but __z->__right_ might == __x == NULL
        __y->__parent_ = __z->__parent_;
        if (ft::__tree_is_left_child(__z))
            __y->__parent_->__left_ = __y;
        else
            __y->__get_parent()->__right_ = __y;
        __y->__left_ = __z->__left_;
        __y->__left_->__set_parent(__y);
        __y->__right_ = __z->__right_;
        if (__y->__right_ != NULL)
            __y->__right_->__set_parent(__y);
        __y->__is_black_ = __z->__is_black_;
        if (__get_root == __z)
            __get_root = __y;
    }
    // There is no need to rebalance if we removed a red, or if we removed
    //     the last node.
    if (__removed_black && __get_root != NULL)
    {
        // Rebalance:
        // __x has an implicit black color (transferred from the removed __y)
        //    associated with it, no matter what its color is.
        // If __x is __get_root (in which case it can't be null), it is supposed
        //    to be black anyway, and if it is doubly black, then the double
        //    can just be ignored.
        // If __x is red (in which case it can't be null), then it can absorb
        //    the implicit black just by setting its color to black.
        // Since __y was black and only had one child (which __x points to), __x
        //   is either red with no children, else null, otherwise __y would have
        //   different black heights under left and right pointers.
        // if (__x == __get_root || __x != NULL and not __x->__is_black_)
        if (__x != NULL)
            __x->__is_black_ = true;
        else
        {
            //  Else __x isn't root, and is "doubly black", even though it may
            //     be null.  __w can not be null here, else the parent would
            //     see a black height >= 2 on the __x side and a black height
            //     of 1 on the __w side (__w must be a non-null black or a red
            //     with a non-null black child).
            while (true)
            {
                if (not ft::__tree_is_left_child(__w))  // if x is left child
                {
                    if (not __w->__is_black_)
                    {
                        __w->__is_black_ = true;
                        __w->__get_parent()->__is_black_ = false;
                        ft::__tree_left_rotate(__w->__get_parent());
                        // __x is still valid
                        // reset __get_root only if necessary
                        if (__get_root == __w->__left_)
                            __get_root = __w;
                        // reset sibling, and it still can't be null
                        __w = __w->__left_->__right_;
                    }
                    // __w->__is_black_ is now true, __w may have null children
                    if ((__w->__left_  == NULL || __w->__left_->__is_black_) &&
                        (__w->__right_ == NULL || __w->__right_->__is_black_))
                    {
                        __w->__is_black_ = false;
                        __x = __w->__get_parent();
                        // __x can no longer be null
                        if (__x == __get_root || not __x->__is_black_)
                        {
                            __x->__is_black_ = true;
                            break;
                        }
                        // reset sibling, and it still can't be null
                        __w = ft::__tree_is_left_child(__x) ?
                                    __x->__get_parent()->__right_ :
                                    __x->__parent_->__left_;
                        // continue;
                    }
                    else  // __w has a red child
                    {
                        if (__w->__right_ == NULL || __w->__right_->__is_black_)
                        {
                            // __w left child is non-null and red
                            __w->__left_->__is_black_ = true;
                            __w->__is_black_ = false;
                            ft::__tree_right_rotate(__w);
                            // __w is known not to be root, so root hasn't changed
                            // reset sibling, and it still can't be null
                            __w = __w->__get_parent();
                        }
                        // __w has a right red child, left child may be null
                        __w->__is_black_ = __w->__get_parent()->__is_black_;
                        __w->__get_parent()->__is_black_ = true;
                        __w->__right_->__is_black_ = true;
                        ft::__tree_left_rotate(__w->__get_parent());
                        break;
                    }
                }
                else
                {
                    if (not __w->__is_black_)
                    {
                        __w->__is_black_ = true;
                        __w->__get_parent()->__is_black_ = false;
                        ft::__tree_right_rotate(__w->__get_parent());
                        // __x is still valid
                        // reset __get_root only if necessary
                        if (__get_root == __w->__right_)
                            __get_root = __w;
                        // reset sibling, and it still can't be null
                        __w = __w->__right_->__left_;
                    }
                    // __w->__is_black_ is now true, __w may have null children
                    if ((__w->__left_  == NULL || __w->__left_->__is_black_) &&
                        (__w->__right_ == NULL || __w->__right_->__is_black_))
                    {
                        __w->__is_black_ = false;
                        __x = __w->__get_parent();
                        // __x can no longer be null
                        if (not __x->__is_black_ || __x == __get_root)
                        {
                            __x->__is_black_ = true;
                            break;
                        }
                        // reset sibling, and it still can't be null
                        __w = ft::__tree_is_left_child(__x) ?
                                    __x->__get_parent()->__right_ :
                                    __x->__parent_->__left_;
                        // continue;
                    }
                    else  // __w has a red child
                    {
                        if (__w->__left_ == NULL || __w->__left_->__is_black_)
                        {
                            // __w right child is non-null and red
                            __w->__right_->__is_black_ = true;
                            __w->__is_black_ = false;
                            ft::__tree_left_rotate(__w);
                            // __w is known not to be root, so root hasn't changed
                            // reset sibling, and it still can't be null
                            __w = __w->__get_parent();
                        }
                        // __w has a left red child, right child may be null
                        __w->__is_black_ = __w->__get_parent()->__is_black_;
                        __w->__get_parent()->__is_black_ = true;
                        __w->__left_->__is_black_ = true;
                        ft::__tree_right_rotate(__w->__get_parent());
                        break;
                    }
                }
            }
        }
    }
}

} // namespace ft


#endif // __tree_remove_HPP
