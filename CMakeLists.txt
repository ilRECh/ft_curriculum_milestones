cmake_minimum_required(VERSION 3.19)
project(ft_printf_clion C)

set(CMAKE_C_STANDARD 99)

set(LIBFT_DIR libft)
set(PRSR_DIR parser)
set(HDRS_DIR includes)

set(
        LIBFT_SRCS
        libft/ft_strchr.c
        libft/ft_atoi.c
        libft/ft_isdigit.c
        libft/ft_isspace.c
        libft/ft_strlen.c
        libft/fill_with.c
        libft/ft_putnbr_base.c
        libft/ft_abs.c
        libft/count_symbs.c)

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
        out_funcs/pointer_print.c out_funcs/digit_print.c)

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