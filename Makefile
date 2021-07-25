OS 				= $(shell uname)
NAME			= fdf
RM				= rm -rf
GCC				= clang
AR				= ar -crs
FLAGS			= -Wall -Wextra -Werror -c -g

ifeq ($(OS), Linux)
	MLX_DIR = minilibx/minilibx_linux/
	OPENGL = -lm -lbsd -lX11 -lXext
endif
ifeq ($(OS), Darwin)
	MLX_DIR = minilibx/minilibx_mac/
	OPENGL = -lz -framework OpenGL -framework AppKit
endif

HDRS_FDF			=	fdf.h\
						color.h\
						put_pixel.h\
						mouse.h
HDRS_FDF_DIR		=	./includes/

HDRS_LIBFT				=	libft.h
HDRS_LIBFT_DIR			=	./libft/

HDRS_FT_PRINTF			=	ft_printf.h
HDRS_FT_PRINTF_DIR		=	./ft_printf/

HDRS_MLX				= mlx.h 
HDRS_MLX_DIR			= $(MLX_DIR)

HDRS			=	$(addprefix $(HDRS_FDF_DIR), $(HDRS_FDF)) \
					$(addprefix $(HDRS_LIBFT_DIR), $(HDRS_LIBFT)) \
					$(addprefix $(HDRS_FT_PRINTF_DIR), $(HDRS_FT_PRINTF))\
					$(addprefix $(HDRS_MLX_DIR), $(HDRS_MLX))
INCLUDES 		= -I $(HDRS_FDF_DIR)\
					-I $(HDRS_LIBFT_DIR)\
					-I $(HDRS_FT_PRINTF_DIR)\
					-I $(HDRS_MLX_DIR)


LIBFT_MAKE			= ./libft/
LIBFT				= ./libft/libft.a
FT_PRINTF_MAKE		= ./ft_printf/
FT_PRINTF			= ./ft_printf/libftprintf.a
MLX_MAKE			= $(MLX_DIR)
MLX					= $(addprefix $(MLX_DIR), libmlx.a)
GNL_MAKE			= ./get_next_line/
GNL					= ./get_next_line/gnl.a

SRCS_LIST		= fdf.c\
					draw.c\
					projections.c\
					hooks_setup.c\
					translate.c\
					scale.c\
					central_point.c
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

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJS)
	@$(GCC) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX) $(GNL) \
	$(OPENGL) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

all: $(NAME)

libs: 
	@make -C $(LIBFT_MAKE)
	@make -C $(FT_PRINTF_MAKE)
	@make -C $(MLX_MAKE)
	@make -C $(GNL_MAKE)

clean:
	@$(RM) $(OBJS)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean:
	@$(RM) $(OBJS)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"
	@$(RM) $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

libs_clean:
	@make -C $(LIBFT_MAKE) clean
	@make -C $(FT_PRINTF_MAKE) clean
	@make -C $(MLX_MAKE) clean
	@make -C $(GNL_MAKE) clean

libs_fclean:
	@make -C $(LIBFT_MAKE) fclean
	@make -C $(FT_PRINTF_MAKE) fclean
	@make -C $(GNL_MAKE) fclean

re: fclean all

.PHONY:	
			all clean fclean re 
