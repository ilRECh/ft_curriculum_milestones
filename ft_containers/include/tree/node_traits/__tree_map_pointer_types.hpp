#ifndef __TREE_MAP_POINTER_TYPES_HPP
#define __TREE_MAP_POINTER_TYPES_HPP

#include "__tree_key_value_types.hpp"

namespace ft {    

template <class _Tp, class _AllocPtr, class _KVTypes = __tree_key_value_types<_Tp>,
         bool = _KVTypes::__is_map>
struct __tree_map_pointer_types {};

template <class _Tp, class _AllocPtr, class _KVTypes>
struct __tree_map_pointer_types<_Tp, _AllocPtr, _KVTypes, true> {
  typedef typename _KVTypes::__map_value_type   _Mv;
  typedef typename std::__rebind_pointer<_AllocPtr, _Mv>::type
                                                       __map_value_type_pointer;
  typedef typename std::__rebind_pointer<_AllocPtr, const _Mv>::type
                                                 __const_map_value_type_pointer;
};


} // namespace ft


#endif //__TREE_MAP_POINTER_TYPES_HPP
