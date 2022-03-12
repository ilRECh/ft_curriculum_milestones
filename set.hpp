#ifndef FT_SET_HPP
#define FT_SET_HPP

#include "include/tree/tree.hpp"
#include "include/iterator_traits.hpp"
#include "include/utility.hpp"
#include "include/type_traits.hpp"
#include "include/reverse_iterator.hpp"
#include "include/__value_type.hpp"
#include <memory>

namespace ft {

template
<
        class _Key,
        class _Compare = ft::less<_Key>,
        class _Allocator = std::allocator<_Key> 
>
class set
{
public:
    // types:
    typedef _Key                                     key_type;
    typedef key_type                                 value_type;
    typedef _Compare                                 key_compare;
    typedef key_compare                              value_compare;
    typedef _Allocator                               allocator_type;
    typedef value_type&                              reference;
    typedef const value_type&                        const_reference;

    static_assert(sizeof(__diagnose_non_const_comparator<_Key, _Compare>()), "");
    static_assert((std::is_same<typename allocator_type::value_type, value_type>::value),
                  "Allocator::value_type must be same type as value_type");

private:
    typedef ft::__tree<value_type, value_compare, allocator_type> __base;
    typedef allocator_traits<allocator_type>                  __alloc_traits;
    typedef typename __base::__node_holder                    __node_holder;

    __base __tree_;

public:
    typedef typename __base::pointer               pointer;
    typedef typename __base::const_pointer         const_pointer;
    typedef typename __base::size_type             size_type;
    typedef typename __base::difference_type       difference_type;
    typedef typename __base::const_iterator        iterator;
    typedef typename __base::const_iterator        const_iterator;
    typedef ft::reverse_iterator<iterator>         reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>   const_reverse_iterator;

    template <class _Key2, class _Compare2, class _Alloc2>
    friend class set;

    set() : __tree_(value_compare()) {}

    explicit set(const value_compare& __comp) : __tree_(__comp) {}

    explicit set(const value_compare& __comp, const allocator_type& __a)
        : __tree_(__comp, __a) {}
    
    template <class _InputIterator>
    set(_InputIterator __f,
        _InputIterator __l,
        const value_compare& __comp = value_compare())
    : __tree_(__comp)
    {
        insert(__f, __l);
    }

    template <class _InputIterator>
    set(_InputIterator __f,
        _InputIterator __l,
        const value_compare& __comp,
        const allocator_type& __a)
    : __tree_(__comp, __a)
    {
        insert(__f, __l);
    }

    set(const set& __s)
    : __tree_(__s.__tree_)
    {
        insert(__s.begin(), __s.end());
    }

    set& operator=(const set& __s)
    {
        __tree_ = __s.__tree_;
        return *this;
    }

    explicit set(const allocator_type& __a)
        : __tree_(__a) {}

    set(const set& __s, const allocator_type& __a)
        : __tree_(__s.__tree_.value_comp(), __a)
    {
        insert(__s.begin(), __s.end());
    }

    iterator begin() throw()
    {
        return __tree_.begin();
    }

    const_iterator begin() const throw()
    {
        return __tree_.begin();
    }

    iterator end() throw()
    {
        return __tree_.end();
    }

    const_iterator end()   const throw()
    {
        return __tree_.end();
    }

    reverse_iterator rbegin() throw()
    {
        return reverse_iterator(end());
    }

    const_reverse_iterator rbegin() const throw()
    {
        return const_reverse_iterator(end());
    }

    reverse_iterator rend() throw()
    {
        return reverse_iterator(begin());
    }

    const_reverse_iterator rend() const throw()
    {
        return const_reverse_iterator(begin());
    }

    const_iterator cbegin()  const throw()
    {
        return begin();
    }

    const_iterator cend() const throw()
    {
        return end();
    }

    const_reverse_iterator crbegin() const throw()
    {
        return rbegin();
    }

    const_reverse_iterator crend() const throw()
    {
        return rend();
    }

    bool empty() const throw()
    {
        return __tree_.size() == 0;
    }

    size_type size() const throw()
    {
        return __tree_.size();
    }

    size_type max_size() const throw()
    {
        return __tree_.max_size();
    }

    ft::pair<iterator,bool> insert(const value_type& __v)
    {
        return __tree_.__insert_unique(__v);
    }

    iterator insert(const_iterator __p, const value_type& __v)
    {
        return __tree_.__insert_unique(__p, __v);
    }

    template <class _InputIterator>
    void insert(_InputIterator __f, _InputIterator __l)
    {
        for (const_iterator __e = cend(); __f != __l; ++__f)
            __tree_.__insert_unique(__e, *__f);
    }

    iterator  erase(const_iterator __p)
    {
        return __tree_.erase(__p);
    }

    size_type erase(const key_type& __k)
    {
        return __tree_.__erase_unique(__k);
    }

    iterator  erase(const_iterator __f, const_iterator __l)
    {
        return __tree_.erase(__f, __l);
    }

    void clear() throw()
    {
        __tree_.clear();
    }

    void swap(set& __s)
    {
        __tree_.swap(__s.__tree_);
    }

    allocator_type get_allocator() const throw()
    {
        return __tree_.__alloc();
    }

    key_compare    key_comp() const
    {
        return __tree_.value_comp();
    }

    value_compare  value_comp() const
    {
        return __tree_.value_comp();
    }

    iterator find(const key_type& __k)
    {
        return __tree_.find(__k);
    }

    const_iterator find(const key_type& __k) const
    {
        return __tree_.find(__k);
    }

    size_type count(const key_type& __k) const
    {
        return __tree_.__count_unique(__k);
    }

    iterator lower_bound(const key_type& __k)
    {
        return __tree_.lower_bound(__k);
    }

    const_iterator lower_bound(const key_type& __k) const
    {
        return __tree_.lower_bound(__k);
    }

    iterator upper_bound(const key_type& __k)
    {
        return __tree_.upper_bound(__k);
    }

    const_iterator upper_bound(const key_type& __k) const
    {
        return __tree_.upper_bound(__k);
    }

    ft::pair<iterator,iterator> equal_range(const key_type& __k)
    {
        return __tree_.__equal_range_unique(__k);
    }
    
    ft::pair<const_iterator,const_iterator> equal_range(const key_type& __k) const
    {
        return __tree_.__equal_range_unique(__k);
    }
};

} // namespace ft

#include "include/set/operator==.hpp"
#include "include/set/operator<.hpp"
#include "include/set/operator>.hpp"
#include "include/set/operator!=.hpp"
#include "include/set/operator>=.hpp"
#include "include/set/operator<=.hpp"
#include "include/set/swap.hpp"

#endif // FT_SET_HPP
