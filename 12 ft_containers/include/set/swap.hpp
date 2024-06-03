#ifndef SET_swap_HPP
#define SET_swap_HPP

namespace ft {

template <class _Key, class _Compare, class _Allocator>
inline void swap(
    ft::set<_Key, _Compare, _Allocator>& __x,
    ft::set<_Key, _Compare, _Allocator>& __y)
{
    __x.swap(__y);
}

} // namespace ft


#endif // SET_swap_HPP
