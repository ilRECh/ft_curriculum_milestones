#ifndef __find_leaf_HPP
#define __find_leaf_HPP

namespace ft {

// Find leaf place to insert closest to __hint
// First check prior to __hint.
// Next check after __hint.
// Next do O(log N) search.
// Set __parent to parent of null leaf
// Return reference to null leaf
template <class _Tp, class _Compare, class _Allocator>
typename __tree<_Tp, _Compare, _Allocator>::__node_base_pointer&
__tree<_Tp, _Compare, _Allocator>::__find_leaf(const_iterator __hint,
                                               __parent_pointer& __parent,
                                               const key_type& __v)
{
    if (__hint == end() || not value_comp()(*__hint, __v))  // check before
    {
        // __v <= *__hint
        const_iterator __prior = __hint;
        if (__prior == begin() || not value_comp()(__v, *--__prior))
        {
            // *prev(__hint) <= __v <= *__hint
            if (__hint.__ptr_->__left_ == NULL)
            {
                __parent = static_cast<__parent_pointer>(__hint.__ptr_);
                return __parent->__left_;
            }
            else
            {
                __parent = static_cast<__parent_pointer>(__prior.__ptr_);
                return static_cast<__node_base_pointer>(__prior.__ptr_)->__right_;
            }
        }
        // __v < *prev(__hint)
        return __find_leaf_high(__parent, __v);
    }
    // else __v > *__hint
    return __find_leaf_low(__parent, __v);
}

} // namespace ft


#endif // __find_leaf_HPP
