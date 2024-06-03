#ifndef vector_iterator_HPP
#define vector_iterator_HPP

#include "../iterator_traits.hpp"

namespace ft {

template <class _Iter>
class veciterator
{
public:
    typedef _Iter                                                          iterator_type;
    typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;
    typedef typename ft::iterator_traits<iterator_type>::value_type        value_type;
    typedef typename ft::iterator_traits<iterator_type>::difference_type   difference_type;
    typedef typename ft::iterator_traits<iterator_type>::pointer           pointer;
    typedef typename ft::iterator_traits<iterator_type>::reference         reference;
private:
    iterator_type __i;
public:
    veciterator() throw()
    {}
    template <class _Up>
        veciterator(const veciterator<_Up>& __u,
            typename enable_if<std::is_convertible<_Up, iterator_type>::value>::type* = 0) throw()
            : __i(__u.base())
    {}

    reference operator*() const throw()
    {
        return *__i;
    }
    pointer  operator->() const throw()
    {
        return (pointer)_VSTD::addressof(*__i);
    }
    veciterator& operator++() throw()
    {
        ++__i;
        return *this;
    }
    veciterator  operator++(int) throw()
    {veciterator __tmp(*this); ++(*this); return __tmp;}

    veciterator& operator--() throw()
    {
        --__i;
        return *this;
    }
    veciterator  operator--(int) throw()
        {veciterator __tmp(*this); --(*this); return __tmp;}
    veciterator  operator+ (difference_type __n) const throw()
        {veciterator __w(*this); __w += __n; return __w;}
    veciterator& operator+=(difference_type __n) throw()
    {
        __i += __n;
        return *this;
    }
    veciterator  operator- (difference_type __n) const throw()
        {return *this + (-__n);}
    veciterator& operator-=(difference_type __n) throw()
        {*this += -__n; return *this;}
    reference    operator[](difference_type __n) const throw()
    {
        return __i[__n];
    }

    iterator_type base() const throw() {return __i;}

private:
    veciterator(iterator_type __x) throw() : __i(__x) {}

    template <class _Up> friend class veciterator;
    template <class _Tp, class _Alloc> friend class vector;

    template <class _Iter1, class _Iter2>
    friend
    bool
    operator==(const veciterator<_Iter1>&, const veciterator<_Iter2>&) throw();

    template <class _Iter1, class _Iter2>
    friend
    bool
    operator<(const veciterator<_Iter1>&, const veciterator<_Iter2>&) throw();

    template <class _Iter1, class _Iter2>
    friend
    bool
    operator!=(const veciterator<_Iter1>&, const veciterator<_Iter2>&) throw();

    template <class _Iter1, class _Iter2>
    friend
    bool
    operator>(const veciterator<_Iter1>&, const veciterator<_Iter2>&) throw();

    template <class _Iter1, class _Iter2>
    friend
    bool
    operator>=(const veciterator<_Iter1>&, const veciterator<_Iter2>&) throw();

    template <class _Iter1, class _Iter2>
    friend
    bool
    operator<=(const veciterator<_Iter1>&, const veciterator<_Iter2>&) throw();


    template <class _Iter1, class _Iter2>
    friend
    typename veciterator<_Iter1>::difference_type
    operator-(const veciterator<_Iter1>&, const veciterator<_Iter2>&) throw();

    template <class _Iter1>
    friend
    veciterator<_Iter1>
    operator+(typename veciterator<_Iter1>::difference_type, veciterator<_Iter1>) throw();

    // template <class _Tp>
    // friend
    // typename ft::enable_if
    // <
    //     std::is_trivially_copy_assignable<_Tp>::value,
    //     _Tp*
    // >::type
    // __unwrap_iter(veciterator<_Tp*>);
};

template <class _Iter1, class _Iter2>
inline
bool
operator==(const veciterator<_Iter1>& __x, const veciterator<_Iter2>& __y) throw()
{
    return __x.base() == __y.base();
}

template <class _Iter1, class _Iter2>
inline  
bool
operator<(const veciterator<_Iter1>& __x, const veciterator<_Iter2>& __y) throw()
{
    return __x.base() < __y.base();
}

template <class _Iter1, class _Iter2>
inline  
bool
operator!=(const veciterator<_Iter1>& __x, const veciterator<_Iter2>& __y) throw()
{
    return !(__x == __y);
}

template <class _Iter1, class _Iter2>
inline  
bool
operator>(const veciterator<_Iter1>& __x, const veciterator<_Iter2>& __y) throw()
{
    return __y < __x;
}

template <class _Iter1, class _Iter2>
inline  
bool
operator>=(const veciterator<_Iter1>& __x, const veciterator<_Iter2>& __y) throw()
{
    return !(__x < __y);
}

template <class _Iter1, class _Iter2>
inline  
bool
operator<=(const veciterator<_Iter1>& __x, const veciterator<_Iter2>& __y) throw()
{
    return !(__y < __x);
}

template <class _Iter1>
inline  
bool
operator!=(const veciterator<_Iter1>& __x, const veciterator<_Iter1>& __y) throw()
{
    return !(__x == __y);
}

template <class _Iter1>
inline  
bool
operator>(const veciterator<_Iter1>& __x, const veciterator<_Iter1>& __y) throw()
{
    return __y < __x;
}

template <class _Iter1>
inline  
bool
operator>=(const veciterator<_Iter1>& __x, const veciterator<_Iter1>& __y) throw()
{
    return !(__x < __y);
}

template <class _Iter1>
inline  
bool
operator<=(const veciterator<_Iter1>& __x, const veciterator<_Iter1>& __y) throw()
{
    return !(__y < __x);
}



template <class _Iter1, class _Iter2>
inline  
typename veciterator<_Iter1>::difference_type
operator-(const veciterator<_Iter1>& __x, const veciterator<_Iter2>& __y) throw()
{
    return __x.base() - __y.base();
}

template <class _Iter>
inline  
veciterator<_Iter>
operator+(typename veciterator<_Iter>::difference_type __n,
          veciterator<_Iter> __x) throw()
{
    __x += __n;
    return __x;
}

} // namespace ft


#endif // vector_iterator_HPP
