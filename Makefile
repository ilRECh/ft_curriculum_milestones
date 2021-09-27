.PHONY:	
			all clean fclean re

OS 						=	$(shell uname)
NAME					=	cub3d
RM						=	rm -rf
GCC						=	gcc
AR						=	ar -crs
FLAGS					=	-Wall -Wextra -Werror -c -g

HDRS_CUB				=	cub3d.h						
HDRS_CUB_DIR			=	./include/

HDRS_LIBFT				=	libft.h
HDRS_LIBFT_DIR			=	./src/libft/

HDRS_GNL				= 	get_next_line.h 
HDRS_GNL_DIR			=	./src/get_next_line/

HDRS					=	$(addprefix $(HDRS_CUB_DIR), $(HDRS_CUB)) \
							$(addprefix $(HDRS_LIBFT_DIR), $(HDRS_LIBFT)) \
							$(addprefix $(HDRS_GNL_DIR), $(HDRS_GNL))
							
INCLUDES 				=	-I $(HDRS_CUB_DIR)\
							-I $(HDRS_LIBFT_DIR)\
							-I $(HDRS_GNL_DIR)

GNL_MAKE				=	./src/get_next_line/
GNL						=	./src/get_next_line/gnl.a
LIBFT_MAKE				=	./src/libft/
LIBFT					=	./src/libft/libft.a

PARSE_LIST				=	
PARSE_DIR				=	./src/parse/
PARSE					=	$(addprefix $(PARSE_DIR), $(PARSE_LIST))

OBJS					=	$(PARSE:.c=.o) main.o

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
	@$(GCC) $(OBJS) $(LIBFT) $(GNL) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

libs: 
	@make -C $(GNL_MAKE)
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
	@make -C $(GNL_MAKE) clean
	@make -C $(LIBFT_MAKE) clean

libs_fclean:
	@make -C $(GNL_MAKE) fclean
	@make -C $(LIBFT_MAKE) fclean

re: fclean all