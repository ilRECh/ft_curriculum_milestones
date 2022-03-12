#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "include/iterator_traits.hpp"
#include "include/utility.hpp"
#include "include/type_traits.hpp"
#include "include/reverse_iterator.hpp"


namespace ft {
 
template <class _Tp, class _Allocator>
class __vector_base
{
public:
    typedef _Allocator                               allocator_type;
    typedef std::allocator_traits<allocator_type>    __alloc_traits;
    typedef typename __alloc_traits::size_type       size_type;
protected:
    typedef _Tp                                      value_type;
    typedef value_type&                              reference;
    typedef const value_type&                        const_reference;
    typedef typename __alloc_traits::difference_type difference_type;
    typedef typename __alloc_traits::pointer         pointer;
    typedef typename __alloc_traits::const_pointer   const_pointer;
    typedef pointer                                  iterator;
    typedef const_pointer                            const_iterator;

    pointer                                         __begin_;
    pointer                                         __end_;
    std::__compressed_pair<pointer, allocator_type> __end_cap_;


    allocator_type& __alloc() throw()
    {
        return __end_cap_.second();
    }

    const allocator_type& __alloc() const throw()
    {
        return __end_cap_.second();
    }

    pointer& __end_cap() throw()
    {
        return __end_cap_.first();
    }

    const pointer& __end_cap() const throw()
    {
        return __end_cap_.first();
    }

    __vector_base();
    
    __vector_base(const allocator_type& __a);

    ~__vector_base();

    void clear() throw()
    {
        __destruct_at_end(__begin_);
    }

    size_type capacity() const throw()
    {
        return static_cast<size_type>(__end_cap() - __begin_);
    }

    void __destruct_at_end(pointer __new_last) throw();

    void __copy_assign_alloc(const __vector_base& __c)
    {
        __copy_assign_alloc(__c, integral_constant<bool,
                      __alloc_traits::propagate_on_container_copy_assignment::value>());
    }

    void __move_assign_alloc(__vector_base& __c)
    {
        __move_assign_alloc(__c, integral_constant<bool,
                      __alloc_traits::propagate_on_container_move_assignment::value>());
    }

private:

    void __copy_assign_alloc(const __vector_base& __c, true_type)
    {
        if (__alloc() != __c.__alloc())
        {
            clear();
            __alloc_traits::deallocate(__alloc(), __begin_, capacity());
            __begin_ = __end_ = __end_cap() = NULL;
        }
        __alloc() = __c.__alloc();
    }


    void __copy_assign_alloc(const __vector_base&, false_type)
    {}


    void __move_assign_alloc(__vector_base& __c, true_type)
    {
        __alloc() = _VSTD::move(__c.__alloc());
    }


    void __move_assign_alloc(__vector_base&, false_type) throw() 
    {}
};

template <class _Tp, class _Allocator>
inline void __vector_base<_Tp, _Allocator>::__destruct_at_end(pointer __new_last) throw()
{
    pointer __soon_to_be_end = __end_;
    while (__new_last != __soon_to_be_end)
        __alloc_traits::destroy(__alloc(), _VSTD::__to_raw_pointer(--__soon_to_be_end));
    __end_ = __new_last;
}

template <class _Tp, class _Allocator>
inline __vector_base<_Tp, _Allocator>::__vector_base()
    : __begin_(NULL),
      __end_(NULL),
      __end_cap_(NULL)
{
}

template <class _Tp, class _Allocator>
inline __vector_base<_Tp, _Allocator>::__vector_base(const allocator_type& __a)
    : __begin_(NULL),
      __end_(NULL),
      __end_cap_(NULL, __a)
{
}

template <class _Tp, class _Allocator>
__vector_base<_Tp, _Allocator>::~__vector_base()
{
    if (__begin_ != NULL)
    {
        clear();
        __alloc_traits::deallocate(__alloc(), __begin_, capacity());
    }
}

template <class _Tp, class _Allocator = std::allocator<_Tp> >
class vector : private __vector_base<_Tp, _Allocator>
{
private:
    typedef __vector_base<_Tp, _Allocator>           __base;
    typedef allocator<_Tp>                           __default_allocator_type;
public:
    typedef vector                                   __self;
    typedef _Tp                                      value_type;
    typedef _Allocator                               allocator_type;
    typedef typename __base::__alloc_traits          __alloc_traits;
    typedef typename __base::reference               reference;
    typedef typename __base::const_reference         const_reference;
    typedef typename __base::size_type               size_type;
    typedef typename __base::difference_type         difference_type;
    typedef typename __base::pointer                 pointer;
    typedef typename __base::const_pointer           const_pointer;
    typedef __wrap_iter<pointer>                     iterator;
    typedef __wrap_iter<const_pointer>               const_iterator;
    typedef ft::reverse_iterator<iterator>         reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>   const_reverse_iterator;

    static_assert((is_same<typename allocator_type::value_type, value_type>::value),
                  "Allocator::value_type must be same type as value_type");

    vector()
    {}
    
    explicit vector(const allocator_type& __a) throw()
        : __base(__a)
    {}

    explicit vector(size_type __n);

    vector(size_type __n, const value_type& __x);

    vector(size_type __n, const value_type& __x, const allocator_type& __a);

    template <class _InputIterator>
    vector(_InputIterator __first,
               typename enable_if<__is_input_iterator  <_InputIterator>::value &&
                                 !__is_forward_iterator<_InputIterator>::value &&
                                 is_constructible<
                                    value_type,
                                    typename ft::iterator_traits<_InputIterator>::reference>::value,
                                 _InputIterator>::type __last);
    template <class _InputIterator>
    vector(_InputIterator __first, _InputIterator __last, const allocator_type& __a,
               typename enable_if<__is_input_iterator  <_InputIterator>::value &&
                                 !__is_forward_iterator<_InputIterator>::value &&
                                 is_constructible<
                                    value_type,
                                    typename iterator_traits<_InputIterator>::reference>::value>::type* = 0);
    template <class _ForwardIterator>
    vector(_ForwardIterator __first,
               typename enable_if<__is_forward_iterator<_ForwardIterator>::value &&
                                 is_constructible<
                                    value_type,
                                    typename iterator_traits<_ForwardIterator>::reference>::value,
                                 _ForwardIterator>::type __last);
    template <class _ForwardIterator>
    vector(_ForwardIterator __first, _ForwardIterator __last, const allocator_type& __a,
               typename enable_if<__is_forward_iterator<_ForwardIterator>::value &&
                                 is_constructible<
                                    value_type,
                                    typename iterator_traits<_ForwardIterator>::reference>::value>::type* = 0);

    ~vector()
    {}

    vector(const vector& __x);

    vector(const vector& __x, const allocator_type& __a);

    vector& operator=(const vector& __x);

    template <class _InputIterator>
        typename enable_if
        <
             __is_input_iterator  <_InputIterator>::value &&
            !__is_forward_iterator<_InputIterator>::value &&
            is_constructible<
                 value_type,
                 typename iterator_traits<_InputIterator>::reference>::value,
            void
        >::type
        assign(_InputIterator __first, _InputIterator __last);
    template <class _ForwardIterator>
        typename enable_if
        <
            __is_forward_iterator<_ForwardIterator>::value &&
            is_constructible<
                 value_type,
                 typename iterator_traits<_ForwardIterator>::reference>::value,
            void
        >::type
        assign(_ForwardIterator __first, _ForwardIterator __last);

    void assign(size_type __n, const_reference __u);

    allocator_type get_allocator() const throw()
    {
        return this->__alloc();
    }

    iterator               begin() throw();
    const_iterator         begin()   const throw();
    iterator               end() throw();
    const_iterator         end()     const throw();


    reverse_iterator       rbegin() throw()
    {
        return       reverse_iterator(end());
    }

    const_reverse_iterator rbegin()  const throw()
    {
        return const_reverse_iterator(end());
    }

    reverse_iterator       rend() throw()
    {
        return       reverse_iterator(begin());
    }

    const_reverse_iterator rend()    const throw()
    {
        return const_reverse_iterator(begin());
    }

    const_iterator         cbegin()  const throw()
    {
        return begin();
    }

    const_iterator         cend()    const throw()
    {
        return end();
    }

    const_reverse_iterator crbegin() const throw()
    {
        return rbegin();
    }

    const_reverse_iterator crend()   const throw()
    {
        return rend();
    }

    
    size_type size() const throw()
    {
        return static_cast<size_type>(this->__end_ - this->__begin_);
    }
    
    size_type capacity() const throw()
    {
        return __base::capacity();
    }

    bool empty() const throw()
    {
        return this->__begin_ == this->__end_;
    }
    size_type max_size() const throw();
    void reserve(size_type __n);
    void shrink_to_fit() throw();

    _LIBCPP_INLINE_VISIBILITY reference       operator[](size_type __n);
    _LIBCPP_INLINE_VISIBILITY const_reference operator[](size_type __n) const;
    reference       at(size_type __n);
    const_reference at(size_type __n) const;

    _LIBCPP_INLINE_VISIBILITY reference       front()
    {
        return *this->__begin_;
    }
    
    const_reference front() const
    {
        return *this->__begin_;
    }
    
    reference back()
    {
        return *(this->__end_ - 1);
    }
    
    const_reference back()  const
    {
        return *(this->__end_ - 1);
    }

    value_type* data() throw()
    {
        return this->__begin_;
    }

    const value_type* data() const throw()
    {
        return this->__begin_;
    }

    void __emplace_back(const value_type& __x)
    {
        push_back(__x);
    }

    void push_back(const_reference __x);

    void pop_back();

    iterator insert(const_iterator __position, const_reference __x);

    iterator insert(const_iterator __position, size_type __n, const_reference __x);

    template <class _InputIterator>
        typename enable_if
        <
             __is_input_iterator  <_InputIterator>::value &&
            !__is_forward_iterator<_InputIterator>::value &&
            is_constructible<
                 value_type,
                 typename iterator_traits<_InputIterator>::reference>::value,
            iterator
        >::type
        insert(const_iterator __position, _InputIterator __first, _InputIterator __last);

    template <class _ForwardIterator>
        typename enable_if
        <
            __is_forward_iterator<_ForwardIterator>::value &&
            is_constructible<
                 value_type,
                 typename iterator_traits<_ForwardIterator>::reference>::value,
            iterator
        >::type
        insert(const_iterator __position, _ForwardIterator __first, _ForwardIterator __last);

    iterator erase(const_iterator __position);
    
    iterator erase(const_iterator __first, const_iterator __last);

    void clear() throw()
    {
        size_type __old_size = size();
        __base::clear();
        __annotate_shrink(__old_size);
        __invalidate_all_iterators();
    }

    void resize(size_type __sz);
    
    void resize(size_type __sz, const_reference __x);

    void swap(vector&);

    bool __invariants() const;

private:
    void __invalidate_all_iterators();
    
    void __invalidate_iterators_past(pointer __new_last);
    
    void __vallocate(size_type __n);
    
    void __vdeallocate() throw();
    
    size_type __recommend(size_type __new_size) const;
    
    void __construct_at_end(size_type __n);

    void __construct_at_end(size_type __n, const_reference __x);
    
    template <class _ForwardIterator>
        typename enable_if
        <
            __is_forward_iterator<_ForwardIterator>::value,
            void
        >::type
        __construct_at_end(_ForwardIterator __first, _ForwardIterator __last, size_type __n);
    
    void __append(size_type __n);
    
    void __append(size_type __n, const_reference __x);
    
    iterator __make_iter(pointer __p) throw();
    
    const_iterator __make_iter(const_pointer __p) const throw();
    
    void __swap_out_circular_buffer(__split_buffer<value_type, allocator_type&>& __v);
    
    pointer __swap_out_circular_buffer(__split_buffer<value_type, allocator_type&>& __v, pointer __p);
    
    void __move_range(pointer __from_s, pointer __from_e, pointer __to);
    
    void __move_assign(vector& __c, true_type);

    void __move_assign(vector& __c, false_type);

    void __destruct_at_end(pointer __new_last) throw()
    {
        __invalidate_iterators_past(__new_last);
        size_type __old_size = size();
        __base::__destruct_at_end(__new_last);
        __annotate_shrink(__old_size);
    }

    template <class _Up> void __push_back_slow_path(_Up& __x);

    struct __RAII_IncreaseAnnotator {
      
      __RAII_IncreaseAnnotator(const vector &, size_type = 1) {}
      void __done() {}
    };

};

} // namespace ft

#endif // VECTOR_HPP
