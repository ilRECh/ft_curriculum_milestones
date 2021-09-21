.PHONY:	
	all clean fclean re

NAME					=	philo
RM						=	rm -rf
GCC						=	gcc
AR						=	ar -crs
FLAGS					=	-Wall -Wextra -Werror -c -g

HDRS_PHILO				=	philo.h							

HDRS_PHILO_DIR			=	./includes/

HDRS					=	$(addprefix $(HDRS_PHILO_DIR), $(HDRS_PHILO))
							
INCLUDES 				=	-I $(HDRS_PHILO_DIR)

SRC_LIST				=	philo.c \
							sit_down_please.c \
							life.c \
							time.c \
							msg.c \
							watchdog.c
SRC_DIR					=	./src/
SRC						=	$(addprefix $(SRC_DIR), $(SRC_LIST)) main.c

OBJS					=	$(SRC:.c=.o)

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
	@$(GCC) $(FLAGS) $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

all: $(NAME)

$(NAME): $(OBJS)
	@$(GCC) $(OBJS) -lpthread -o $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

clean:
	@$(RM) $(OBJS)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean:
	@$(RM) $(OBJS)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"
	@$(RM) $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean all
