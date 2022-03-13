#ifndef __tree_balance_after_insert_HPP
#define __tree_balance_after_insert_HPP

namespace ft {

// Effects:  Rebalances __get_root after attaching __x to a leaf.
// Precondition:  __get_root != nulptr && __x != NULL.
//                __x has no children.
//                __x == __get_root or == a direct or indirect child of __get_root.
//                If __x were to be unlinked from __get_root (setting __get_root to
//                  NULL if __get_root == __x), __tree_invariant(__get_root) == true.
// Postcondition: __tree_invariant(end_node->__left_) == true.  end_node->__left_
//                may be different than the value passed in as __get_root.
template <class _NodePtr>
void __tree_balance_after_insert(_NodePtr __get_root, _NodePtr __x) throw()
{
    __x->__is_black_ = __x == __get_root;
    while (__x != __get_root and not __x->__get_parent()->__is_black_)
    {
        // __x->__parent_ != __get_root because __x->__parent_->__is_black == false
        if (ft::__tree_is_left_child(__x->__get_parent()))
        {
            _NodePtr __y = __x->__get_parent()->__get_parent()->__right_;
            if (__y != NULL and not __y->__is_black_)
            {
                __x = __x->__get_parent();
                __x->__is_black_ = true;
                __x = __x->__get_parent();
                __x->__is_black_ = __x == __get_root;
                __y->__is_black_ = true;
            }
            else
            {
                if (not ft::__tree_is_left_child(__x))
                {
                    __x = __x->__get_parent();
                    ft::__tree_left_rotate(__x);
                }
                __x = __x->__get_parent();
                __x->__is_black_ = true;
                __x = __x->__get_parent();
                __x->__is_black_ = false;
                ft::__tree_right_rotate(__x);
                break;
            }
        }
        else
        {
            _NodePtr __y = __x->__get_parent()->__parent_->__left_;
            if (__y != NULL and not __y->__is_black_)
            {
                __x = __x->__get_parent();
                __x->__is_black_ = true;
                __x = __x->__get_parent();
                __x->__is_black_ = __x == __get_root;
                __y->__is_black_ = true;
            }
            else
            {
                if (ft::__tree_is_left_child(__x))
                {
                    __x = __x->__get_parent();
                    ft::__tree_right_rotate(__x);
                }
                __x = __x->__get_parent();
                __x->__is_black_ = true;
                __x = __x->__get_parent();
                __x->__is_black_ = false;
                ft::__tree_left_rotate(__x);
                break;
            }
        }
    }
}

} // namespace ft


#endif // __tree_balance_after_insert_HPP
