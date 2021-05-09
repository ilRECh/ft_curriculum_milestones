cmake_minimum_required(VERSION 3.17)
project(ft_printf_clion C)

set(CMAKE_C_STANDARD 99)

set(LIBFT_DIR libft)
set(PRSR_DIR parser)
set(HDRS_DIR includes)

set(
        LIBFT_SRCS
        libft/ft_strchr.c
        libft/ft_atoi.c
        libft/ft_calloc.c
        libft/ft_bzero.c
        libft/ft_isdigit.c
        libft/ft_isspace.c
        libft/ft_strlen.c
        libft/fill_with.c
        libft/ft_putnbr_base.c
        libft/ft_abs.c
        libft/count_symbs.c
        libft/ft_lstadd_front.c
        libft/ft_lstnew.c
        libft/ft_lstnormalizer.c
        libft/ft_lstclear.c
        libft/ft_lstlast.c
        libft/ft_power.c
        libft/ft_bignummultiply.c
        libft/ft_bignumaddition.c libft/ft_lstfirst.c)

set(
        PRSR_SRCS
        parser/ft_vprintf.c
        parser/specifier_parse.c
        parser/flags_parse.c
        parser/width_parse.c
        parser/precision_parse.c
        parser/size_parse.c
)

set(
        OUT_FUNCS
        out_funcs/char_print.c
        out_funcs/out_funcs.c
        out_funcs/str_print.c
        out_funcs/pointer_print.c
        out_funcs/digit_print.c
        out_funcs/u_digit_print.c
        out_funcs/hex_print.c
        out_funcs/fe_print.c
        out_funcs/fge_special_cases.c
        out_funcs/g_print.c
        out_funcs/ft_putdouble.c
        out_funcs/ft_double_as_bignum.c out_funcs/ft_round_decimal.c out_funcs/ft_int_dec_symbs_counter.c out_funcs/ft_putexp.c)

set(
        HDRS
        includes/parser.h
        includes/libft.h
        includes/ft_stdio.h
        includes/out_funcs.h)

include_directories(${LIBFT_DIR})
include_directories(${PRSR_DIR})
include_directories(${HDRS_DIR})

set (
        SRCS
        ft_printf.c
        main.c
        ${PRSR_SRCS}
        ${HDRS}
        ${LIBFT_SRCS}
        ${OUT_FUNCS}
)

add_executable(ft_printf_clion ${SRCS})