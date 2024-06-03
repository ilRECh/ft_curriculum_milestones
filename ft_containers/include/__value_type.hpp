#ifndef __VALUE_TYPE_HPP
#define __VALUE_TYPE_HPP

namespace ft {

template <class _Key, class _Tp>
struct __value_type
{
    typedef _Key                                     key_type;
    typedef _Tp                                      mapped_type;
    typedef ft::pair<const key_type, mapped_type>    value_type;

private:
    value_type __cc;

public:
    value_type& __get_value()
	{
		return __cc;
	}
    
	const value_type& __get_value() const
	{
		return __cc;
	}

private:
   __value_type();
   __value_type(__value_type const&);
   __value_type& operator=(__value_type const&);
   ~__value_type();
};

} // namespace ft

#endif //__VALUE_TYPE_HPP
