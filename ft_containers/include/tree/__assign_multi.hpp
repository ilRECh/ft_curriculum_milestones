#ifndef __assign_multi_HPP
#define __assign_multi_HPP

#include "__node_insert_multi.hpp"
#include "__insert_multi.hpp"
#include "detach.hpp"

namespace ft {

template <class _Tp, class _Compare, class _Allocator>
template <class _InputIterator>
void
ft::__tree<_Tp, _Compare, _Allocator>::__assign_multi(_InputIterator __first, _InputIterator __last)
{
    typedef iterator_traits<_InputIterator> _ITraits;
    typedef typename _ITraits::value_type _ItValueType;
    static_assert((std::is_same<_ItValueType, __container_value_type>::value ||
                  std::is_same<_ItValueType, __node_value_type>::value),
                  "__assign_multi may only be called with the containers value type"
                  " or the nodes value type");
    if (size() != 0)
    {
        __node_pointer __cache = __detach();
        try
        {
            for (; __cache != NULL && __first != __last; ++__first)
            {
                __cache->__value_ = *__first;
                __node_pointer __next = __detach(__cache);
                __node_insert_multi(__cache);
                __cache = __next;
            }
        }
        catch (...)
        {
            while (__cache->__parent_ != NULL)
                __cache = static_cast<__node_pointer>(__cache->__parent_);
            destroy(__cache);
            throw;
        }
        if (__cache != NULL)
        {
            while (__cache->__parent_ != NULL)
                __cache = static_cast<__node_pointer>(__cache->__parent_);
            destroy(__cache);
        }
    }
    for (; __first != __last; ++__first)
        __insert_multi(_NodeTypes::__get_value(*__first));
}

} // namespace ft


#endif // __assign_multi_HPP
