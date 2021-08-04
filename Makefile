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

BUILTIN_LIST			=	cd/cd.c
# export/export.c\
# echo/echo.c\
# pwd/pwd.c\
# unset/unset.c
BUILTIN_DIR				=	./src/builtin/
BUILTIN					=	$(addprefix $(BUILTIN_DIR), $(BUILTIN_LIST))

ENVIRON_LIST			=	getvalue.c\
							setvalue.c
ENVIRON_DIR				=	./src/environ/
ENVIRON					=	$(addprefix $(ENVIRON_DIR), $(ENVIRON_LIST))

OBJS					=	$(BUILTIN:.c=.o) $(ENVIRON:.c=.o) main.o

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

all: libs $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(GCC) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

libs: 
	@make -C $(LIBFT_MAKE)

clean: libs_clean
	@$(RM) $(OBJS)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: libs_fclean
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

pars:
	clear
	gcc -g -Iincludes main.c -Ilibft libft/*.c -Isrc/parse/ src/parse/*.c
pars2: pars
	./a.out "echo \"$PWD kkk00;00\" > a > b;echo \"00;00\" > a > b"