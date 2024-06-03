#ifndef __TREE_NODE_BASE_TYPES_HPP
#define __TREE_NODE_BASE_TYPES_HPP

namespace ft {

template <class _VoidPtr>
struct __tree_node_base_types
{
    typedef _VoidPtr __void_pointer;

    typedef __tree_node_base<__void_pointer>                            __node_base_type;
    typedef typename __rebind_pointer<_VoidPtr, __node_base_type>::type __node_base_pointer;

    typedef __tree_end_node<__node_base_pointer>                        __end_node_type;
    typedef typename __rebind_pointer<_VoidPtr, __end_node_type>::type  __end_node_pointer;
    typedef typename ft::conditional
    <
        is_pointer<__end_node_pointer>::value,
        __end_node_pointer,
        __node_base_pointer
    >::type                                                             __parent_pointer;

private:
    static_assert((is_same<typename pointer_traits<_VoidPtr>::element_type, void>::value),
                  "_VoidPtr does not point to unqualified void type");
};

} // namespace ft


#endif //__TREE_NODE_BASE_TYPES_HPP