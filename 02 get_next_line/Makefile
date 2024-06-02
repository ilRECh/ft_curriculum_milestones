SRCS	= get_next_line.c get_next_line_utils.c 

OBJS	= $(SRCS:.c=.o)

HDRS	= get_next_line.h

NAME	= gnl.a

RM	= rm -rf
GCC	= gcc
AR	= ar -crs
FLAGS	= -Wall -Wextra -Werror -c

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
	@$(GCC) $(FLAGS) $(INCLUDES) $< -o $@
	@echo  "$(GREEN).$(RESET)\c"

$(NAME):	$(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

all:		$(NAME)

re:			fclean all

clean:
	@$(RM) $(OBJS)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: 	clean
	@$(RM) $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
	
.PHONY:	
			all clean fclean re 