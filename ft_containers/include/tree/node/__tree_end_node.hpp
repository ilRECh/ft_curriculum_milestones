#ifndef __TREE_END_NODE_HPP
#define __TREE_END_NODE_HPP

namespace ft {
    
template <class _Pointer>
class __tree_end_node
{
public:
    typedef _Pointer pointer;
    
    pointer __left_;
    
    __tree_end_node() throw() : __left_() {}
};

} // namespace ft


#endif //__TREE_END_NODE_HPP
