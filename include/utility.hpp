#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <__config>
#include <__tuple>
#include "type_traits.hpp"
#include <cstddef>
#include <cstring>
#include <cstdint>
#include <__cxx_version>
#include <__debug>

namespace ft {

template <class _Arg1, class _Arg2, class _Result>
struct binary_function
{
    typedef _Arg1   first_argument_type;
    typedef _Arg2   second_argument_type;
    typedef _Result result_type;
};

template <class _Tp>
struct less : binary_function<_Tp, _Tp, bool>
{
    bool operator()(const _Tp& __x, const _Tp& __y) const
        {return __x < __y;}
};

template <class _T1, class _T2>
struct pair
{
    _T1 first;
    _T2 second;

    pair() : first(), second() {}

    pair(_T1 const& __t1, _T2 const& __t2) : first(__t1), second(__t2) {}

    template <class _U1, class _U2>
    pair(const pair<_U1, _U2>& __p) : first(__p.first), second(__p.second) {}

    pair& operator=(pair const& __p) {
        first = __p.first;
        second = __p.second;
        return *this;
    }

    void swap(pair& __p)
    {
        _T1 first_tmp = first;
		first = __p.first;
		__p.first = first_tmp;
		_T2 second_tmp = second;
		second = __p.second;
		__p.second = second_tmp;
    }
};

};

#endif //UTILITY_HPP
