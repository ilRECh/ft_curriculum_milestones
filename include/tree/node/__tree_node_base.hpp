#ifndef __TREE_NODE_BASE_HPP
#define __TREE_NODE_BASE_HPP

#include "__tree_node_types.hpp"

namespace ft {

template <class _VoidPtr>
class __tree_node_base
    : public __tree_node_base_types<_VoidPtr>::__end_node_type
{
    typedef __tree_node_base_types<_VoidPtr> _NodeBaseTypes;

public:
    typedef typename _NodeBaseTypes::__node_base_pointer pointer;
    typedef typename _NodeBaseTypes::__parent_pointer __parent_pointer;

    pointer          __right_;
    __parent_pointer __parent_;
    bool             __is_black_;
    
    pointer __get_parent() const
    {
        return static_cast<pointer>(__parent_);
    }

    void __set_parent(pointer __p) {
        __parent_ = static_cast<__parent_pointer>(__p);
    }

private:
  ~__tree_node_base() _LIBCPP_EQUAL_DELETE;
  __tree_node_base(__tree_node_base const&) _LIBCPP_EQUAL_DELETE;
  __tree_node_base& operator=(__tree_node_base const&) _LIBCPP_EQUAL_DELETE;
};

} // namespace ft


#endif //__TREE_NODE_BASE_HPP
