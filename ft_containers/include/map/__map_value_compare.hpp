#ifndef __MAP_VALUE_COMPARE_HPP
#define __MAP_VALUE_COMPARE_HPP

using std::is_empty;
using std::__libcpp_is_final;

namespace ft {

template <class _Key, class _CP, class _Compare,
          bool = is_empty<_Compare>::value && not __libcpp_is_final<_Compare>::value>
class __map_value_compare
    : private _Compare
{
public:
    __map_value_compare() : _Compare() {}
    __map_value_compare(_Compare c) : _Compare(c) {}
    const _Compare& key_comp() const {return *this;}
    bool operator()(const _CP& __x, const _CP& __y) const
	{
		return static_cast<const _Compare&>(*this)(__x.__get_value().first, __y.__get_value().first);
	}
    bool operator()(const _CP& __x, const _Key& __y) const
	{
		return static_cast<const _Compare&>(*this)(__x.__get_value().first, __y);
	}
	bool operator()(const _Key& __x, const _CP& __y) const
	{
		return static_cast<const _Compare&>(*this)(__x, __y.__get_value().first);
	}
    void swap(__map_value_compare&__y)
    {
      using std::swap;
      swap(static_cast<_Compare&>(*this), static_cast<_Compare&>(__y));
    }
};

}

#endif // __MAP_VALUE_COMPARE_HPP
