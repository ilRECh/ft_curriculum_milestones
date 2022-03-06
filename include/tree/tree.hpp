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

template <class _NodePtr>
inline bool __tree_is_left_child(_NodePtr node) throw();

template <class _Tp, class _Compare, class _Allocator> class __tree;
template <class _Tp, class _NodePtr, class _DiffType>
    class __tree_iterator;
template <class _Tp, class _ConstNodePtr, class _DiffType>
    class __tree_const_iterator;

template <class _Pointer> class __tree_end_node;
template <class _VoidPtr> class __tree_node_base;
template <class _Tp, class _VoidPtr> class __tree_node;

template <class _Key, class _Value>
struct __value_type;

template <class _Allocator> class __map_node_destructor;
template <class _TreeIterator> class  __map_iterator;
template <class _TreeIterator> class  __map_const_iterator;

}

#include "node/__tree_end_node.hpp"
#include "node_traits/__tree_key_value_types.hpp"
#include "__tree_min.hpp"
#include "__tree_max.hpp"
#include "__tree_next.hpp"

namespace ft {

template <class _EndNodePtr, class _NodePtr>
inline _EndNodePtr __tree_next_iter(_NodePtr __x) throw()
{
    if (__x->__right_ != NULL)
        return static_cast<_EndNodePtr>(__tree_min(__x->__right_));
    while (!__tree_is_left_child(__x))
        __x = __x->__get_parent();
    return static_cast<_EndNodePtr>(__x->__parent_);
}

// Returns:  pointer to the previous in-order node before __x.
// Precondition:  __x != NULL.
// Note: __x may be the end node.
template <class _NodePtr, class _EndNodePtr>
inline _NodePtr __tree_prev_iter(_EndNodePtr __endNode) throw()
{
    if (__endNode->__left_ != NULL)
        return __tree_max(__endNode->__left_);
    _NodePtr __node = static_cast<_NodePtr>(__endNode);
    while (__tree_is_left_child(__node))
        __node = __node->__get_parent();
    return __node->__get_parent();
}

// Returns:  pointer to a node which has no children
// Precondition:  __x != NULL.
template <class _NodePtr>
_NodePtr
__tree_leaf(_NodePtr __x) throw()
{
    while (true)
    {
        if (__x->__left_ != NULL)
        {
            __x = __x->__left_;
            continue;
        }
        if (__x->__right_ != NULL)
        {
            __x = __x->__right_;
            continue;
        }
        break;
    }
    return __x;
}

// Effects:  Makes __x->__right_ the subtree root with __x as its left child
//           while preserving in-order order.
// Precondition:  __x->__right_ != NULL
template <class _NodePtr>
void
__tree_left_rotate(_NodePtr __x) throw()
{
    _NodePtr __y = __x->__right_;
    __x->__right_ = __y->__left_;
    if (__x->__right_ != NULL)
        __x->__right_->__set_parent(__x);
    __y->__parent_ = __x->__parent_;
    if (__tree_is_left_child(__x))
        __x->__parent_->__left_ = __y;
    else
        __x->__get_parent()->__right_ = __y;
    __y->__left_ = __x;
    __x->__set_parent(__y);
}

// Effects:  Makes __x->__left_ the subtree root with __x as its right child
//           while preserving in-order order.
// Precondition:  __x->__left_ != NULL
template <class _NodePtr>
void
__tree_right_rotate(_NodePtr __x) throw()
{
    _NodePtr __y = __x->__left_;
    __x->__left_ = __y->__right_;
    if (__x->__left_ != NULL)
        __x->__left_->__set_parent(__x);
    __y->__parent_ = __x->__parent_;
    if (__tree_is_left_child(__x))
        __x->__parent_->__left_ = __y;
    else
        __x->__get_parent()->__right_ = __y;
    __y->__right_ = __x;
    __x->__set_parent(__y);
}

// Effects:  Rebalances __root after attaching __x to a leaf.
// Precondition:  __root != nulptr && __x != NULL.
//                __x has no children.
//                __x == __root or == a direct or indirect child of __root.
//                If __x were to be unlinked from __root (setting __root to
//                  NULL if __root == __x), __tree_invariant(__root) == true.
// Postcondition: __tree_invariant(end_node->__left_) == true.  end_node->__left_
//                may be different than the value passed in as __root.
template <class _NodePtr>
void
__tree_balance_after_insert(_NodePtr __root, _NodePtr __x) throw()
{
    __x->__is_black_ = __x == __root;
    while (__x != __root and not __x->__get_parent()->__is_black_)
    {
        // __x->__parent_ != __root because __x->__parent_->__is_black == false
        if (__tree_is_left_child(__x->__get_parent()))
        {
            _NodePtr __y = __x->__get_parent()->__get_parent()->__right_;
            if (__y != NULL and not __y->__is_black_)
            {
                __x = __x->__get_parent();
                __x->__is_black_ = true;
                __x = __x->__get_parent();
                __x->__is_black_ = __x == __root;
                __y->__is_black_ = true;
            }
            else
            {
                if (!__tree_is_left_child(__x))
                {
                    __x = __x->__get_parent();
                    __tree_left_rotate(__x);
                }
                __x = __x->__get_parent();
                __x->__is_black_ = true;
                __x = __x->__get_parent();
                __x->__is_black_ = false;
                __tree_right_rotate(__x);
                break;
            }
        }
        else
        {
            _NodePtr __y = __x->__get_parent()->__parent_->__left_;
            if (__y != NULL and not __y->__is_black_)
            {
                __x = __x->__get_parent();
                __x->__is_black_ = true;
                __x = __x->__get_parent();
                __x->__is_black_ = __x == __root;
                __y->__is_black_ = true;
            }
            else
            {
                if (__tree_is_left_child(__x))
                {
                    __x = __x->__get_parent();
                    __tree_right_rotate(__x);
                }
                __x = __x->__get_parent();
                __x->__is_black_ = true;
                __x = __x->__get_parent();
                __x->__is_black_ = false;
                __tree_left_rotate(__x);
                break;
            }
        }
    }
}

// Precondition:  __root != NULL && __z != NULL.
//                __tree_invariant(__root) == true.
//                __z == __root or == a direct or indirect child of __root.
// Effects:  unlinks __z from the tree rooted at __root, rebalancing as needed.
// Postcondition: __tree_invariant(end_node->__left_) == true && end_node->__left_
//                nor any of its children refer to __z.  end_node->__left_
//                may be different than the value passed in as __root.
template <class _NodePtr>
void
__tree_remove(_NodePtr __root, _NodePtr __z) throw()
{
    // __z will be removed from the tree.  Client still needs to destruct/deallocate it
    // __y is either __z, or if __z has two children, __tree_next(__z).
    // __y will have at most one child.
    // __y will be the initial hole in the tree (make the hole at a leaf)
    _NodePtr __y = (__z->__left_ == NULL || __z->__right_ == NULL) ?
                    __z : __tree_next(__z);
    // __x is __y's possibly null single child
    _NodePtr __x = __y->__left_ != NULL ? __y->__left_ : __y->__right_;
    // __w is __x's possibly null uncle (will become __x's sibling)
    _NodePtr __w = NULL;
    // link __x to __y's parent, and find __w
    if (__x != NULL)
        __x->__parent_ = __y->__parent_;
    if (__tree_is_left_child(__y))
    {
        __y->__parent_->__left_ = __x;
        if (__y != __root)
            __w = __y->__get_parent()->__right_;
        else
            __root = __x;  // __w == NULL
    }
    else
    {
        __y->__get_parent()->__right_ = __x;
        // __y can't be root if it is a right child
        __w = __y->__parent_->__left_;
    }
    bool __removed_black = __y->__is_black_;
    // If we didn't remove __z, do so now by splicing in __y for __z,
    //    but copy __z's color.  This does not impact __x or __w.
    if (__y != __z)
    {
        // __z->__left_ != nulptr but __z->__right_ might == __x == NULL
        __y->__parent_ = __z->__parent_;
        if (__tree_is_left_child(__z))
            __y->__parent_->__left_ = __y;
        else
            __y->__get_parent()->__right_ = __y;
        __y->__left_ = __z->__left_;
        __y->__left_->__set_parent(__y);
        __y->__right_ = __z->__right_;
        if (__y->__right_ != NULL)
            __y->__right_->__set_parent(__y);
        __y->__is_black_ = __z->__is_black_;
        if (__root == __z)
            __root = __y;
    }
    // There is no need to rebalance if we removed a red, or if we removed
    //     the last node.
    if (__removed_black && __root != NULL)
    {
        // Rebalance:
        // __x has an implicit black color (transferred from the removed __y)
        //    associated with it, no matter what its color is.
        // If __x is __root (in which case it can't be null), it is supposed
        //    to be black anyway, and if it is doubly black, then the double
        //    can just be ignored.
        // If __x is red (in which case it can't be null), then it can absorb
        //    the implicit black just by setting its color to black.
        // Since __y was black and only had one child (which __x points to), __x
        //   is either red with no children, else null, otherwise __y would have
        //   different black heights under left and right pointers.
        // if (__x == __root || __x != NULL and not __x->__is_black_)
        if (__x != NULL)
            __x->__is_black_ = true;
        else
        {
            //  Else __x isn't root, and is "doubly black", even though it may
            //     be null.  __w can not be null here, else the parent would
            //     see a black height >= 2 on the __x side and a black height
            //     of 1 on the __w side (__w must be a non-null black or a red
            //     with a non-null black child).
            while (true)
            {
                if (!__tree_is_left_child(__w))  // if x is left child
                {
                    if (!__w->__is_black_)
                    {
                        __w->__is_black_ = true;
                        __w->__get_parent()->__is_black_ = false;
                        __tree_left_rotate(__w->__get_parent());
                        // __x is still valid
                        // reset __root only if necessary
                        if (__root == __w->__left_)
                            __root = __w;
                        // reset sibling, and it still can't be null
                        __w = __w->__left_->__right_;
                    }
                    // __w->__is_black_ is now true, __w may have null children
                    if ((__w->__left_  == NULL || __w->__left_->__is_black_) &&
                        (__w->__right_ == NULL || __w->__right_->__is_black_))
                    {
                        __w->__is_black_ = false;
                        __x = __w->__get_parent();
                        // __x can no longer be null
                        if (__x == __root || !__x->__is_black_)
                        {
                            __x->__is_black_ = true;
                            break;
                        }
                        // reset sibling, and it still can't be null
                        __w = __tree_is_left_child(__x) ?
                                    __x->__get_parent()->__right_ :
                                    __x->__parent_->__left_;
                        // continue;
                    }
                    else  // __w has a red child
                    {
                        if (__w->__right_ == NULL || __w->__right_->__is_black_)
                        {
                            // __w left child is non-null and red
                            __w->__left_->__is_black_ = true;
                            __w->__is_black_ = false;
                            __tree_right_rotate(__w);
                            // __w is known not to be root, so root hasn't changed
                            // reset sibling, and it still can't be null
                            __w = __w->__get_parent();
                        }
                        // __w has a right red child, left child may be null
                        __w->__is_black_ = __w->__get_parent()->__is_black_;
                        __w->__get_parent()->__is_black_ = true;
                        __w->__right_->__is_black_ = true;
                        __tree_left_rotate(__w->__get_parent());
                        break;
                    }
                }
                else
                {
                    if (!__w->__is_black_)
                    {
                        __w->__is_black_ = true;
                        __w->__get_parent()->__is_black_ = false;
                        __tree_right_rotate(__w->__get_parent());
                        // __x is still valid
                        // reset __root only if necessary
                        if (__root == __w->__right_)
                            __root = __w;
                        // reset sibling, and it still can't be null
                        __w = __w->__right_->__left_;
                    }
                    // __w->__is_black_ is now true, __w may have null children
                    if ((__w->__left_  == NULL || __w->__left_->__is_black_) &&
                        (__w->__right_ == NULL || __w->__right_->__is_black_))
                    {
                        __w->__is_black_ = false;
                        __x = __w->__get_parent();
                        // __x can no longer be null
                        if (!__x->__is_black_ || __x == __root)
                        {
                            __x->__is_black_ = true;
                            break;
                        }
                        // reset sibling, and it still can't be null
                        __w = __tree_is_left_child(__x) ?
                                    __x->__get_parent()->__right_ :
                                    __x->__parent_->__left_;
                        // continue;
                    }
                    else  // __w has a red child
                    {
                        if (__w->__left_ == NULL || __w->__left_->__is_black_)
                        {
                            // __w right child is non-null and red
                            __w->__right_->__is_black_ = true;
                            __w->__is_black_ = false;
                            __tree_left_rotate(__w);
                            // __w is known not to be root, so root hasn't changed
                            // reset sibling, and it still can't be null
                            __w = __w->__get_parent();
                        }
                        // __w has a left red child, right child may be null
                        __w->__is_black_ = __w->__get_parent()->__is_black_;
                        __w->__get_parent()->__is_black_ = true;
                        __w->__left_->__is_black_ = true;
                        __tree_right_rotate(__w->__get_parent());
                        break;
                    }
                }
            }
        }
    }
}

// node traits

template <class _VoidPtr>
struct __tree_node_base_types {
  typedef _VoidPtr                                               __void_pointer;

  typedef __tree_node_base<__void_pointer>                      __node_base_type;
  typedef typename __rebind_pointer<_VoidPtr, __node_base_type>::type
                                                             __node_base_pointer;

  typedef __tree_end_node<__node_base_pointer>                  __end_node_type;
  typedef typename __rebind_pointer<_VoidPtr, __end_node_type>::type
                                                             __end_node_pointer;
  typedef typename ft::conditional<
      is_pointer<__end_node_pointer>::value,
        __end_node_pointer,
        __node_base_pointer>::type __parent_pointer;

private:
  static_assert((is_same<typename pointer_traits<_VoidPtr>::element_type, void>::value),
                  "_VoidPtr does not point to unqualified void type");
};

template <class _Tp, class _AllocPtr, class _KVTypes = __tree_key_value_types<_Tp>,
         bool = _KVTypes::__is_map>
struct __tree_map_pointer_types {};

template <class _Tp, class _AllocPtr, class _KVTypes>
struct __tree_map_pointer_types<_Tp, _AllocPtr, _KVTypes, true> {
  typedef typename _KVTypes::__map_value_type   _Mv;
  typedef typename __rebind_pointer<_AllocPtr, _Mv>::type
                                                       __map_value_type_pointer;
  typedef typename __rebind_pointer<_AllocPtr, const _Mv>::type
                                                 __const_map_value_type_pointer;
};

template <class _NodePtr, class _NodeT = typename pointer_traits<_NodePtr>::element_type>
struct __tree_node_types;

template <class _NodePtr, class _Tp, class _VoidPtr>
struct __tree_node_types<_NodePtr, __tree_node<_Tp, _VoidPtr> >
    : public __tree_node_base_types<_VoidPtr>,
             __tree_key_value_types<_Tp>,
             __tree_map_pointer_types<_Tp, _VoidPtr>
{
  typedef __tree_node_base_types<_VoidPtr> __base;
  typedef __tree_key_value_types<_Tp>      __key_base;
  typedef __tree_map_pointer_types<_Tp, _VoidPtr> __map_pointer_base;
public:

  typedef typename pointer_traits<_NodePtr>::element_type       __node_type;
  typedef _NodePtr                                              __node_pointer;

  typedef _Tp                                                 __node_value_type;
  typedef typename __rebind_pointer<_VoidPtr, __node_value_type>::type
                                                      __node_value_type_pointer;
  typedef typename __rebind_pointer<_VoidPtr, const __node_value_type>::type
                                                __const_node_value_type_pointer;
#if defined(_LIBCPP_ABI_TREE_REMOVE_NODE_POINTER_UB)
  typedef typename __base::__end_node_pointer __iter_pointer;
#else
  typedef typename ft::conditional<
      is_pointer<__node_pointer>::value,
        typename __base::__end_node_pointer,
        __node_pointer>::type __iter_pointer;
#endif
private:
    static_assert(!is_const<__node_type>::value,
                "_NodePtr should never be a pointer to const");
    static_assert((is_same<typename __rebind_pointer<_VoidPtr, __node_type>::type,
                          _NodePtr>::value), "_VoidPtr does not rebind to _NodePtr.");
};

template <class _ValueTp, class _VoidPtr>
struct __make_tree_node_types {
  typedef typename __rebind_pointer<_VoidPtr, __tree_node<_ValueTp, _VoidPtr> >::type
                                                                        _NodePtr;
  typedef __tree_node_types<_NodePtr> type;
};

// node

template <class _VoidPtr>
class __tree_node_base
    : public __tree_node_base_types<_VoidPtr>::__end_node_type
{
    typedef __tree_node_base_types<_VoidPtr> _NodeBaseTypes;

public:
    typedef typename _NodeBaseTypes::__node_base_pointer pointer;
    typedef typename _NodeBaseTypes::__parent_pointer __parent_pointer;

    pointer          __right_;
    __parent_pointer __parent_;
    bool __is_black_;

    
    pointer __get_parent() const { return static_cast<pointer>(__parent_);}

    
    void __set_parent(pointer __p) {
        __parent_ = static_cast<__parent_pointer>(__p);
    }

private:
  ~__tree_node_base() _LIBCPP_EQUAL_DELETE;
  __tree_node_base(__tree_node_base const&) _LIBCPP_EQUAL_DELETE;
  __tree_node_base& operator=(__tree_node_base const&) _LIBCPP_EQUAL_DELETE;
};

template <class _Tp, class _VoidPtr>
class __tree_node
    : public __tree_node_base<_VoidPtr>
{
public:
    typedef _Tp __node_value_type;

    __node_value_type __value_;

private:
  ~__tree_node() _LIBCPP_EQUAL_DELETE;
  __tree_node(__tree_node const&) _LIBCPP_EQUAL_DELETE;
  __tree_node& operator=(__tree_node const&) _LIBCPP_EQUAL_DELETE;
};


template <class _Allocator>
class __tree_node_destructor
{
    typedef _Allocator                                      allocator_type;
    typedef allocator_traits<allocator_type>                __alloc_traits;

public:
    typedef typename __alloc_traits::pointer                pointer;
private:
    typedef __tree_node_types<pointer> _NodeTypes;
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
        if (__value_constructed)
            __alloc_traits::destroy(__na_, _NodeTypes::__get_ptr(__p->__value_));
        if (__p)
            __alloc_traits::deallocate(__na_, __p, 1);
    }

    template <class> friend class __map_node_destructor;
};

template<class _Tp, class _Compare>
int __diagnose_non_const_comparator();

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
    __compressed_pair<__end_node_t, __node_allocator>  __pair1_;
    __compressed_pair<size_type, value_compare>        __pair3_;

public:
    
    __iter_pointer __end_node() throw()
    {
        return static_cast<__iter_pointer>(
                pointer_traits<__end_node_ptr>::pointer_to(__pair1_.first())
        );
    }
    
    __iter_pointer __end_node() const throw()
    {
        return static_cast<__iter_pointer>(
            pointer_traits<__end_node_ptr>::pointer_to(
                const_cast<__end_node_t&>(__pair1_.first())
            )
        );
    }
    
          __node_allocator& __node_alloc() throw() {return __pair1_.second();}
private:
    
    const __node_allocator& __node_alloc() const throw()
        {return __pair1_.second();}
    
          __iter_pointer& __begin_node() throw() {return __begin_node_;}
    
    const __iter_pointer& __begin_node() const throw() {return __begin_node_;}
public:
    
    allocator_type __alloc() const throw()
        {return allocator_type(__node_alloc());}
private:
    
          size_type& size() throw() {return __pair3_.first();}
public:
    
    const size_type& size() const throw() {return __pair3_.first();}
    
          value_compare& value_comp() throw() {return __pair3_.second();}
    
    const value_compare& value_comp() const throw()
        {return __pair3_.second();}
public:

    __node_pointer __root() const throw()
        {return static_cast<__node_pointer>(__end_node()->__left_);}

    __node_base_pointer* __root_ptr() const throw() {
        return &__end_node()->__left_;
    }

    typedef __tree_iterator<value_type, __node_pointer, difference_type>             iterator;
    typedef __tree_const_iterator<value_type, __node_pointer, difference_type> const_iterator;

    explicit __tree(const value_compare& __comp);
    explicit __tree(const allocator_type& __a);
    __tree(const value_compare& __comp, const allocator_type& __a);
    __tree(const __tree& __t);
    __tree& operator=(const __tree& __t);

    ~__tree();

    
          iterator begin()  throw() {return       iterator(__begin_node());}
    
    const_iterator begin() const throw() {return const_iterator(__begin_node());}
    
          iterator end() throw() {return       iterator(__end_node());}
    
    const_iterator end() const throw() {return const_iterator(__end_node());}

    
    size_type max_size() const throw()
        {return std::min<size_type>(
                __node_traits::max_size(__node_alloc()),
                numeric_limits<difference_type >::max());}

    void clear() throw();

    void swap(__tree& __t);

    template <class _Key, class _Args>
    
    pair<iterator, bool> __emplace_unique_key_args(_Key const&, _Args& __args);
    template <class _Key, class _Args>
    
    iterator __emplace_hint_unique_key_args(const_iterator, _Key const&, _Args&);
    
    pair<iterator, bool> __insert_unique(const __container_value_type& __v) {
        return __emplace_unique_key_args(_NodeTypes::__get_key(__v), __v);
    }

    
    iterator __insert_unique(const_iterator __p, const __container_value_type& __v) {
        return __emplace_hint_unique_key_args(__p, _NodeTypes::__get_key(__v), __v);
    }
    
    pair<iterator, bool> __node_insert_unique(__node_pointer __nd);
    
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
            {return __lower_bound(__v, __root(), __end_node());}
    template <class _Key>
        iterator __lower_bound(const _Key& __v,
                               __node_pointer __root,
                               __iter_pointer __result);
    template <class _Key>
        
        const_iterator lower_bound(const _Key& __v) const
            {return __lower_bound(__v, __root(), __end_node());}
    template <class _Key>
        const_iterator __lower_bound(const _Key& __v,
                                     __node_pointer __root,
                                     __iter_pointer __result) const;
    template <class _Key>
        
        iterator upper_bound(const _Key& __v)
            {return __upper_bound(__v, __root(), __end_node());}
    template <class _Key>
        iterator __upper_bound(const _Key& __v,
                               __node_pointer __root,
                               __iter_pointer __result);
    template <class _Key>
        
        const_iterator upper_bound(const _Key& __v) const
            {return __upper_bound(__v, __root(), __end_node());}
    template <class _Key>
        const_iterator __upper_bound(const _Key& __v,
                                     __node_pointer __root,
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
    __node_base_pointer&
        __find_leaf_low(__parent_pointer& __parent, const key_type& __v);
    __node_base_pointer&
        __find_leaf_high(__parent_pointer& __parent, const key_type& __v);
    __node_base_pointer&
        __find_leaf(const_iterator __hint,
                    __parent_pointer& __parent, const key_type& __v);
    // FIXME: Make this function const qualified. Unfortunetly doing so
    // breaks existing code which uses non-const callable comparators.
    template <class _Key>
    __node_base_pointer&
        __find_equal(__parent_pointer& __parent, const _Key& __v);
    template <class _Key>
     __node_base_pointer&
    __find_equal(__parent_pointer& __parent, const _Key& __v) const {
      return const_cast<__tree*>(this)->__find_equal(__parent, __v);
    }
    template <class _Key>
    __node_base_pointer&
        __find_equal(const_iterator __hint, __parent_pointer& __parent,
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

    void __move_assign_alloc(__tree& __t)
    {
        __move_assign_alloc(__t, ft::integral_constant<bool,
             __node_traits::propagate_on_container_move_assignment::value>());
    }

    void __move_assign_alloc(__tree& __t, true_type)
        {__node_alloc() = __t.__node_alloc();}
    
    void __move_assign_alloc(__tree&, false_type) throw() {}

    template <class, class, class, class> friend class map;
};

template <class _Tp, class _Compare, class _Allocator>
__tree<_Tp, _Compare, _Allocator>::__tree(const value_compare& __comp) 
    : __pair3_(0, __comp)
{
    __begin_node() = __end_node();
}

template <class _Tp, class _Compare, class _Allocator>
__tree<_Tp, _Compare, _Allocator>::__tree(const allocator_type& __a)
    : __begin_node_(__iter_pointer()),
      __pair1_(__second_tag(), __node_allocator(__a)),
      __pair3_(0)
{
    __begin_node() = __end_node();
}

template <class _Tp, class _Compare, class _Allocator>
__tree<_Tp, _Compare, _Allocator>::__tree(const value_compare& __comp,
                                           const allocator_type& __a)
    : __begin_node_(__iter_pointer()),
      __pair1_(__second_tag(), __node_allocator(__a)),
      __pair3_(0, __comp)
{
    __begin_node() = __end_node();
}

template <class _Tp, class _Compare, class _Allocator>
__tree<_Tp, _Compare, _Allocator>&
__tree<_Tp, _Compare, _Allocator>::operator=(const __tree& __t)
{
    if (this != &__t)
    {
        value_comp() = __t.value_comp();
        __copy_assign_alloc(__t);
        __assign_multi(__t.begin(), __t.end());
    }
    return *this;
}


template <class _Tp, class _Compare, class _Allocator>
__tree<_Tp, _Compare, _Allocator>::__tree(const __tree& __t)
    : __begin_node_(__iter_pointer()),
      __pair1_(__second_tag(), __node_traits::select_on_container_copy_construction(__t.__node_alloc())),
      __pair3_(0, __t.value_comp())
{
    __begin_node() = __end_node();
}

template <class _Tp, class _Compare, class _Allocator>
__tree<_Tp, _Compare, _Allocator>::~__tree()
{
    static_assert((is_copy_constructible<value_compare>::value),
                 "Comparator must be copy-constructible.");
  destroy(__root());
}

template <class _Tp, class _Compare, class _Allocator>
void
__tree<_Tp, _Compare, _Allocator>::destroy(__node_pointer __nd) throw()
{
    if (__nd != NULL)
    {
        destroy(static_cast<__node_pointer>(__nd->__left_));
        destroy(static_cast<__node_pointer>(__nd->__right_));
        __node_allocator& __na = __node_alloc();
        __node_traits::destroy(__na, _NodeTypes::__get_ptr(__nd->__value_));
        __node_traits::deallocate(__na, __nd, 1);
    }
}

template <class _Tp, class _Compare, class _Allocator>
void
__tree<_Tp, _Compare, _Allocator>::swap(__tree& __t)
{
	using std::swap;
    swap(__begin_node_, __t.__begin_node_);
    swap(__pair1_.first(), __t.__pair1_.first());
    __swap_allocator(__node_alloc(), __t.__node_alloc());
    __pair3_.swap(__t.__pair3_);
    if (size() == 0)
        __begin_node() = __end_node();
    else
        __end_node()->__left_->__parent_ = static_cast<__parent_pointer>(__end_node());
    if (__t.size() == 0)
        __t.__begin_node() = __t.__end_node();
    else
        __t.__end_node()->__left_->__parent_ = static_cast<__parent_pointer>(__t.__end_node());
}

template <class _Tp, class _Compare, class _Allocator>
void
__tree<_Tp, _Compare, _Allocator>::clear() throw()
{
    destroy(__root());
    size() = 0;
    __begin_node() = __end_node();
    __end_node()->__left_ = NULL;
}

// Find lower_bound place to insert
// Set __parent to parent of null leaf
// Return reference to null leaf
template <class _Tp, class _Compare, class _Allocator>
typename __tree<_Tp, _Compare, _Allocator>::__node_base_pointer&
__tree<_Tp, _Compare, _Allocator>::__find_leaf_low(__parent_pointer& __parent,
                                                   const key_type& __v)
{
    __node_pointer __nd = __root();
    if (__nd != NULL)
    {
        while (true)
        {
            if (value_comp()(__nd->__value_, __v))
            {
                if (__nd->__right_ != NULL)
                    __nd = static_cast<__node_pointer>(__nd->__right_);
                else
                {
                    __parent = static_cast<__parent_pointer>(__nd);
                    return __nd->__right_;
                }
            }
            else
            {
                if (__nd->__left_ != NULL)
                    __nd = static_cast<__node_pointer>(__nd->__left_);
                else
                {
                    __parent = static_cast<__parent_pointer>(__nd);
                    return __parent->__left_;
                }
            }
        }
    }
    __parent = static_cast<__parent_pointer>(__end_node());
    return __parent->__left_;
}

// Find upper_bound place to insert
// Set __parent to parent of null leaf
// Return reference to null leaf
template <class _Tp, class _Compare, class _Allocator>
typename __tree<_Tp, _Compare, _Allocator>::__node_base_pointer&
__tree<_Tp, _Compare, _Allocator>::__find_leaf_high(__parent_pointer& __parent,
                                                    const key_type& __v)
{
    __node_pointer __nd = __root();
    if (__nd != NULL)
    {
        while (true)
        {
            if (value_comp()(__v, __nd->__value_))
            {
                if (__nd->__left_ != NULL)
                    __nd = static_cast<__node_pointer>(__nd->__left_);
                else
                {
                    __parent = static_cast<__parent_pointer>(__nd);
                    return __parent->__left_;
                }
            }
            else
            {
                if (__nd->__right_ != NULL)
                    __nd = static_cast<__node_pointer>(__nd->__right_);
                else
                {
                    __parent = static_cast<__parent_pointer>(__nd);
                    return __nd->__right_;
                }
            }
        }
    }
    __parent = static_cast<__parent_pointer>(__end_node());
    return __parent->__left_;
}

// Find leaf place to insert closest to __hint
// First check prior to __hint.
// Next check after __hint.
// Next do O(log N) search.
// Set __parent to parent of null leaf
// Return reference to null leaf
template <class _Tp, class _Compare, class _Allocator>
typename __tree<_Tp, _Compare, _Allocator>::__node_base_pointer&
__tree<_Tp, _Compare, _Allocator>::__find_leaf(const_iterator __hint,
                                               __parent_pointer& __parent,
                                               const key_type& __v)
{
    if (__hint == end() || !value_comp()(*__hint, __v))  // check before
    {
        // __v <= *__hint
        const_iterator __prior = __hint;
        if (__prior == begin() || !value_comp()(__v, *--__prior))
        {
            // *prev(__hint) <= __v <= *__hint
            if (__hint.__ptr_->__left_ == NULL)
            {
                __parent = static_cast<__parent_pointer>(__hint.__ptr_);
                return __parent->__left_;
            }
            else
            {
                __parent = static_cast<__parent_pointer>(__prior.__ptr_);
                return static_cast<__node_base_pointer>(__prior.__ptr_)->__right_;
            }
        }
        // __v < *prev(__hint)
        return __find_leaf_high(__parent, __v);
    }
    // else __v > *__hint
    return __find_leaf_low(__parent, __v);
}

// Find place to insert if __v doesn't exist
// Set __parent to parent of null leaf
// Return reference to null leaf
// If __v exists, set parent to node of __v and return reference to node of __v
template <class _Tp, class _Compare, class _Allocator>
template <class _Key>
typename __tree<_Tp, _Compare, _Allocator>::__node_base_pointer&
__tree<_Tp, _Compare, _Allocator>::__find_equal(__parent_pointer& __parent,
                                                const _Key& __v)
{
    __node_pointer __nd = __root();
    __node_base_pointer* __nd_ptr = __root_ptr();
    if (__nd != NULL)
    {
        while (true)
        {
            if (value_comp()(__v, __nd->__value_))
            {
                if (__nd->__left_ != NULL) {
                    __nd_ptr = &__nd->__left_;
                    __nd = static_cast<__node_pointer>(__nd->__left_);
                } else {
                    __parent = static_cast<__parent_pointer>(__nd);
                    return __parent->__left_;
                }
            }
            else if (value_comp()(__nd->__value_, __v))
            {
                if (__nd->__right_ != NULL) {
                    __nd_ptr = &__nd->__right_;
                    __nd = static_cast<__node_pointer>(__nd->__right_);
                } else {
                    __parent = static_cast<__parent_pointer>(__nd);
                    return __nd->__right_;
                }
            }
            else
            {
                __parent = static_cast<__parent_pointer>(__nd);
                return *__nd_ptr;
            }
        }
    }
    __parent = static_cast<__parent_pointer>(__end_node());
    return __parent->__left_;
}

// Find place to insert if __v doesn't exist
// First check prior to __hint.
// Next check after __hint.
// Next do O(log N) search.
// Set __parent to parent of null leaf
// Return reference to null leaf
// If __v exists, set parent to node of __v and return reference to node of __v
template <class _Tp, class _Compare, class _Allocator>
template <class _Key>
typename __tree<_Tp, _Compare, _Allocator>::__node_base_pointer&
__tree<_Tp, _Compare, _Allocator>::__find_equal(const_iterator __hint,
                                                __parent_pointer& __parent,
                                                __node_base_pointer& __dummy,
                                                const _Key& __v)
{
    if (__hint == end() || value_comp()(__v, *__hint))  // check before
    {
        // __v < *__hint
        const_iterator __prior = __hint;
        if (__prior == begin() || value_comp()(*--__prior, __v))
        {
            // *prev(__hint) < __v < *__hint
            if (__hint.__ptr_->__left_ == NULL)
            {
                __parent = static_cast<__parent_pointer>(__hint.__ptr_);
                return __parent->__left_;
            }
            else
            {
                __parent = static_cast<__parent_pointer>(__prior.__ptr_);
                return static_cast<__node_base_pointer>(__prior.__ptr_)->__right_;
            }
        }
        // __v <= *prev(__hint)
        return __find_equal(__parent, __v);
    }
    else if (value_comp()(*__hint, __v))  // check after
    {
        // *__hint < __v
        const_iterator __next = ++__hint;
        if (__next == end() || value_comp()(__v, *__next))
        {
            // *__hint < __v < *_VSTD::next(__hint)
            if (__hint.__get_np()->__right_ == NULL)
            {
                __parent = static_cast<__parent_pointer>(__hint.__ptr_);
                return static_cast<__node_base_pointer>(__hint.__ptr_)->__right_;
            }
            else
            {
                __parent = static_cast<__parent_pointer>(__next.__ptr_);
                return __parent->__left_;
            }
        }
        // *next(__hint) <= __v
        return __find_equal(__parent, __v);
    }
    // else __v == *__hint
    __parent = static_cast<__parent_pointer>(__hint.__ptr_);
    __dummy = static_cast<__node_base_pointer>(__hint.__ptr_);
    return __dummy;
}

template <class _Tp, class _Compare, class _Allocator>
void __tree<_Tp, _Compare, _Allocator>::__insert_node_at(
    __parent_pointer __parent, __node_base_pointer& __child,
    __node_base_pointer __new_node) throw()
{
    __new_node->__left_   = NULL;
    __new_node->__right_  = NULL;
    __new_node->__parent_ = __parent;
    // __new_node->__is_black_ is initialized in __tree_balance_after_insert
    __child = __new_node;
    if (__begin_node()->__left_ != NULL)
        __begin_node() = static_cast<__iter_pointer>(__begin_node()->__left_);
    __tree_balance_after_insert(__end_node()->__left_, __child);
    ++size();
}

template <class _Tp, class _Compare, class _Allocator>
template <class _Key, class _Args>
pair<typename __tree<_Tp, _Compare, _Allocator>::iterator, bool>
__tree<_Tp, _Compare, _Allocator>::__emplace_unique_key_args(_Key const& __k, _Args& __args)
{
    __parent_pointer __parent;
    __node_base_pointer& __child = __find_equal(__parent, __k);
    __node_pointer __r = static_cast<__node_pointer>(__child);
    bool __inserted = false;
    if (__child == NULL)
    {
        __node_holder __h = __construct_node(__args);
        __insert_node_at(__parent, __child, static_cast<__node_base_pointer>(__h.get()));
        __r = __h.release();
        __inserted = true;
    }
    return pair<iterator, bool>(iterator(__r), __inserted);
}


template <class _Tp, class _Compare, class _Allocator>
template <class _Key, class _Args>
typename __tree<_Tp, _Compare, _Allocator>::iterator
__tree<_Tp, _Compare, _Allocator>::__emplace_hint_unique_key_args(
    const_iterator __p, _Key const& __k, _Args& __args)
{
    __parent_pointer __parent;
    __node_base_pointer __dummy;
    __node_base_pointer& __child = __find_equal(__p, __parent, __dummy, __k);
    __node_pointer __r = static_cast<__node_pointer>(__child);
    if (__child == NULL)
    {
        __node_holder __h = __construct_node(__args);
        __insert_node_at(__parent, __child, static_cast<__node_base_pointer>(__h.get()));
        __r = __h.release();
    }
    return iterator(__r);
}



template <class _Tp, class _Compare, class _Allocator>
typename __tree<_Tp, _Compare, _Allocator>::__node_holder
__tree<_Tp, _Compare, _Allocator>::__construct_node(const __container_value_type& __v)
{
    __node_allocator& __na = __node_alloc();
    __node_holder __h(__node_traits::allocate(__na, 1), _Dp(__na));
    __node_traits::construct(__na, _NodeTypes::__get_ptr(__h->__value_), __v);
    __h.get_deleter().__value_constructed = true;
    return _LIBCPP_EXPLICIT_MOVE(__h);  // explicitly moved for C++03
}

template <class _Tp, class _Compare, class _Allocator>
pair<typename __tree<_Tp, _Compare, _Allocator>::iterator, bool>
__tree<_Tp, _Compare, _Allocator>::__node_insert_unique(__node_pointer __nd)
{
    __parent_pointer __parent;
    __node_base_pointer& __child = __find_equal(__parent, __nd->__value_);
    __node_pointer __r = static_cast<__node_pointer>(__child);
    bool __inserted = false;
    if (__child == NULL)
    {
        __insert_node_at(__parent, __child, static_cast<__node_base_pointer>(__nd));
        __r = __nd;
        __inserted = true;
    }
    return pair<iterator, bool>(iterator(__r), __inserted);
}

template <class _Tp, class _Compare, class _Allocator>
typename __tree<_Tp, _Compare, _Allocator>::iterator
__tree<_Tp, _Compare, _Allocator>::__node_insert_unique(const_iterator __p,
                                                        __node_pointer __nd)
{
    __parent_pointer __parent;
    __node_base_pointer __dummy;
    __node_base_pointer& __child = __find_equal(__p, __parent, __nd->__value_);
    __node_pointer __r = static_cast<__node_pointer>(__child);
    if (__child == NULL)
    {
        __insert_node_at(__parent, __child, static_cast<__node_base_pointer>(__nd));
        __r = __nd;
    }
    return iterator(__r);
}

template <class _Tp, class _Compare, class _Allocator>
typename __tree<_Tp, _Compare, _Allocator>::iterator
__tree<_Tp, _Compare, _Allocator>::__remove_node_pointer(__node_pointer __ptr) throw()
{
    iterator __r(__ptr);
    ++__r;
    if (__begin_node() == __ptr)
        __begin_node() = __r.__ptr_;
    --size();
    __tree_remove(__end_node()->__left_,
                  static_cast<__node_base_pointer>(__ptr));
    return __r;
}


template <class _Tp, class _Compare, class _Allocator>
typename __tree<_Tp, _Compare, _Allocator>::iterator
__tree<_Tp, _Compare, _Allocator>::erase(const_iterator __p)
{
    __node_pointer __np = __p.__get_np();
    iterator __r = __remove_node_pointer(__np);
    __node_allocator& __na = __node_alloc();
    __node_traits::destroy(__na, _NodeTypes::__get_ptr(
        const_cast<__node_value_type&>(*__p)));
    __node_traits::deallocate(__na, __np, 1);
    return __r;
}

template <class _Tp, class _Compare, class _Allocator>
typename __tree<_Tp, _Compare, _Allocator>::iterator
__tree<_Tp, _Compare, _Allocator>::erase(const_iterator __f, const_iterator __l)
{
    while (__f != __l)
        __f = erase(__f);
    return iterator(__l.__ptr_);
}

template <class _Tp, class _Compare, class _Allocator>
template <class _Key>
typename __tree<_Tp, _Compare, _Allocator>::size_type
__tree<_Tp, _Compare, _Allocator>::__erase_unique(const _Key& __k)
{
    iterator __i = find(__k);
    if (__i == end())
        return 0;
    erase(__i);
    return 1;
}

template <class _Tp, class _Compare, class _Allocator>
template <class _Key>
typename __tree<_Tp, _Compare, _Allocator>::iterator
__tree<_Tp, _Compare, _Allocator>::find(const _Key& __v)
{
    iterator __p = __lower_bound(__v, __root(), __end_node());
    if (__p != end() and not value_comp()(__v, *__p))
        return __p;
    return end();
}

template <class _Tp, class _Compare, class _Allocator>
template <class _Key>
typename __tree<_Tp, _Compare, _Allocator>::const_iterator
__tree<_Tp, _Compare, _Allocator>::find(const _Key& __v) const
{
    const_iterator __p = __lower_bound(__v, __root(), __end_node());
    if (__p != end() and not value_comp()(__v, *__p))
        return __p;
    return end();
}

template <class _Tp, class _Compare, class _Allocator>
template <class _Key>
typename __tree<_Tp, _Compare, _Allocator>::size_type
__tree<_Tp, _Compare, _Allocator>::__count_unique(const _Key& __k) const
{
    __node_pointer __rt = __root();
    while (__rt != NULL)
    {
        if (value_comp()(__k, __rt->__value_))
        {
            __rt = static_cast<__node_pointer>(__rt->__left_);
        }
        else if (value_comp()(__rt->__value_, __k))
            __rt = static_cast<__node_pointer>(__rt->__right_);
        else
            return 1;
    }
    return 0;
}

template <class _Tp, class _Compare, class _Allocator>
template <class _Key>
typename __tree<_Tp, _Compare, _Allocator>::iterator
__tree<_Tp, _Compare, _Allocator>::__lower_bound(const _Key& __v,
                                                 __node_pointer __root,
                                                 __iter_pointer __result)
{
    while (__root != NULL)
    {
        if (!value_comp()(__root->__value_, __v))
        {
            __result = static_cast<__iter_pointer>(__root);
            __root = static_cast<__node_pointer>(__root->__left_);
        }
        else
            __root = static_cast<__node_pointer>(__root->__right_);
    }
    return iterator(__result);
}

template <class _Tp, class _Compare, class _Allocator>
template <class _Key>
typename __tree<_Tp, _Compare, _Allocator>::const_iterator
__tree<_Tp, _Compare, _Allocator>::__lower_bound(const _Key& __v,
                                                 __node_pointer __root,
                                                 __iter_pointer __result) const
{
    while (__root != NULL)
    {
        if (!value_comp()(__root->__value_, __v))
        {
            __result = static_cast<__iter_pointer>(__root);
            __root = static_cast<__node_pointer>(__root->__left_);
        }
        else
            __root = static_cast<__node_pointer>(__root->__right_);
    }
    return const_iterator(__result);
}

template <class _Tp, class _Compare, class _Allocator>
template <class _Key>
typename __tree<_Tp, _Compare, _Allocator>::iterator
__tree<_Tp, _Compare, _Allocator>::__upper_bound(const _Key& __v,
                                                 __node_pointer __root,
                                                 __iter_pointer __result)
{
    while (__root != NULL)
    {
        if (value_comp()(__v, __root->__value_))
        {
            __result = static_cast<__iter_pointer>(__root);
            __root = static_cast<__node_pointer>(__root->__left_);
        }
        else
            __root = static_cast<__node_pointer>(__root->__right_);
    }
    return iterator(__result);
}

template <class _Tp, class _Compare, class _Allocator>
template <class _Key>
typename __tree<_Tp, _Compare, _Allocator>::const_iterator
__tree<_Tp, _Compare, _Allocator>::__upper_bound(const _Key& __v,
                                                 __node_pointer __root,
                                                 __iter_pointer __result) const
{
    while (__root != NULL)
    {
        if (value_comp()(__v, __root->__value_))
        {
            __result = static_cast<__iter_pointer>(__root);
            __root = static_cast<__node_pointer>(__root->__left_);
        }
        else
            __root = static_cast<__node_pointer>(__root->__right_);
    }
    return const_iterator(__result);
}

template <class _Tp, class _Compare, class _Allocator>
template <class _Key>
ft::pair<typename __tree<_Tp, _Compare, _Allocator>::iterator,
     typename __tree<_Tp, _Compare, _Allocator>::iterator>
__tree<_Tp, _Compare, _Allocator>::__equal_range_unique(const _Key& __k)
{
    typedef pair<iterator, iterator> _Pp;
    __iter_pointer __result = __end_node();
    __node_pointer __rt = __root();
    while (__rt != NULL)
    {
        if (value_comp()(__k, __rt->__value_))
        {
            __result = static_cast<__iter_pointer>(__rt);
            __rt = static_cast<__node_pointer>(__rt->__left_);
        }
        else if (value_comp()(__rt->__value_, __k))
            __rt = static_cast<__node_pointer>(__rt->__right_);
        else
            return _Pp(iterator(__rt),
                      iterator(
                          __rt->__right_ != NULL ?
                              static_cast<__iter_pointer>(__tree_min(__rt->__right_))
                            : __result));
    }
    return _Pp(iterator(__result), iterator(__result));
}

template <class _Tp, class _Compare, class _Allocator>
template <class _Key>
ft::pair<typename __tree<_Tp, _Compare, _Allocator>::const_iterator,
     typename __tree<_Tp, _Compare, _Allocator>::const_iterator>
__tree<_Tp, _Compare, _Allocator>::__equal_range_unique(const _Key& __k) const
{
    typedef pair<const_iterator, const_iterator> _Pp;
    __iter_pointer __result = __end_node();
    __node_pointer __rt = __root();
    while (__rt != NULL)
    {
        if (value_comp()(__k, __rt->__value_))
        {
            __result = static_cast<__iter_pointer>(__rt);
            __rt = static_cast<__node_pointer>(__rt->__left_);
        }
        else if (value_comp()(__rt->__value_, __k))
            __rt = static_cast<__node_pointer>(__rt->__right_);
        else
            return _Pp(const_iterator(__rt),
                      const_iterator(
                          __rt->__right_ != NULL ?
                              static_cast<__iter_pointer>(__tree_min(__rt->__right_))
                            : __result));
    }
    return _Pp(const_iterator(__result), const_iterator(__result));
}

template <class _Tp, class _Compare, class _Allocator>
typename __tree<_Tp, _Compare, _Allocator>::__node_holder
__tree<_Tp, _Compare, _Allocator>::remove(const_iterator __p) throw()
{
    __node_pointer __np = __p.__get_np();
    if (__begin_node() == __p.__ptr_)
    {
        if (__np->__right_ != NULL)
            __begin_node() = static_cast<__iter_pointer>(__np->__right_);
        else
            __begin_node() = static_cast<__iter_pointer>(__np->__parent_);
    }
    --size();
    __tree_remove(__end_node()->__left_,
                  static_cast<__node_base_pointer>(__np));
    return __node_holder(__np, _Dp(__node_alloc(), true));
}

};

#include "__tree_is_left_child.hpp"
#include "__tree_iterator.hpp"
#include "__tree_const_iterator.hpp"

#include "swap.hpp"

#endif // FT_TREE
