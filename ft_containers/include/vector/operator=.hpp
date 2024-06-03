#ifndef VECTOR_OPERATOR_EQ_HPP
#define VECTOR_OPERATOR_EQ_HPP

#include "../../vector.hpp"

namespace ft {

template <class _Tp, class _Allocator>
inline ft::vector<_Tp, _Allocator>&
ft::vector<_Tp, _Allocator>::operator=(const vector& __x)
{
    if (this != &__x)
    {
        __base::__copy_assign_alloc(__x);
        assign(__x.__begin_, __x.__end_);
    }
    return *this;
}

} // namespace ft


#endif // VECTOR_OPERATOR_EQ_HPP
