#ifndef erase_HPP
#define erase_HPP

namespace ft {

template <class _Tp, class _Compare, class _Allocator>
typename __tree<_Tp, _Compare, _Allocator>::iterator
__tree<_Tp, _Compare, _Allocator>::erase(const_iterator __p)
{
    __node_pointer __np = __p.__get_np();
    iterator __r = __remove_node_pointer(__np);
    __node_allocator& __na = __node_alloc();
    __node_traits::destroy(__na, _NodeTypes::__get_ptr(
        const_cast<__node_value_type&>(*__p)));
    __node_traits::deallocate(__na, __np, 1);
    return __r;
}

template <class _Tp, class _Compare, class _Allocator>
typename __tree<_Tp, _Compare, _Allocator>::iterator
__tree<_Tp, _Compare, _Allocator>::erase(const_iterator __f, const_iterator __l)
{
    while (__f != __l)
        __f = erase(__f);
    return iterator(__l.__ptr_);
}

} // namespace ft


#endif // erase_HPP
