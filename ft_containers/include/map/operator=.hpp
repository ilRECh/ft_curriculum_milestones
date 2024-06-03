#ifndef MAP_OPERATOR_ASSIGN_HPP
#define MAP_OPERATOR_ASSIGN_HPP

#include "../../map.hpp"

namespace ft {

template <class _Key, class _Tp, class _Compare, class _Allocator>
map<_Key, _Tp, _Compare, _Allocator>& map<_Key, _Tp, _Compare, _Allocator>::operator=(const map<_Key, _Tp, _Compare, _Allocator>& __m)
{
	if (this != &__m) {
		__tree_.clear();
		__tree_.value_comp() = __m.__tree_.value_comp();
		__tree_.__copy_assign_alloc(__m.__tree_);
		insert(__m.begin(), __m.end());
	}
	return *this;
}

} // namespace ft

#endif // MAP_OPERATOR_ASSIGN_HPP
