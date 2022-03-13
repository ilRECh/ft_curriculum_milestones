#ifndef __TREE_KEY_VALUE_TYPES_HPP
#define __TREE_KEY_VALUE_TYPES_HPP

#include "../../__value_type.hpp"

namespace ft {

template <class _Tp>
struct __tree_key_value_types {

	typedef _Tp key_type;
	typedef _Tp __node_value_type;
	typedef _Tp __container_value_type;

	static const bool __is_map = false;
	
	static key_type const& __get_key(_Tp const& __v)
    {
	    return __v;
	}
	
	static __container_value_type const& __get_value(__node_value_type const& __v)
    {
	    return __v;
	}
	
	static __container_value_type* __get_ptr(__node_value_type& __n)
    {
	    return &__n;
	}
};

template <class _Key, class _Tp>
struct __tree_key_value_types<ft::__value_type<_Key, _Tp> >
{

    typedef _Key                      key_type;
    typedef _Tp                       mapped_type;
    typedef __value_type<_Key, _Tp>   __node_value_type;
    typedef ft::pair<const _Key, _Tp> __container_value_type;
    typedef __container_value_type    __map_value_type;

    static const bool __is_map = true;

    static key_type const& __get_key(__node_value_type const& __t)
    {
        return __t.__get_value().first;
    }

    template <class _Up>
    static typename ft::enable_if
    <

        std::is_same
        <
            typename ft::remove_cv<typename std::remove_reference<_Up>::type>::type,
            typename ft::remove_cv<typename std::remove_reference<__container_value_type>::type>::type
        >::value, 
        key_type const&
    >::type __get_key(_Up& __t)
    {
        return __t.first;
    }
    
    static __container_value_type const& __get_value(__node_value_type const& __t)
    {
        return __t.__get_value();
    }

    template <class _Up>
    static typename ft::enable_if
    <
        std::is_same
        <
            typename ft::remove_cv<typename std::remove_reference<_Up>::type>::type,
            typename ft::remove_cv<typename std::remove_reference<__container_value_type>::type>::type
        >::value,
        __container_value_type const&
    >::type __get_value(_Up& __t)
    {
        return __t;
    }

    static __container_value_type* __get_ptr(__node_value_type& __n)
    {
        return &__n.__get_value();
    }
};

} // namespace ft


#endif //__TREE_KEY_VALUE_TYPES_HPP
