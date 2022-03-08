#ifndef __find_leaf_low_HPP
#define __find_leaf_low_HPP

namespace ft {

// Find lower_bound place to insert
// Set __parent to parent of null leaf
// Return reference to null leaf
template <class _Tp, class _Compare, class _Allocator>
typename __tree<_Tp, _Compare, _Allocator>::__node_base_pointer&
__tree<_Tp, _Compare, _Allocator>::__find_leaf_low(__parent_pointer& __parent,
                                                   const key_type& __v)
{
    __node_pointer __nd = __get_root();
    if (__nd != NULL)
    {
        while (true)
        {
            if (value_comp()(__nd->__value_, __v))
            {
                if (__nd->__right_ != NULL)
                    __nd = static_cast<__node_pointer>(__nd->__right_);
                else
                {
                    __parent = static_cast<__parent_pointer>(__nd);
                    return __nd->__right_;
                }
            }
            else
            {
                if (__nd->__left_ != NULL)
                    __nd = static_cast<__node_pointer>(__nd->__left_);
                else
                {
                    __parent = static_cast<__parent_pointer>(__nd);
                    return __parent->__left_;
                }
            }
        }
    }
    __parent = static_cast<__parent_pointer>(__end_node());
    return __parent->__left_;
}

}

#endif // __find_leaf_low_HPP
