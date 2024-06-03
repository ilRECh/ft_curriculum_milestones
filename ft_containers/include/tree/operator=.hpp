#ifndef tree_operator_eq_HPP
#define tree_operator_eq_HPP

#include "__assign_multi.hpp"

namespace ft {

template <class _Tp, class _Compare, class _Allocator>
ft::__tree<_Tp, _Compare, _Allocator>&
ft::__tree<_Tp, _Compare, _Allocator>::operator=(const ft::__tree<_Tp, _Compare, _Allocator>& __t)
{
    if (this != &__t)
    {
        value_comp() = __t.value_comp();
        __copy_assign_alloc(__t);
        __assign_multi(__t.begin(), __t.end());
    }
    return *this;
}

} // namespace ft


#endif // tree_operator_eq_HPP
