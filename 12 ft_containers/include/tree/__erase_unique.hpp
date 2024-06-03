#ifndef __erase_unique_HPP
#define __erase_unique_HPP

namespace ft {

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

} // namespace ft


#endif // __erase_unique_HPP
