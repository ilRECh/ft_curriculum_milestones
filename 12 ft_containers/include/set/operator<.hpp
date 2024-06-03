#ifndef SET_OPERATOR_LT_HPP
#define SET_OPERATOR_LT_HPP

namespace ft {

template <class _Key, class _Compare, class _Allocator>
inline bool operator< (
    const ft::set<_Key, _Compare, _Allocator>& __x,
    const ft::set<_Key, _Compare, _Allocator>& __y)
{
    return ft::lexicographical_compare(__x.begin(), __x.end(), __y.begin(), __y.end());
}

} // namespace ft


#endif // SET_OPERATOR_LT_HPP
