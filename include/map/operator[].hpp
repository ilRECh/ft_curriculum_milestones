#ifndef MAP_OPERATOR_SQUAREBRACES_HPP //operator[]
#define MAP_OPERATOR_SQUAREBRACES_HPP //operator[]

#include "../../map.hpp"

namespace ft {

template <class _Key, class _Tp, class _Compare, class _Allocator>
_Tp& map<_Key, _Tp, _Compare, _Allocator>::operator[](const key_type& __k)
{
    __parent_pointer __parent;
    __node_base_pointer& __child = __tree_.__find_equal(__parent, __k);
    __node_pointer __r = static_cast<__node_pointer>(__child);
    if (__child == NULL)
    {
        __node_holder __h = __construct_node_with_key(__k);
        __tree_.__insert_node_at(__parent, __child, static_cast<__node_base_pointer>(__h.get()));
        __r = __h.release();
    }
    return __r->__value_.__get_value().second;
}

} // namespace ft


#endif //MAP_OPERATOR[]_HPP
