#ifndef MAP_SWAP_HPP
#define MAP_SWAP_HPP

#include "../../map.hpp"

namespace ft {

template <class _Key, class _Tp, class _Compare, class _Allocator>
inline void swap(
	map<_Key, _Tp, _Compare, _Allocator>& __x,
	map<_Key, _Tp, _Compare, _Allocator>& __y)
{
	__x.swap(__y);
}

} // namespace ft

#endif // MAP_SWAP_HPP
