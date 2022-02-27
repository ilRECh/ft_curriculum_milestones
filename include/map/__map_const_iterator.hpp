#ifndef __MAP_CONST_ITERATOR_HPP
#define __MAP_CONST_ITERATOR_HPP

namespace ft {

template <class _TreeIterator>
class __map_const_iterator
{
    typedef typename _TreeIterator::_NodeTypes _NodeTypes;
    typedef typename _TreeIterator::__pointer_traits __pointer_traits;

    _TreeIterator __i_;

public:
    typedef bidirectional_iterator_tag iterator_category;
    typedef typename _NodeTypes::__map_value_type value_type;
    typedef typename _TreeIterator::difference_type difference_type;
    typedef const value_type& reference;
    typedef typename _NodeTypes::__const_map_value_type_pointer pointer;

    __map_const_iterator() throw() {}

    __map_const_iterator(_TreeIterator __i) throw() : __i_(__i) {}
    __map_const_iterator(__map_iterator<
        typename _TreeIterator::__non_const_iterator> __i) throw()
        : __i_(__i.__i_) {}

    reference operator*() const 
	{
		return __i_->__get_value();
	}
    pointer operator->() const 
	{
		return pointer_traits<pointer>::pointer_to(__i_->__get_value());
	}
    __map_const_iterator& operator++() {++__i_; return *this;}
    __map_const_iterator operator++(int)
    {
        __map_const_iterator __t(*this);
        ++(*this);
        return __t;
    }
    __map_const_iterator& operator--() {--__i_; return *this;}
    __map_const_iterator operator--(int)
    {
        __map_const_iterator __t(*this);
        --(*this);
        return __t;
    }

    friend bool operator==(const __map_const_iterator& __x, const __map_const_iterator& __y)
    {
		return __x.__i_ == __y.__i_;
	}
    friend bool operator!=(const __map_const_iterator& __x, const __map_const_iterator& __y)
    {
		return __x.__i_ != __y.__i_;
	}

    template <class, class, class, class> friend class map;
    template <class, class, class> friend class __tree_const_iterator;
};

} // namespace ft


#endif //__MAP_CONST_ITERATOR_HPP
