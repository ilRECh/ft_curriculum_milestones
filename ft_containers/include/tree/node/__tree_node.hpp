#ifndef __TREE_NODE_HPP
#define __TREE_NODE_HPP

#include "__tree_node_base.hpp"

namespace ft {

template <class _Tp, class _VoidPtr>
class __tree_node : public __tree_node_base<_VoidPtr>
{
public:
    typedef _Tp __node_value_type;

    __node_value_type __value_;

private:
  ~__tree_node();
  __tree_node(__tree_node const&);
  __tree_node& operator=(__tree_node const&);
};

} // namespace ft


#endif //__TREE_NODE_HPP
