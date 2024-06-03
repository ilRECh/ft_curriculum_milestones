#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

namespace ft {

// enable_if
template<bool, typename Type = void>
struct enable_if
{};
template<typename Type>
struct enable_if<true, Type>
{
    typedef Type type;
};

// is_integral
template<typename Type, Type __v>
struct integral_constant
{
    static const Type                      value = __v;
    typedef Type                           value_type;
    typedef integral_constant<Type, __v>   type;
    operator value_type() const throw()
    {
        Type tmp = value;
        (void)tmp;
        return value;
    }
};
/// typedef for true_type
typedef integral_constant<bool, true>     true_type;
/// typedef for false_type
typedef integral_constant<bool, false>    false_type;

/// remove_const
template<typename _Tp>
struct remove_const
{ typedef _Tp     type; };
template<typename _Tp>
struct remove_const<_Tp const>
{ typedef _Tp     type; };

/// remove_volatile
template<typename _Tp>
struct remove_volatile
{
	typedef _Tp     type;
};

template<typename _Tp>
struct remove_volatile<_Tp volatile>
{
	typedef _Tp     type;
};

/// remove_cv
template<typename _Tp>
struct remove_cv
{
    typedef typename
    remove_const<typename remove_volatile<_Tp>::type>::type     type;
};

template<typename>
struct is_integral_helper : public false_type { };
template<> struct is_integral_helper<bool> : public integral_constant<bool, true> { };
template<> struct is_integral_helper<char> : public integral_constant<bool, true> { };
template<> struct is_integral_helper<signed char> : public integral_constant<bool, true> { };
template<> struct is_integral_helper<unsigned char> : public integral_constant<bool, true> { };
template<> struct is_integral_helper<short> : public integral_constant<bool, true> { };
template<> struct is_integral_helper<unsigned short> : public integral_constant<bool, true> { };
template<> struct is_integral_helper<int> : public integral_constant<bool, true> { };
template<> struct is_integral_helper<unsigned int> : public integral_constant<bool, true> { };
template<> struct is_integral_helper<long> : public integral_constant<bool, true> { };
template<> struct is_integral_helper<unsigned long> : public integral_constant<bool, true> { };
template<> struct is_integral_helper<long long> : public integral_constant<bool, true> { };
template<> struct is_integral_helper<unsigned long long> : public integral_constant<bool, true> { };
template<> struct is_integral_helper<wchar_t> : public integral_constant<bool, true> { };
template<> struct is_integral_helper<char16_t> : public integral_constant<bool, true> { };
template<typename _Tp>
struct is_integral : public integral_constant<bool, (is_integral_helper<typename remove_cv<_Tp>::type>::value)>
{};

template <bool _Bp, class _If, class _Then>
    struct conditional {typedef _If type;};
template <class _If, class _Then>
    struct conditional<false, _If, _Then> {typedef _Then type;};

};

#endif //TYPE_TRAITS_HPP
