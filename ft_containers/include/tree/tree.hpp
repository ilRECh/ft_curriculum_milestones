#ifndef FT_TREE
#define FT_TREE

#include "../type_traits.hpp"
#include "../utility.hpp"

using std::allocator;
using std::pointer_traits;
using std::allocator_traits;
using std::__rebind_alloc_helper;
using std::__is_same_uncvref;
using std::__rebind_pointer;
using std::is_pointer;
using std::is_same;
using std::is_const;
using std::bidirectional_iterator_tag;
using std::__compressed_pair;
using std::unique_ptr;
using std::numeric_limits;
using std::iterator_traits;
using std::is_copy_constructible;
using std::__second_tag;

namespace ft {

template <class _Tp, class _Compare, class _Allocator>
class __tree;
template <class _Tp, class _NodePtr, class _DiffType>
class __tree_iterator;
template <class _Tp, class _ConstNodePtr, class _DiffType>
class __tree_const_iterator;
template <class _Pointer>
class __tree_end_node;
template <class _VoidPtr>
class __tree_node_base;
template <class _Tp, class _VoidPtr>
class __tree_node;
template <class _Key, class _Value>
struct __value_type;
template <class _Allocator>
class __map_node_destructor;
template <class _TreeIterator>
class  __map_iterator;
template <class _TreeIterator>
class  __map_const_iterator;

}


#include "node_traits/__tree_key_value_types.hpp"
#include "node_traits/__tree_node_base_types.hpp"
#include "node_traits/__tree_map_pointer_types.hpp"
#include "node_traits/__tree_node_types.hpp"
#include "node/__tree_node_base.hpp"
#include "node/__tree_node.hpp"
#include "node/__tree_end_node.hpp"
#include "node/__tree_node_destructor.hpp"
#include "__tree_is_left_child.hpp"
#include "__tree_min.hpp"
#include "__tree_max.hpp"
#include "__tree_next.hpp"
#include "__tree_next_iter.hpp"
#include "__tree_prev_iter.hpp"
#include "__tree_leaf.hpp"
#include "__tree_left_rotate.hpp"
#include "__tree_right_rotate.hpp"
#include "__tree_balance_after_insert.hpp"
#include "__tree_remove.hpp"

namespace ft {

template <class _Tp, class _Compare, class _Allocator>
class __tree
{
public:
    typedef _Tp                                      value_type;
    typedef _Compare                                 value_compare;
    typedef _Allocator                               allocator_type;

private:
    typedef allocator_traits<allocator_type>         __alloc_traits;
    typedef typename __make_tree_node_types<value_type,
        typename __alloc_traits::void_pointer>::type
                                                    _NodeTypes;
    typedef typename _NodeTypes::key_type           key_type;
public:
    typedef typename _NodeTypes::__node_value_type      __node_value_type;
    typedef typename _NodeTypes::__container_value_type __container_value_type;

    typedef typename __alloc_traits::pointer         pointer;
    typedef typename __alloc_traits::const_pointer   const_pointer;
    typedef typename __alloc_traits::size_type       size_type;
    typedef typename __alloc_traits::difference_type difference_type;

public:
    typedef typename _NodeTypes::__void_pointer        __void_pointer;

    typedef typename _NodeTypes::__node_type           __node;
    typedef typename _NodeTypes::__node_pointer        __node_pointer;

    typedef typename _NodeTypes::__node_base_type      __node_base;
    typedef typename _NodeTypes::__node_base_pointer   __node_base_pointer;

    typedef typename _NodeTypes::__end_node_type       __end_node_t;
    typedef typename _NodeTypes::__end_node_pointer    __end_node_ptr;

    typedef typename _NodeTypes::__parent_pointer      __parent_pointer;
    typedef typename _NodeTypes::__iter_pointer        __iter_pointer;

    typedef typename __rebind_alloc_helper<__alloc_traits, __node>::type __node_allocator;
    typedef allocator_traits<__node_allocator>         __node_traits;

private:
    // check for sane allocator pointer rebinding semantics. Rebinding the
    // allocator for a new pointer type should be exactly the same as rebinding
    // the pointer using 'pointer_traits'.
    static_assert((is_same<__node_pointer, typename __node_traits::pointer>::value),
                  "Allocator does not rebind pointers in a sane manner.");
    typedef typename __rebind_alloc_helper<__node_traits, __node_base>::type
        __node_base_allocator;
    typedef allocator_traits<__node_base_allocator> __node_base_traits;
    static_assert((is_same<__node_base_pointer, typename __node_base_traits::pointer>::value),
                 "Allocator does not rebind pointers in a sane manner.");

private:
    __iter_pointer                                     __begin_node_;
    __compressed_pair<__end_node_t, __node_allocator>  __compressedEndNode;
    __compressed_pair<size_type, value_compare>        __compressedValueCompare;

public:
    
    __iter_pointer __end_node() throw()
    {
        return static_cast<__iter_pointer>(
                pointer_traits<__end_node_ptr>::pointer_to(__compressedEndNode.first())
        );
    }
    
    __iter_pointer __end_node() const throw()
    {
        return static_cast<__iter_pointer>(
            pointer_traits<__end_node_ptr>::pointer_to(
                const_cast<__end_node_t&>(__compressedEndNode.first())
            )
        );
    }
    
    __node_allocator& __node_alloc() throw()
    {
        return __compressedEndNode.second();
    }

private:
    
    const __node_allocator& __node_alloc() const throw()
    {
        return __compressedEndNode.second();
    }
    
    __iter_pointer& __begin_node() throw()
    {
        return __begin_node_;
    }
    
    const __iter_pointer& __begin_node() const throw()
    {
        return __begin_node_;
    }

public:
    
    allocator_type __alloc() const throw()
    {
        return allocator_type(__node_alloc());
    }
private:
    
    size_type& size() throw()
    {
        return __compressedValueCompare.first();
    }
public:
    
    const size_type& size() const throw()
    {
        return __compressedValueCompare.first();
    }
    
    value_compare& value_comp() throw()
    {
        return __compressedValueCompare.second();
    }
    
    const value_compare& value_comp() const throw()
    {
        return __compressedValueCompare.second();
    }

public:

    __node_pointer __get_root() const throw()
    {
        return static_cast<__node_pointer>(__end_node()->__left_);
    }

    __node_base_pointer* __root_ptr() const throw()
    {
        return &__end_node()->__left_;
    }

    typedef __tree_iterator<value_type, __node_pointer, difference_type>       iterator;
    
    typedef __tree_const_iterator<value_type, __node_pointer, difference_type> const_iterator;

    explicit __tree(const value_compare& __comp);
    
    explicit __tree(const allocator_type& __a);
    
    __tree(const value_compare& __comp, const allocator_type& __a);
    
    __tree(const __tree& __t);

    __tree& operator=(const __tree& __t);

    template <class _InputIterator>
    void __assign_multi(_InputIterator __first, _InputIterator __last);

    ~__tree();

    iterator begin()  throw()
    {
        return iterator(__begin_node());
    }
    
    const_iterator begin() const throw()
    {
        return const_iterator(__begin_node());
    }
    
    iterator end() throw()
    {
        return iterator(__end_node());
    }
    
    const_iterator end() const throw()
    {
        return const_iterator(__end_node());
    }

    size_type max_size() const throw()
    {
        return std::min<size_type>(
                __node_traits::max_size(__node_alloc()),
                numeric_limits<difference_type >::max()
        );
    }

    iterator __insert_multi(const __container_value_type& __v);
    
    iterator __node_insert_multi(__node_pointer __nd);

    void clear() throw();

    void swap(__tree& __t);

    template <class _Key, class _Args>
    
    pair<iterator, bool> __emplace_unique_key_args(_Key const&, _Args& __args);
    template <class _Key, class _Args>
    
    iterator __emplace_hint_unique_key_args(const_iterator, _Key const&, _Args&);
    
    pair<iterator, bool> __insert_unique(const __container_value_type& __v) {
        // return __emplace_unique_key_args(_NodeTypes::__get_key(__v), __v);
        __parent_pointer __parent;
        __node_base_pointer& __child = __find_equal(__parent, _NodeTypes::__get_key(__v));
        __node_pointer __r = static_cast<__node_pointer>(__child);
        bool __inserted = false;
        if (__child == NULL)
        {
            __node_holder __h = __construct_node( __v);
            __insert_node_at(__parent, __child, static_cast<__node_base_pointer>(__h.get()));
            __r = __h.release();
            __inserted = true;
        }
        return ft::pair<iterator, bool>(iterator(__r), __inserted);
    }

    
    iterator __insert_unique(const_iterator __p, const __container_value_type& __v) {
        // return __emplace_hint_unique_key_args(__p, _NodeTypes::__get_key(__v), __v);
        __parent_pointer __parent;
        __node_base_pointer __dummy;
        __node_base_pointer& __child = __find_equal(__p, __parent, __dummy, _NodeTypes::__get_key(__v));
        __node_pointer __r = static_cast<__node_pointer>(__child);
        if (__child == NULL)
        {
            __node_holder __h = __construct_node(__v);
            __insert_node_at(__parent, __child, static_cast<__node_base_pointer>(__h.get()));
            __r = __h.release();
        }
        return iterator(__r);
    }
    
    ft::pair<iterator, bool> __node_insert_unique(__node_pointer __nd);
    
    iterator             __node_insert_unique(const_iterator __p,
                                              __node_pointer __nd);

     iterator
    __remove_node_pointer(__node_pointer) throw();

    iterator erase(const_iterator __p);
    iterator erase(const_iterator __f, const_iterator __l);
    template <class _Key>
        size_type __erase_unique(const _Key& __k);
    template <class _Key>
        size_type __erase_multi(const _Key& __k);

    void __insert_node_at(__parent_pointer     __parent,
                          __node_base_pointer& __child,
                          __node_base_pointer __new_node) throw();

    template <class _Key>
        iterator find(const _Key& __v);
    template <class _Key>
        const_iterator find(const _Key& __v) const;

    template <class _Key>
        size_type __count_unique(const _Key& __k) const;
    template <class _Key>
        size_type __count_multi(const _Key& __k) const;

    template <class _Key>
        
        iterator lower_bound(const _Key& __v)
            {return __lower_bound(__v, __get_root(), __end_node());}
    template <class _Key>
        iterator __lower_bound(const _Key& __v,
                               __node_pointer __get_root,
                               __iter_pointer __result);
    template <class _Key>
        
        const_iterator lower_bound(const _Key& __v) const
            {return __lower_bound(__v, __get_root(), __end_node());}
    template <class _Key>
        const_iterator __lower_bound(const _Key& __v,
                                     __node_pointer __get_root,
                                     __iter_pointer __result) const;
    template <class _Key>
        
        iterator upper_bound(const _Key& __v)
            {return __upper_bound(__v, __get_root(), __end_node());}
    template <class _Key>
        iterator __upper_bound(const _Key& __v,
                               __node_pointer __get_root,
                               __iter_pointer __result);
    template <class _Key>
        
        const_iterator upper_bound(const _Key& __v) const
            {return __upper_bound(__v, __get_root(), __end_node());}
    template <class _Key>
        const_iterator __upper_bound(const _Key& __v,
                                     __node_pointer __get_root,
                                     __iter_pointer __result) const;
    template <class _Key>
        pair<iterator, iterator>
        __equal_range_unique(const _Key& __k);
    template <class _Key>
        pair<const_iterator, const_iterator>
        __equal_range_unique(const _Key& __k) const;

    typedef __tree_node_destructor<__node_allocator> _Dp;
    typedef unique_ptr<__node, _Dp> __node_holder;

    __node_holder remove(const_iterator __p) throw();
private:
    __node_base_pointer& __find_leaf_low(__parent_pointer& __parent, const key_type& __v);
    __node_base_pointer& __find_leaf_high(__parent_pointer& __parent, const key_type& __v);
    __node_base_pointer& __find_leaf(const_iterator __hint, __parent_pointer& __parent, const key_type& __v);
    // FIXME: Make this function const qualified. Unfortunetly doing so
    // breaks existing code which uses non-const callable comparators.
    template <class _Key>
    __node_base_pointer&
        __find_equal(__parent_pointer& __parent, const _Key& __v);
    
    template <class _Key>
    __node_base_pointer& __find_equal(__parent_pointer& __parent, const _Key& __v) const
    {
        return const_cast<__tree*>(this)->__find_equal(__parent, __v);
    }
    
    template <class _Key>
    __node_base_pointer&
    __find_equal(
        const_iterator __hint, __parent_pointer& __parent,
        __node_base_pointer& __dummy,
        const _Key& __v);


    __node_holder __construct_node(const __container_value_type& __v);

    void destroy(__node_pointer __nd) throw();

    void __copy_assign_alloc(const __tree& __t)
    {
        __copy_assign_alloc(
            __t,
            integral_constant
            <
                bool,
                __node_traits::propagate_on_container_copy_assignment::value
            >());
    }

    
    void __copy_assign_alloc(const __tree& __t, true_type)
    {
        if (__node_alloc() != __t.__node_alloc())
        {
            clear();
        }
        __node_alloc() = __t.__node_alloc();
    }
    
    void __copy_assign_alloc(const __tree&, false_type) {}

    void __move_assign(__tree& __t, false_type);

    void __move_assign(__tree& __t, true_type);

    // void __move_assign_alloc(__tree& __t)
    // {
    //     __move_assign_alloc(__t, ft::integral_constant<bool,
    //          __node_traits::propagate_on_container_move_assignment::value>());
    // }

    // void __move_assign_alloc(__tree& __t, true_type)
    // {
    //     __node_alloc() = __t.__node_alloc();
    // }
    
    // void __move_assign_alloc(__tree&, false_type) throw() {}

    __node_pointer __detach();
    static __node_pointer __detach(__node_pointer);


    template <class, class, class, class> friend class map;
};

template <class _Tp, class _Compare, class _Allocator>
__tree<_Tp, _Compare, _Allocator>::__tree(const value_compare& __comp) 
    : __compressedValueCompare(0, __comp)
{
    __begin_node() = __end_node();
}

// template <class _Tp, class _Compare, class _Allocator>
// __tree<_Tp, _Compare, _Allocator>::__tree(const allocator_type& __a)
//     : __begin_node_(__iter_pointer()),
//       __compressedEndNode(__second_tag(), __node_allocator(__a)),
//       __compressedValueCompare(0)
// {
//     __begin_node() = __end_node();
// }

// template <class _Tp, class _Compare, class _Allocator>
// __tree<_Tp, _Compare, _Allocator>::__tree(const value_compare& __comp,
//                                            const allocator_type& __a)
//     : __begin_node_(__iter_pointer()),
//       __compressedEndNode(__second_tag(), __node_allocator(__a)),
//       __compressedValueCompare(0, __comp)
// {
//     __begin_node() = __end_node();
// }

template <class _Tp, class _Compare, class _Allocator>
__tree<_Tp, _Compare, _Allocator>::__tree(const __tree& __t)
    : __begin_node_(__iter_pointer()),
      __compressedEndNode(__second_tag(), __node_traits::select_on_container_copy_construction(__t.__node_alloc())),
      __compressedValueCompare(0, __t.value_comp())
{
    __begin_node() = __end_node();
}

template <class _Tp, class _Compare, class _Allocator>
__tree<_Tp, _Compare, _Allocator>::~__tree()
{
    static_assert((is_copy_constructible<value_compare>::value),
                 "Comparator must be copy-constructible.");
    destroy(__get_root());
}

};

#include "operator=.hpp"
#include "destroy.hpp"
#include "swap_tree_method.hpp"
#include "remove.hpp"
#include "__tree_iterator.hpp"
#include "__tree_const_iterator.hpp"
#include "swap.hpp"
#include "__equal_range_unique.hpp"
#include "__upper_bound.hpp"
#include "__lower_bound.hpp"
#include "__count_unique.hpp"
#include "find.hpp"
#include "__erase_unique.hpp"
#include "erase.hpp"
#include "__remove_node_pointer.hpp"
#include "__node_insert_unique.hpp"
#include "__construct_node.hpp"
#include "__insert_node_at.hpp"
#include "__find_equal.hpp"
#include "__find_leaf.hpp"
#include "__find_leaf_high.hpp"
#include "__find_leaf_low.hpp"
#include "clear.hpp"

#endif // FT_TREE

