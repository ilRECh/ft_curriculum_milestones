#ifndef __TREE_NODE_TYPES_HPP
#define __TREE_NODE_TYPES_HPP


namespace ft {

template <class _NodePtr, class _NodeT = typename std::pointer_traits<_NodePtr>::element_type>
struct __tree_node_types;

template <class _NodePtr, class _Tp, class _VoidPtr>
struct __tree_node_types<_NodePtr, __tree_node<_Tp, _VoidPtr> >
    : public __tree_node_base_types<_VoidPtr>,
             __tree_key_value_types<_Tp>,
             __tree_map_pointer_types<_Tp, _VoidPtr>
{
  typedef __tree_node_base_types<_VoidPtr> __base;
  typedef __tree_key_value_types<_Tp>      __key_base;
  typedef __tree_map_pointer_types<_Tp, _VoidPtr> __map_pointer_base;
public:

  typedef typename pointer_traits<_NodePtr>::element_type       __node_type;
  typedef _NodePtr                                              __node_pointer;

  typedef _Tp                                                 __node_value_type;
  typedef typename __rebind_pointer<_VoidPtr, __node_value_type>::type
                                                      __node_value_type_pointer;
  typedef typename __rebind_pointer<_VoidPtr, const __node_value_type>::type
                                                __const_node_value_type_pointer;
#if defined(_LIBCPP_ABI_TREE_REMOVE_NODE_POINTER_UB)
  typedef typename __base::__end_node_pointer __iter_pointer;
#else
  typedef typename ft::conditional<
      is_pointer<__node_pointer>::value,
        typename __base::__end_node_pointer,
        __node_pointer>::type __iter_pointer;
#endif
private:
    static_assert(not is_const<__node_type>::value,
                "_NodePtr should never be a pointer to const");
    static_assert((is_same<typename __rebind_pointer<_VoidPtr, __node_type>::type,
                          _NodePtr>::value), "_VoidPtr does not rebind to _NodePtr.");
};

} // namespace ft


#endif //__TREE_NODE_TYPES_HPP
