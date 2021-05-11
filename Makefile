NAME			= libftprintf.a

RM				= rm -rf
GCC				= gcc
AR				= ar -crs
FLAGS			= -Wall -Wextra -Werror -c
INCLUDES 		= -I $(HDRS_DIR)

HDRS_LIST		= libft.h\
			  parser.h\
			  out_funcs.h
HDRS_DIR		= ./includes/
HDRS			= $(addprefix $(HDRS_DIR), $(HDRS_LIST)) ft_printf.h

LIBFT_LIST	=	ft_strchr.c\
				ft_atoi.c\
				ft_isdigit.c\
				ft_isspace.c\
				ft_strlen.c\
				fill_with.c\
				count_symbs.c\
				ft_putnbr_base.c\
				ft_calloc.c\
				ft_bzero.c\
				ft_abs.c\
				ft_lstadd_front.c\
				ft_lstnew.c\
				ft_lstnormalizer.c\
				ft_lstclear.c\
				ft_lstlast.c\
				ft_power.c\
				ft_bignummultiply.c\
				ft_bignumaddition.c
LIBFT_DIR		= ./libft/
LIBFT			= $(addprefix $(LIBFT_DIR), $(LIBFT_LIST))

SRCS_LIST	= 	ft_printf.c
SRCS_DIR		= ./
SRCS			= $(addprefix $(SRCS_DIR), $(SRCS_LIST))

OUT_LIST	=	s_print.c\
				c_print.c\
				p_print.c\
				di_print.c\
				u_d_print.c\
				xX_print.c\
				feg_print.c\
				feg_special_cases.c\
				g_print.c\
				ft_double_as_bignum.c\
				ft_putdouble.c\
				ft_round_decimal.c\
				ft_int_dec_symbs_counter.c\
				ft_putexp.c\
				out_funcs.c
OUT_DIR			= ./out_funcs/
OUT				= $(addprefix $(OUT_DIR), $(OUT_LIST))

PRSR_LIST	=	ft_vprintf.c\
				specifier_parse.c\
				flags_parse.c\
				width_parse.c\
				precision_parse.c\
				size_parse.c

PRSR_DIR		= ./parser/
PRSR			= $(addprefix $(PRSR_DIR), $(PRSR_LIST))

OBJS			= $(OUT:.c=.o) $(PRSR:.c=.o) $(LIBFT:.c=.o) $(SRCS:.c=.o)

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

all: $(NAME)

bonus: all

%.o : %.c $(HDRS)
	@$(GCC) $(FLAGS) $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

clean:
	@$(RM) $(OBJS)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@$(RM) $(NAME) $(OBJS_DIR)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean all

.PHONY:	
			all clean fclean re 
