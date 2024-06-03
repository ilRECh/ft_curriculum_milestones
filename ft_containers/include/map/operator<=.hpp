#ifndef MAP_OPERATOR_LT_EQ_HPP
#define MAP_OPERATOR_LT_EQ_HPP

#include "../../map.hpp"

namespace ft {

template <class _Key, class _Tp, class _Compare, class _Allocator>
inline bool operator<=(
	const map<_Key, _Tp, _Compare, _Allocator>& __x,
    const map<_Key, _Tp, _Compare, _Allocator>& __y)
{
    return not (__y < __x);
}

} // namespace ft

#endif // MAP_OPERATOR_LT_EQ_HPP
