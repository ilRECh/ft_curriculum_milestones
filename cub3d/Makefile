.PHONY:	
			all clean fclean re

OS 						=	$(shell uname)
NAME					=	cub3d
RM						=	rm -rf
GCC						=	gcc
AR						=	ar -crs
FLAGS					=	-Wall -Wextra -Werror -c

ifeq ($(OS), Darwin)
LINKS += -framework OpenGL -framework AppKit
else ifeq ($(OS), Linux)
LINKS += -L./srcs/minilibx -lmlx -L/usr/lib -I./srcs/minilibx -lXext -lX11 -lm -lz
else
$(error OS is not defined, because uname didn't work)
endif

HDRS_CUB				=	cub3d.h						
HDRS_CUB_DIR			=	./include/

HDRS_LIBFT				=	libft.h
HDRS_LIBFT_DIR			=	./srcs/libft/

HDRS_GNL				= 	get_next_line.h 
HDRS_GNL_DIR			=	./srcs/get_next_line/

HDRS_MLX				= 	mlx.h 
HDRS_MLX_DIR			=	./srcs/minilibx/

HDRS					=	$(addprefix $(HDRS_CUB_DIR), $(HDRS_CUB)) \
							$(addprefix $(HDRS_LIBFT_DIR), $(HDRS_LIBFT)) \
							$(addprefix $(HDRS_GNL_DIR), $(HDRS_GNL))\
							$(addprefix $(HDRS_MLX_DIR), $(HDRS_MLX))
							
INCLUDES 				=	-I $(HDRS_CUB_DIR)\
							-I $(HDRS_LIBFT_DIR)\
							-I $(HDRS_GNL_DIR)\
							-I $(HDRS_MLX_DIR)\
							-I /usr/include

MLX_MAKE				=	./srcs/minilibx/
MLX						=	./srcs/minilibx/libmlx.a
GNL_MAKE				=	./srcs/get_next_line/
GNL						=	./srcs/get_next_line/gnl.a
LIBFT_MAKE				=	./srcs/libft/
LIBFT					=	./srcs/libft/libft.a

GAME_ENGINE_LIST		=	colors.c\
							draw_mini_map.c\
							draw_perspective_wall.c\
							draw_perspective.c\
							game.c\
							image_functions.c\
							image_maker.c\
							init.c\
							key_handler.c\
							pixel_get_put_color.c\
							player_on_map.c\
							set_plr_full.c\
							utils_dpoint_math.c\
							utils_dpoint.c\
							utils_int.c\
							utils_point_math.c\
							utils_point.c\
							utils_trigonometry.c\
							wrappers.c\
							start_game.c\

GAME_ENGINE_DIR			=	srcs/game_engine/
GAME_ENGINE				=	$(addprefix $(GAME_ENGINE_DIR), $(GAME_ENGINE_LIST))

PARSE_LIST				=	parse.c\
							setup_all.c\
							cleaning.c\
							setup_params/setup_params.c\
							setup_params/setup_params_additional.c\
							setup_params/setup_missing.c\
							setup_map/setup_map.c\
							setup_map/check_symbols.c\
							setup_map/make_map_from_lst.c\
							setup_map/spaces_to_walls.c\
							setup_map/check_closed.c\
							setup_map/check_extra_regions.c
PARSE_DIR				=	./srcs/parse/
PARSE					=	$(addprefix $(PARSE_DIR), $(PARSE_LIST))

OBJS					=	$(PARSE:.c=.o) main.o $(GAME_ENGINE:.c=.o)

%.o : %.c $(HDRS)
	$(GCC) $(FLAGS) $(INCLUDES) $< -o $@

all: libs $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(GCC) $(OBJS) $(LIBFT) $(GNL) $(MLX) -o $(NAME) $(LINKS)

libs: 
	make -C $(GNL_MAKE)
	@if [ -d $(HDRS_MLX_DIR) ];\
	then\
		echo minilibx exists;\
	else\
		echo minilibx does not exist;\
		echo git clone https://github.com/42Paris/minilibx-linux.git srcs/minilibx;\
		git clone https://github.com/42Paris/minilibx-linux.git srcs/minilibx;\
	fi;
	make -C $(LIBFT_MAKE)
	make -C $(MLX_MAKE)

clean: libs_clean
	$(RM) $(OBJS)

fclean: libs_fclean
	$(RM) $(OBJS)
	$(RM) $(NAME)

libs_clean:
	make -C $(GNL_MAKE) clean
	make -C $(LIBFT_MAKE) clean
	@if [ -d $(HDRS_MLX_DIR) ];\
	then\
		make -C $(MLX_MAKE) clean;\
	else\
		echo minilibx does not exist;\
	fi;


libs_fclean: libs_clean
	make -C $(GNL_MAKE) fclean
	make -C $(LIBFT_MAKE) fclean
	
re: fclean all
