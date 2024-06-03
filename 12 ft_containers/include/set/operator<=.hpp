#ifndef SET_OPERATOR_LT_EQ_HPP
#define SET_OPERATOR_LT_EQ_HPP

namespace ft {

template <class _Key, class _Compare, class _Allocator>
inline bool operator<=(
    const ft::set<_Key, _Compare, _Allocator>& __x,
    const ft::set<_Key, _Compare, _Allocator>& __y)
{
    return !(__y < __x);
}

} // namespace ft


#endif // SET_OPERATOR_LT_EQ_HPP
