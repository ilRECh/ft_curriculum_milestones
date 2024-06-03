#ifndef __TREE_SWAP_HPP
#define __TREE_SWAP_HPP

namespace ft {

template <class _Tp, class _Compare, class _Allocator>
inline void swap(
	__tree<_Tp, _Compare, _Allocator>& __x,
    __tree<_Tp, _Compare, _Allocator>& __y)
{
    __x.swap(__y);
}

} // namespace ft


#endif //__TREE_SWAP_HPP
