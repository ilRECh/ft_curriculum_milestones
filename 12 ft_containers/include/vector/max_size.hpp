#ifndef max_size_HPP
#define max_size_HPP

#include "../../vector.hpp"

namespace ft {

template <class _Tp, class _Allocator>
typename ft::vector<_Tp, _Allocator>::size_type
ft::vector<_Tp, _Allocator>::max_size() const throw()
{
    return std::min<size_type>(__alloc_traits::max_size(this->__alloc()),
                                 std::numeric_limits<difference_type>::max());
}

} // namespace ft


#endif // max_size_HPP
