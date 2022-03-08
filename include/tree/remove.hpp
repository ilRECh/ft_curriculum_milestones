#ifndef __TREE_REMOVE_HPP
#define __TREE_REMOVE_HPP

#include "tree.hpp"

namespace ft {
    
// template <class _Tp, class _Compare, class _Allocator>
// typename __tree<_Tp, _Compare, _Allocator>::__node_holder
// __tree<_Tp, _Compare, _Allocator>::remove(const_iterator __p) throw()
// {
//     __node_pointer __np = __p.__get_np();
//     if (__begin_node() == __p.__ptr_)
//     {
//         if (__np->__right_ != NULL)
//             __begin_node() = static_cast<__iter_pointer>(__np->__right_);
//         else
//             __begin_node() = static_cast<__iter_pointer>(__np->__parent_);
//     }
//     --size();
//     __tree_remove(__end_node()->__left_,
//                   static_cast<__node_base_pointer>(__np));
//     return __node_holder(__np, _Dp(__node_alloc(), true));
// }

} // namespace ft


#endif // __TREE_REMOVE_HPP
