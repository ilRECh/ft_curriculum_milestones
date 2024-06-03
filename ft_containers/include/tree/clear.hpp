#ifndef tree_clear_HPP
#define tree_clear_HPP

namespace ft {

template <class _Tp, class _Compare, class _Allocator>
void __tree<_Tp, _Compare, _Allocator>::clear() throw()
{
    destroy(__get_root());
    size() = 0;
    __begin_node() = __end_node();
    __end_node()->__left_ = NULL;
}

} // namespace ft


#endif // tree_clear_HPP
