#ifndef __TREE_NODE_DESTRUCTOR_HPP
#define __TREE_NODE_DESTRUCTOR_HPP

namespace ft {

template <class _Allocator>
class __tree_node_destructor
{
    typedef _Allocator                                      allocator_type;
    typedef std::allocator_traits<allocator_type>           __alloc_traits;

public:
    typedef typename __alloc_traits::pointer                pointer;

private:
    typedef ft::__tree_node_types<pointer> _NodeTypes;
    allocator_type& __na_;

    __tree_node_destructor& operator=(const __tree_node_destructor&);

public:
    bool __value_constructed;
    
    explicit __tree_node_destructor(allocator_type& __na, bool __val = false) throw()
        : __na_(__na),
          __value_constructed(__val)
        {}

    
    void operator()(pointer __p) throw()
    {
        if (__value_constructed) {
            __alloc_traits::destroy(__na_, _NodeTypes::__get_ptr(__p->__value_));
        }
        if (__p) {
            __alloc_traits::deallocate(__na_, __p, 1);
        }
    }

    template <class> friend class __map_node_destructor;
};

} // namespace ft


#endif // __TREE_NODE_DESTRUCTOR_HPP
