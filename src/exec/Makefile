NAME			= pipex

RM				= rm -rf
GCC				= gcc
AR				= ar -crs
FLAGS			= -Wall -Wextra -Werror -c

HDRS_PIPEX			=	pipex.h
HDRS_PIPEX_DIR		=	./

HDRS_LIBFT				=	libft.h
HDRS_LIBFT_DIR			=	./libft/

HDRS_FT_PRINTF			=	ft_printf.h
HDRS_FT_PRINTF_DIR		=	./ft_printf/

HDRS			=	$(addprefix $(HDRS_PIPEX_DIR), $(HDRS_PIPEX)) \
					$(addprefix $(HDRS_LIBFT_DIR), $(HDRS_LIBFT)) \
					$(addprefix $(HDRS_FT_PRINTF_DIR), $(HDRS_FT_PRINTF))
INCLUDES 		= -I$(HDRS_PIPEX_DIR)\
					-I$(HDRS_LIBFT_DIR)\
					-I$(HDRS_FT_PRINTF_DIR)


LIBFT_MAKE			= ./libft/
LIBFT				= ./libft/libft.a
FT_PRINTF_MAKE		= ./ft_printf/
FT_PRINTF			= ./ft_printf/libftprintf.a

SRCS_LIST		= pipex.c\
					cleaning.c\
					exec_cmd.c
SRCS_DIR		= ./srcs/
SRCS			= $(addprefix $(SRCS_DIR), $(SRCS_LIST)) main.c

OBJS			= $(SRCS:.c=.o)

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

all: LIBFT_CREAT FT_PRINTF_CREAT $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJS)
	@$(GCC) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

LIBFT_CREAT:
	@make -C $(LIBFT_MAKE)

FT_PRINTF_CREAT:
	@make -C $(FT_PRINTF_MAKE)

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_MAKE) clean
	@make -C $(FT_PRINTF_MAKE) clean
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean:
	@make -C $(LIBFT_MAKE) fclean
	@make -C $(FT_PRINTF_MAKE) fclean
	@$(RM) $(OBJS)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"
	@$(RM) $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean all

.PHONY:	
			all clean fclean re 
