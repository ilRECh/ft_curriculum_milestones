#ifndef __find_equal_HPP
#define __find_equal_HPP

namespace ft {

// Find place to insert if __v doesn't exist
// First check prior to __hint.
// Next check after __hint.
// Next do O(log N) search.
// Set __parent to parent of null leaf
// Return reference to null leaf
// If __v exists, set parent to node of __v and return reference to node of __v
template <class _Tp, class _Compare, class _Allocator>
template <class _Key>
typename __tree<_Tp, _Compare, _Allocator>::__node_base_pointer&
__tree<_Tp, _Compare, _Allocator>::__find_equal(const_iterator __hint,
                                                __parent_pointer& __parent,
                                                __node_base_pointer& __dummy,
                                                const _Key& __v)
{
    if (__hint == end() || value_comp()(__v, *__hint))  // check before
    {
        // __v < *__hint
        const_iterator __prior = __hint;
        if (__prior == begin() || value_comp()(*--__prior, __v))
        {
            // *prev(__hint) < __v < *__hint
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
        // __v <= *prev(__hint)
        return __find_equal(__parent, __v);
    }
    else if (value_comp()(*__hint, __v))  // check after
    {
        // *__hint < __v
        const_iterator __next = ++__hint;
        if (__next == end() || value_comp()(__v, *__next))
        {
            // *__hint < __v < *_VSTD::next(__hint)
            if (__hint.__get_np()->__right_ == NULL)
            {
                __parent = static_cast<__parent_pointer>(__hint.__ptr_);
                return static_cast<__node_base_pointer>(__hint.__ptr_)->__right_;
            }
            else
            {
                __parent = static_cast<__parent_pointer>(__next.__ptr_);
                return __parent->__left_;
            }
        }
        // *next(__hint) <= __v
        return __find_equal(__parent, __v);
    }
    // else __v == *__hint
    __parent = static_cast<__parent_pointer>(__hint.__ptr_);
    __dummy = static_cast<__node_base_pointer>(__hint.__ptr_);
    return __dummy;
}

// Find place to insert if __v doesn't exist
// Set __parent to parent of null leaf
// Return reference to null leaf
// If __v exists, set parent to node of __v and return reference to node of __v
template <class _Tp, class _Compare, class _Allocator>
template <class _Key>
typename __tree<_Tp, _Compare, _Allocator>::__node_base_pointer&
__tree<_Tp, _Compare, _Allocator>::__find_equal(__parent_pointer& __parent,
                                                const _Key& __v)
{
    __node_pointer __nd = __get_root();
    __node_base_pointer* __nd_ptr = __root_ptr();
    if (__nd != NULL)
    {
        while (true)
        {
            if (value_comp()(__v, __nd->__value_))
            {
                if (__nd->__left_ != NULL) {
                    __nd_ptr = &__nd->__left_;
                    __nd = static_cast<__node_pointer>(__nd->__left_);
                } else {
                    __parent = static_cast<__parent_pointer>(__nd);
                    return __parent->__left_;
                }
            }
            else if (value_comp()(__nd->__value_, __v))
            {
                if (__nd->__right_ != NULL) {
                    __nd_ptr = &__nd->__right_;
                    __nd = static_cast<__node_pointer>(__nd->__right_);
                } else {
                    __parent = static_cast<__parent_pointer>(__nd);
                    return __nd->__right_;
                }
            }
            else
            {
                __parent = static_cast<__parent_pointer>(__nd);
                return *__nd_ptr;
            }
        }
    }
    __parent = static_cast<__parent_pointer>(__end_node());
    return __parent->__left_;
}

} // namespace ft


#endif // __find_equal_HPP
