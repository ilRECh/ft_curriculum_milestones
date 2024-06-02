NAME			= push_swap

RM				= rm -rf
GCC				= gcc
AR				= ar -crs
FLAGS			= -Wall -Wextra -Werror -c

HDRS_PUSH_SWAP			=	push_swap.h
HDRS_PUSH_SWAP_DIR		=	./includes/

HDRS_LIBFT				=	libft.h
HDRS_LIBFT_DIR			=	./libft/

HDRS_FT_PRINTF			=	ft_printf.h
HDRS_FT_PRINTF_DIR		=	./ft_printf/

HDRS			=	$(addprefix $(HDRS_PUSH_SWAP_DIR), $(HDRS_PUSH_SWAP)) \
					$(addprefix $(HDRS_LIBFT_DIR), $(HDRS_LIBFT)) \
					$(addprefix $(HDRS_FT_PRINTF_DIR), $(HDRS_FT_PRINTF))
INCLUDES 		= -I$(HDRS_PUSH_SWAP_DIR) -I$(HDRS_LIBFT_DIR) -I$(HDRS_FT_PRINTF_DIR)


LIBFT_MAKE			= ./libft/
LIBFT				= ./libft/libft.a
FT_PRINTF_MAKE		= ./ft_printf/
FT_PRINTF		= ./ft_printf/libftprintf.a

SRCS_LIST	=	print_stacks.c\
				not_keep_elem_count.c\
				is_sort.c\
				clear_keep.c\
				find_smaller_and_bigger.c\
				index_check.c
SRCS_DIR		= ./srcs/
SRCS			= $(addprefix $(SRCS_DIR), $(SRCS_LIST)) main.c

PRSR_LIST	=	args_check.c\
				expand_args.c
PRSR_DIR		= ./parser/
PRSR			= $(addprefix $(PRSR_DIR), $(PRSR_LIST))

ACTIONS_LIST	=	actions.c\
					align.c
ACTIONS_DIR		= ./actions/
ACTIONS			= $(addprefix $(ACTIONS_DIR), $(ACTIONS_LIST))

DIVIDE_LIST	=	divide.c\
				mark.c
DIVIDE_DIR		= ./divide/
DIVIDE			= $(addprefix $(DIVIDE_DIR), $(DIVIDE_LIST))

MERGE_LIST	=	merge.c
MERGE_DIR		= ./merge/
MERGE			= $(addprefix $(MERGE_DIR), $(MERGE_LIST))

OBJS			= $(SRCS:.c=.o) $(PRSR:.c=.o) $(ACTIONS:.c=.o) $(DIVIDE:.c=.o) $(MERGE:.c=.o) 

# COLORS
BLACK	=	\033[0;30m
RED		=	\033[0;31m
GREEN	=	\033[0;32m
YELLOW	=	\033[0;33m
BLUE	=	\033[0;34m
MAGENTA	=	\033[0;35m
CYAN	=	\033[0;36m
RESET	=	\033[0m

%.o : %.c $(HDRS)
	@$(GCC) $(FLAGS) $(INCLUDES)  $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJS) 
	@$(GCC) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_MAKE)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_MAKE)

clean:
	@$(RM) $(OBJS) $(LIBFT) $(FT_PRINTF)
	@make -C $(LIBFT_MAKE) clean
	@make -C $(FT_PRINTF_MAKE) clean
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean:
	@make -C $(LIBFT_MAKE) fclean
	@make -C $(FT_PRINTF_MAKE) fclean
	@$(RM) $(OBJS) $(LIBFT) $(FT_PRINTF)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"
	@$(RM) $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean all

.PHONY:	
			all clean fclean re 
