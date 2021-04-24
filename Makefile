NAME			= libftprintf.a

RM				= rm -rf
GCC				= gcc
AR				= ar -crs
FLAGS			= -Wall -Wextra -Werror -c

HDRS_LIST		= libft.h
HDRS_DIR		= ./includes/
HDRS			= $(addprefix $(HDRS_DIR), $(HDRS_LIST))
INCLUDES 		= -I $(HDRS_DIR)

LIBFT_LIST	=
LIBFT_DIR		= ./libft/
LIBFT			= $(addprefix $(LIBFT_DIR), $(LIBFT_LIST))

SRCS_LIST	= 	ft_printf.c
SRCS_DIR		= ./
SRCS			= $(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJS_LIST		= $(LIBFT_LIST:.c=.o) $(SRCS_LIST:.c=.o)
OBJS_DIR		= ./all_objs/
OBJS			= $(addprefix $(OBJS_DIR), $(OBJS_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

$(NAME): $(OBJS_DIR) $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

all: $(NAME)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c $(HDRS)
	$(GCC) $(FLAGS) $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "$(NAME): $(GREEN)$(OBJS_DIR) was created$(RESET)"

clean:
	$(RM) $(OBJS_DIR)
	@echo "$(NAME): $(RED)$(OBJS_DIR) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	$(RM) $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean all

.PHONY:	
			all clean fclean re 
