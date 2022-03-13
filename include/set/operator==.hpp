#ifndef SET_OPERATOR_EQ_EQ_HPP
#define SET_OPERATOR_EQ_EQ_HPP

#include "../../set.hpp"

namespace ft {

template <class _Key, class _Compare, class _Allocator>
inline bool operator==(
    const ft::set<_Key, _Compare, _Allocator>& __x,
    const ft::set<_Key, _Compare, _Allocator>& __y)
{
    return __x.size() == __y.size() && ft::equal(__x.begin(), __x.end(), __y.begin());
}

} // namespace ft


#endif // SET_OPERATOR_EQ_EQ_HPP
