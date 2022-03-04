#ifndef MAP_OPERATOR_GT_EQ_HPP
#define MAP_OPERATOR_GT_EQ_HPP

#include "../../map.hpp"

namespace ft {

template <class _Key, class _Tp, class _Compare, class _Allocator>
inline bool operator>=(
	const map<_Key, _Tp, _Compare, _Allocator>& __x,
    const map<_Key, _Tp, _Compare, _Allocator>& __y)
{
    return !(__x < __y);
}

} // namespace ft

#endif // MAP_OPERATOR_GT_EQ_HPP
