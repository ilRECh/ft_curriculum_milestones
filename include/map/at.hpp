#ifndef MAP_AT_HPP
#define MAP_AT_HPP

#include "../../map.hpp"

namespace ft {

template <class _Key, class _Tp, class _Compare, class _Allocator>
_Tp& map<_Key, _Tp, _Compare, _Allocator>::at(const key_type& __k)
{
    __parent_pointer __parent;
    __node_base_pointer& __child = __tree_.__find_equal(__parent, __k);
    if (__child == NULL)
        std::out_of_range("map::at:  key not found");
    return static_cast<__node_pointer>(__child)->__value_.__get_value().second;
}

template <class _Key, class _Tp, class _Compare, class _Allocator>
const _Tp& map<_Key, _Tp, _Compare, _Allocator>::at(const key_type& __k) const
{
    __parent_pointer __parent;
    __node_base_pointer __child = __tree_.__find_equal(__parent, __k);
    if (__child == NULL)
        throw std::out_of_range("map::at:  key not found");
    return static_cast<__node_pointer>(__child)->__value_.__get_value().second;
}

} // namespace ft

#endif //MAP_AT_HPP
