OS 						=	$(shell uname)
NAME					=	minishell
RM						=	rm -rf
GCC						=	clang
AR						=	ar -crs
FLAGS					=	-Wall -Wextra -Werror -c -g

# ifeq ($(OS), Linux)
# 	MLX_ARC = libmlx.a
# 	MLX_DIR = minilibx/minilibx_linux/
# 	OPENGL = -lm -lbsd -lX11 -lXext
# endif
# ifeq ($(OS), Darwin)
# 	MLX_ARC = libmlx.dylib
# 	MLX_DIR = minilibx/minilibx_mac/
# 	OPENGL = -lz -framework OpenGL -framework AppKit
# endif

HDRS_MINISHELL			=	minishell.h
HDRS_MINISHELL_DIR		=	./includes/

HDRS_LIBFT				=	libft.h
HDRS_LIBFT_DIR			=	./libft/

HDRS					=	$(addprefix $(HDRS_MINISHELL_DIR), $(HDRS_MINISHELL)) \
							$(addprefix $(HDRS_LIBFT_DIR), $(HDRS_LIBFT))
INCLUDES 				=	-I $(HDRS_MINISHELL_DIR)\
							-I $(HDRS_LIBFT_DIR)

LIBFT_MAKE				=	./libft/
LIBFT					=	./libft/libft.a

SRCS_LIST				= 
SRCS_DIR				=	./srcs/
SRCS					=	$(addprefix $(SRCS_DIR), $(SRCS_LIST)) main.c

OBJS					=	$(SRCS:.c=.o)

# COLORS
BLACK					=	\033[0;30m
RED						=	\033[0;31m
GREEN					=	\033[0;32m
YELLOW					=	\033[0;33m
BLUE					=	\033[0;34m
MAGENTA					=	\033[0;35m
CYAN					=	\033[0;36m
RESET					=	\033[0m

%.o : %.c $(HDRS)
	@$(GCC) $(FLAGS) $(INCLUDES)  $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(NAME): $(LIBFT) $(OBJS)
	@$(GCC) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

all: $(NAME)

libs: 
	@make -C $(LIBFT_MAKE)

clean:
	@$(RM) $(OBJS)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean:
	@say -v Yuri 'I guess I die'
	@$(RM) $(OBJS)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"
	@$(RM) $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

libs_clean:
	@make -C $(LIBFT_MAKE) clean

libs_fclean:
	@make -C $(LIBFT_MAKE) fclean

re: fclean all

.PHONY:	
			all clean fclean re
