#ifndef UTILITY_HPP
#define UTILITY_HPP

#include "type_traits.hpp"
#include "iterator_traits.hpp"

namespace ft {

template <class _Tp, typename _Tp2 = _Tp>
struct less
{
    bool operator()(const _Tp& __x, const _Tp2& __y) const
    {
		return __x < __y;
	}
};

struct __two {char __lx[2];};

struct __is_referenceable_impl
{
    template <class _Tp> static _Tp& __test(int);
    template <class _Tp> static __two __test(...);
};

template <class _Tp>
struct __is_referenceable : ft::integral_constant<bool,
    not std::is_same<decltype(ft::__is_referenceable_impl::__test<_Tp>(0)), __two>::value> {};


template <class _Tp, bool = ft::__is_referenceable<_Tp>::value> struct __add_lvalue_reference_impl
{
	typedef _Tp type;
};

template <class _Tp> struct __add_lvalue_reference_impl<_Tp, true>
{
	typedef _Tp& type;
};

template <class _Tp>
struct add_lvalue_reference
{
	typedef typename ft::__add_lvalue_reference_impl<_Tp>::type type;
};


template <class _Tp>
typename ft::add_lvalue_reference<_Tp>::type
declval();

template <class _Compare, class _InputIterator1, class _InputIterator2>
bool __lexicographical_compare(_InputIterator1 __first1, _InputIterator1 __last1,
                          _InputIterator2 __first2, _InputIterator2 __last2, _Compare __comp)
{
    for (; __first2 != __last2; ++__first1, (void) ++__first2)
    {
        if (__first1 == __last1 || __comp(*__first1, *__first2))
            return true;
        if (__comp(*__first2, *__first1))
            return false;
    }
    return false;
}

template <class _InputIterator1, class _InputIterator2, class _Compare>
inline
bool
lexicographical_compare(_InputIterator1 __first1, _InputIterator1 __last1,
                        _InputIterator2 __first2, _InputIterator2 __last2, _Compare __comp)
{
    typedef typename ft::add_lvalue_reference<_Compare>::type _Comp_ref;
    return ft::__lexicographical_compare<_Comp_ref>(__first1, __last1, __first2, __last2, __comp);
}

template <class _InputIterator1, class _InputIterator2>
inline bool lexicographical_compare(_InputIterator1 __first1, _InputIterator1 __last1,
                        _InputIterator2 __first2, _InputIterator2 __last2)
{
    return ft::__lexicographical_compare(__first1, __last1, __first2, __last2,
                                         ft::less<typename iterator_traits<_InputIterator1>::value_type,
                                                typename iterator_traits<_InputIterator2>::value_type>());
}

template <class _T1, class _T2 = _T1>
struct __equal_to
{
    bool operator()(const _T1& __x, const _T2& __y) const {return __x == __y;}
};

template <class _InputIterator1, class _InputIterator2, class _BinaryPredicate>
inline bool equal(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2, _BinaryPredicate __pred)
{
    for (; __first1 != __last1; ++__first1, (void) ++__first2)
        if (not __pred(*__first1, *__first2))
            return false;
    return true;
}

template <class _InputIterator1, class _InputIterator2>
inline bool equal(_InputIterator1 __first1, _InputIterator1 __last1, _InputIterator2 __first2)
{
    typedef typename iterator_traits<_InputIterator1>::value_type __v1;
    typedef typename iterator_traits<_InputIterator2>::value_type __v2;
    return ft::equal(__first1, __last1, __first2, ft::__equal_to<__v1, __v2>());
}

template <class _T1, class _T2>
struct pair
{
    _T1 first;
    _T2 second;

    pair() : first(), second() {}

    pair(_T1 const& __t1, _T2 const& __t2) : first(__t1), second(__t2) {}

    template <class _U1, class _U2>
    pair(const pair<_U1, _U2>& __p) : first(__p.first), second(__p.second) {}

    pair& operator=(pair const& __p)
    {
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

template <class _T1, class _T2>
inline bool operator==(const pair<_T1,_T2>& __x, const pair<_T1,_T2>& __y)
{
    return __x.first == __y.first && __x.second == __y.second;
}

template <class _T1, class _T2>
inline bool operator!=(const pair<_T1,_T2>& __x, const pair<_T1,_T2>& __y)
{
    return not (__x == __y);
}

template <class _T1, class _T2>
inline bool operator< (const pair<_T1,_T2>& __x, const pair<_T1,_T2>& __y)
{
    return __x.first < __y.first || (not (__y.first < __x.first) && __x.second < __y.second);
}

template <class _T1, class _T2>
inline bool operator> (const pair<_T1,_T2>& __x, const pair<_T1,_T2>& __y)
{
    return __y < __x;
}

template <class _T1, class _T2>
inline bool operator>=(const pair<_T1,_T2>& __x, const pair<_T1,_T2>& __y)
{
    return not (__x < __y);
}

template <class _T1, class _T2>
inline bool operator<=(const pair<_T1,_T2>& __x, const pair<_T1,_T2>& __y)
{
    return not (__y < __x);
}

template <class _T1, class _T2>
inline typename enable_if
<
    std::__is_swappable<_T1>::value &&
    std::__is_swappable<_T2>::value,
    void
>::type swap(pair<_T1, _T2>& __x, pair<_T1, _T2>& __y)
{
    __x.swap(__y);
}

template <class _T1, class _T2>
inline pair<_T1,_T2> make_pair(_T1 __x, _T2 __y)
{
    return pair<_T1, _T2>(__x, __y);
}

};

#endif //UTILITY_HPP
