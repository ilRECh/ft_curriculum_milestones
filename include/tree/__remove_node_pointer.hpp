#ifndef __remove_node_pointer_HPP
#define __remove_node_pointer_HPP

namespace ft {

template <class _Tp, class _Compare, class _Allocator>
typename __tree<_Tp, _Compare, _Allocator>::iterator
__tree<_Tp, _Compare, _Allocator>::__remove_node_pointer(__node_pointer __ptr) throw()
{
    iterator __r(__ptr);
    ++__r;
    if (__begin_node() == __ptr)
        __begin_node() = __r.__ptr_;
    --size();
    __tree_remove(__end_node()->__left_,
                  static_cast<__node_base_pointer>(__ptr));
    return __r;
}


} // namespace ft


#endif // __remove_node_pointer_HPP
