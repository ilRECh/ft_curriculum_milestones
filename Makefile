OS 						=	$(shell uname)
NAME					=	minishell
RM						=	rm -rf
GCC						=	clang
AR						=	ar -crs

FLAGS					=	-Wall -Wextra -Werror -c -g

ifeq ($(OS), Linux)
READ_LINE_FLAGS			=	-lreadline
endif
ifeq ($(OS), Darwin)
READ_LINE_FLAGS			=	-L/Users/$(USER)/.brew/Cellar/readline/8.1/lib/ -lreadline
endif
FLAGS					=	-g -Wall -Wextra -Werror -c #$(READ_LINE_FLAGS)
# FLAGS					=	-Wall -Wextra -Werror -c -g $(READ_LINE_FLAGS)
# FLAGS					=	-Wall -Wextra -Werror -c -g -L/Users/$(USER)/.brew/opt/readline/lib -lreadline

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

HDRS_MINISHELL			=	minishell.h \
							parse.h

HDRS_MINISHELL_DIR		=	./includes/

HDRS_LIBFT				=	libft.h
HDRS_LIBFT_DIR			=	./libft/

HDRS					=	$(addprefix $(HDRS_MINISHELL_DIR), $(HDRS_MINISHELL)) \
							$(addprefix $(HDRS_LIBFT_DIR), $(HDRS_LIBFT))
INCLUDES 				=	-I $(HDRS_MINISHELL_DIR)\
							-I $(HDRS_LIBFT_DIR)

LIBFT_MAKE				=	./libft/
LIBFT					=	./libft/libft.a

BUILTIN_LIST			=	cd/cd.c \
							echo/echo.c \
							export/export.c \
							export/print_exp.c \
							env/env.c \
							pwd/pwd.c \
							unset/unset.c \
							exit/exit.c	
BUILTIN_DIR				=	./src/builtin/
BUILTIN					=	$(addprefix $(BUILTIN_DIR), $(BUILTIN_LIST))

EXEC_LIST				=	exec.c\
							exec_braces.c\
							exec_builtin.c\
							exec_cmd.c\
							find.c\
							ft_rdrct.c\
							in_and_out.c\
							openpipe.c\
							whatsupdoc.c\
							go_on_I_will_wait.c
							
EXEC_DIR				=	./src/exec/
EXEC					=	$(addprefix $(EXEC_DIR), $(EXEC_LIST))

ENVIRON_LIST			=	getvalue.c\
							setvalue.c
ENVIRON_DIR				=	./src/environ/
ENVIRON					=	$(addprefix $(ENVIRON_DIR), $(ENVIRON_LIST))


PARSE_LIST				=	dollar_get_env.c \
							parse.c \
							utils_parse.c \
							trimmer.c \
							split_sub_argutils.c \
							is_file_exists.c \
							ret_perr.c \
							pre_parser.c \
							is_split.c \
							parse_gen_fill.c \
							skiper.c \
							test_and_debug.c \
							get_command_line.c \
							args_fill.c \
							get_next_sp.c \
							lst_helper.c \
							is_builtins.c \
							free_parse.c \
							post_parser.c \
							short_utils.c

PARSE_DIR				=	./src/parse/
PARSE					=	$(addprefix $(PARSE_DIR), $(PARSE_LIST))

OBJS					=	$(BUILTIN:.c=.o) $(ENVIRON:.c=.o) $(PARSE:.c=.o) $(EXEC:.c=.o) main.o

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
	@$(GCC) $(OBJS) $(LIBFT) $(READ_LINE_FLAGS) -o $(NAME)
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
