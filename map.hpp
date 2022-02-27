#ifndef MAP_HPP
#define MAP_HPP

#include "include/tree.hpp"
#include "include/iterator.hpp"
#include <memory>
#include "include/utility.hpp"
#include "include/type_traits.hpp"

#include "include/map/__value_type.hpp"
#include "include/map/__map_node_destructor.hpp"
#include "include/map/__map_value_compare.hpp"
#include "include/map/__map_iterator.hpp"
#include "include/map/__map_const_iterator.hpp"

using std::allocator;

using std::__rebind_alloc_helper;
using std::allocator_traits;
using std::__is_nothrow_swappable;
using std::is_nothrow_copy_constructible;
using std::unique_ptr;
using std::pointer_traits;
using std::bidirectional_iterator_tag;
using std::binary_function;

namespace ft {

template <class _Key, class _Tp, class _Compare = less<_Key>,
          class _Allocator = allocator<pair<const _Key, _Tp> > >
class map
{
public:
    typedef _Key                                     key_type;
    typedef _Tp                                      mapped_type;
    typedef pair<const key_type, mapped_type>        value_type;
    typedef _Compare                                 key_compare;
    typedef _Allocator                               allocator_type;
    typedef value_type&                              reference;
    typedef const value_type&                        const_reference;

    static_assert(sizeof(__diagnose_non_const_comparator<_Key, _Compare>()), "");
    static_assert((is_same<typename allocator_type::value_type, value_type>::value),
                  "Allocator::value_type must be same type as value_type");

    class value_compare
        : public binary_function<value_type, value_type, bool>
    {
        friend class map;
    protected:
        key_compare comp;

        value_compare(key_compare c) : comp(c) {}
    public:
        
        bool operator()(const value_type& __x, const value_type& __y) const
            {return comp(__x.first, __y.first);}
    };

private:

    typedef __value_type<key_type, mapped_type>             __value_type;
    typedef __map_value_compare<key_type, __value_type, key_compare> __vc;
    typedef typename __rebind_alloc_helper<allocator_traits<allocator_type>,
                                                 __value_type>::type __allocator_type;
    typedef __tree<__value_type, __vc, __allocator_type>   __base;
    typedef typename __base::__node_traits                 __node_traits;
    typedef allocator_traits<allocator_type>               __alloc_traits;

    __base __tree_;

public:
    typedef typename __alloc_traits::pointer               pointer;
    typedef typename __alloc_traits::const_pointer         const_pointer;
    typedef typename __alloc_traits::size_type             size_type;
    typedef typename __alloc_traits::difference_type       difference_type;
    typedef __map_iterator<typename __base::iterator>             iterator;
    typedef __map_const_iterator<typename __base::const_iterator> const_iterator;
    typedef ft::reverse_iterator<iterator>               reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>         const_reverse_iterator;

    map() : __tree_(__vc(key_compare())) {}

    explicit map(const key_compare& __comp) : __tree_(__vc(__comp)) {}

    explicit map(const key_compare& __comp, const allocator_type& __a)
        : __tree_(__vc(__comp), typename __base::allocator_type(__a)) {}

    template <class _InputIterator>
        map(_InputIterator __f, _InputIterator __l,
            const key_compare& __comp = key_compare())
        : __tree_(__vc(__comp))
	{ insert(__f, __l); }

    template <class _InputIterator>
        map(_InputIterator __f, _InputIterator __l,
            const key_compare& __comp, const allocator_type& __a)
        : __tree_(__vc(__comp), typename __base::allocator_type(__a))
    { insert(__f, __l); }


    map(const map& __m)
        : __tree_(__m.__tree_)
	{ insert(__m.begin(), __m.end()); }

    map&
		operator=(const map& __m)
	{
		if (this != &__m) {
			__tree_.clear();
			__tree_.value_comp() = __m.__tree_.value_comp();
			__tree_.__copy_assign_alloc(__m.__tree_);
			insert(__m.begin(), __m.end());
		}
		return *this;
	}

    explicit map(const allocator_type& __a)
		: __tree_(typename __base::allocator_type(__a)) {}
    map(const map& __m, const allocator_type& __a)
        : __tree_(__m.__tree_.value_comp(), typename __base::allocator_type(__a)) 
	{ insert(__m.begin(), __m.end()); }

	// Getting iterators: common and const_, reverse_
	iterator
		begin() throw() {return __tree_.begin();}
    const_iterator
		begin() const throw() {return __tree_.begin();}
	iterator
		end() throw() {return __tree_.end();}
    const_iterator
		end() const throw() {return __tree_.end();}
	reverse_iterator
		rbegin() throw() {return reverse_iterator(end());}
    const_reverse_iterator
		rbegin() const throw() {return const_reverse_iterator(end());}
	reverse_iterator
		rend() throw() {return reverse_iterator(begin());}
    const_reverse_iterator
		rend() const throw() {return const_reverse_iterator(begin());}
    const_iterator
		cbegin() const throw() {return begin();}
    const_iterator
		cend() const throw() {return end();}
    const_reverse_iterator
		crbegin() const throw() {return rbegin();}
    const_reverse_iterator
		crend() const throw() {return rend();}

    bool
		empty() const throw() {return __tree_.size() == 0;}
    size_type
		size() const throw() {return __tree_.size();}
    size_type
		max_size() const throw() {return __tree_.max_size();}

    mapped_type&
		operator[](const key_type& __k);

	mapped_type&
		at(const key_type& __k);
    const mapped_type&
		at(const key_type& __k) const;

    allocator_type get_allocator() const throw() {return allocator_type(__tree_.__alloc());}
    key_compare    key_comp()      const {return __tree_.value_comp().key_comp();}
    value_compare  value_comp()    const {return value_compare(__tree_.value_comp().key_comp());}

    pair<iterator, bool>
        insert(const value_type& __v) {return __tree_.__insert_unique(__v);}

    iterator
        insert(const_iterator __p, const value_type& __v)
            {return __tree_.__insert_unique(__p.__i_, __v);}

    template <class _InputIterator>
        void insert(_InputIterator __f, _InputIterator __l)
        {
            for (const_iterator __e = cend(); __f != __l; ++__f)
                insert(__e.__i_, *__f);
        }

    iterator erase(const_iterator __p) {return __tree_.erase(__p.__i_);}
    iterator erase(iterator __p)       {return __tree_.erase(__p.__i_);}
    size_type erase(const key_type& __k)
        {return __tree_.__erase_unique(__k);}
    iterator  erase(const_iterator __f, const_iterator __l)
        {return __tree_.erase(__f.__i_, __l.__i_);}
    void clear() throw() {__tree_.clear();}

    void swap(map& __m)
        {__tree_.swap(__m.__tree_);}

    iterator find(const key_type& __k)             {return __tree_.find(__k);}
    const_iterator find(const key_type& __k) const {return __tree_.find(__k);}

    size_type      count(const key_type& __k) const
        {return __tree_.__count_unique(__k);}
    iterator lower_bound(const key_type& __k)
        {return __tree_.lower_bound(__k);}
    const_iterator lower_bound(const key_type& __k) const
        {return __tree_.lower_bound(__k);}

    iterator upper_bound(const key_type& __k)
        {return __tree_.upper_bound(__k);}
    const_iterator upper_bound(const key_type& __k) const
        {return __tree_.upper_bound(__k);}
    pair<iterator,iterator> equal_range(const key_type& __k)
        {return __tree_.__equal_range_unique(__k);}
    pair<const_iterator,const_iterator> equal_range(const key_type& __k) const
        {return __tree_.__equal_range_unique(__k);}

private:
    typedef typename __base::__node                    __node;
    typedef typename __base::__node_allocator          __node_allocator;
    typedef typename __base::__node_pointer            __node_pointer;
    typedef typename __base::__node_base_pointer       __node_base_pointer;
    typedef typename __base::__parent_pointer          __parent_pointer;

    typedef __map_node_destructor<__node_allocator> _Dp;
    typedef unique_ptr<__node, _Dp> __node_holder;
	__node_holder __construct_node_with_key(const key_type& __k);
};


template <class _Key, class _Tp, class _Compare, class _Allocator>
typename map<_Key, _Tp, _Compare, _Allocator>::__node_holder
map<_Key, _Tp, _Compare, _Allocator>::__construct_node_with_key(const key_type& __k)  
{
    __node_allocator& __na = __tree_.__node_alloc();
    __node_holder __h(__node_traits::allocate(__na, 1), _Dp(__na));
    __node_traits::construct(__na, &__h->__value_.__get_value().first, __k);
    __h.get_deleter().__first_constructed = true;
    __node_traits::construct(__na, &__h->__value_.__get_value().second);
    __h.get_deleter().__second_constructed = true;
    return __node_holder(std::__rv<__node_holder>(__h));
}

template <class _Key, class _Tp, class _Compare, class _Allocator>
_Tp& map<_Key, _Tp, _Compare, _Allocator>::operator[](const key_type& __k)
{
    __parent_pointer __parent;
    __node_base_pointer& __child = __tree_.__find_equal(__parent, __k);
    __node_pointer __r = static_cast<__node_pointer>(__child);
    if (__child == nullptr)
    {
        __node_holder __h = __construct_node_with_key(__k);
        __tree_.__insert_node_at(__parent, __child, static_cast<__node_base_pointer>(__h.get()));
        __r = __h.release();
    }
    return __r->__value_.__get_value().second;
}

template <class _Key, class _Tp, class _Compare, class _Allocator>
_Tp& map<_Key, _Tp, _Compare, _Allocator>::at(const key_type& __k)
{
    __parent_pointer __parent;
    __node_base_pointer& __child = __tree_.__find_equal(__parent, __k);
    if (__child == nullptr)
        std::out_of_range("map::at:  key not found");
    return static_cast<__node_pointer>(__child)->__value_.__get_value().second;
}

template <class _Key, class _Tp, class _Compare, class _Allocator>
const _Tp& map<_Key, _Tp, _Compare, _Allocator>::at(const key_type& __k) const
{
    __parent_pointer __parent;
    __node_base_pointer __child = __tree_.__find_equal(__parent, __k);
    if (__child == nullptr)
        throw std::out_of_range("map::at:  key not found");
    return static_cast<__node_pointer>(__child)->__value_.__get_value().second;
}


template <class _Key, class _Tp, class _Compare, class _Allocator>
inline bool operator==(
	const map<_Key, _Tp, _Compare, _Allocator>& __x,
    const map<_Key, _Tp, _Compare, _Allocator>& __y)
{
    return __x.size() == __y.size() && ft::equal(__x.begin(), __x.end(), __y.begin());
}

template <class _Key, class _Tp, class _Compare, class _Allocator>
inline bool operator< (
	const map<_Key, _Tp, _Compare, _Allocator>& __x,
    const map<_Key, _Tp, _Compare, _Allocator>& __y)
{
    return ft::lexicographical_compare(__x.begin(), __x.end(), __y.begin(), __y.end());
}

template <class _Key, class _Tp, class _Compare, class _Allocator>
inline bool operator!=(
	const map<_Key, _Tp, _Compare, _Allocator>& __x,
    const map<_Key, _Tp, _Compare, _Allocator>& __y)
{
    return !(__x == __y);
}

template <class _Key, class _Tp, class _Compare, class _Allocator>
inline bool operator> (
	const map<_Key, _Tp, _Compare, _Allocator>& __x,
    const map<_Key, _Tp, _Compare, _Allocator>& __y)
{
    return __y < __x;
}

template <class _Key, class _Tp, class _Compare, class _Allocator>
inline bool operator>=(
	const map<_Key, _Tp, _Compare, _Allocator>& __x,
    const map<_Key, _Tp, _Compare, _Allocator>& __y)
{
    return !(__x < __y);
}

template <class _Key, class _Tp, class _Compare, class _Allocator>
inline bool operator<=(
	const map<_Key, _Tp, _Compare, _Allocator>& __x,
    const map<_Key, _Tp, _Compare, _Allocator>& __y)
{
    return !(__y < __x);
}

template <class _Key, class _Tp, class _Compare, class _Allocator>
inline void swap(
	map<_Key, _Tp, _Compare, _Allocator>& __x,
    map<_Key, _Tp, _Compare, _Allocator>& __y)
{
    __x.swap(__y);
}

};

#endif
