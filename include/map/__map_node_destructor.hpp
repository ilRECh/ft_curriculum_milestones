#ifndef __MAP_NODE_DESTRUCTOR_HPP
#define __MAP_NODE_DESTRUCTOR_HPP

namespace ft {

template <class _Allocator>
class __map_node_destructor
{
    typedef _Allocator allocator_type;
    typedef std::allocator_traits<allocator_type> __alloc_traits;

public:
    typedef typename __alloc_traits::pointer pointer;

private:
    allocator_type& __na_;

    __map_node_destructor& operator=(const __map_node_destructor&);

public:
    bool __first_constructed;
    bool __second_constructed;

    explicit __map_node_destructor(allocator_type& __na) throw()
        : __na_(__na),
          __first_constructed(false),
          __second_constructed(false)
        {}

    void operator()(pointer __p) throw()
    {
        if (__second_constructed)
		{
            __alloc_traits::destroy(__na_, &__p->__value_.__get_value().second);
		}
        if (__first_constructed)
		{
            __alloc_traits::destroy(__na_, &__p->__value_.__get_value().first);
		}
        if (__p)
		{
            __alloc_traits::deallocate(__na_, __p, 1);
		}
    }
};

} // namespace ft


#endif //__MAP_NODE_DESTRUCTOR_HPP
