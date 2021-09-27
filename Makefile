SRCS	= ft_bzero.c\
		  ft_memccpy.c\
		  ft_memcpy.c\
		  ft_memset.c\
		  ft_memmove.c\
		  ft_memchr.c\
		  ft_memcmp.c\
		  ft_strlen.c\
		  ft_strlcpy.c\
		  ft_strlcat.c\
		  ft_strchr.c\
		  ft_strrchr.c\
		  ft_strnstr.c\
		  ft_strncmp.c\
		  ft_isspace.c\
		  ft_isdigit.c\
		  ft_atoi.c\
		  ft_isalpha.c\
		  ft_isalnum.c\
		  ft_isascii.c\
		  ft_isprint.c\
		  ft_toupper.c\
		  ft_tolower.c\
		  ft_strdup.c\
		  ft_strndup.c\
		  ft_calloc.c\
		  ft_substr.c\
		  ft_strjoin.c\
		  ft_strtrim.c\
		  ft_split.c\
		  ft_abs.c\
		  ft_itoa.c\
		  ft_strmapi.c\
		  ft_putchar_fd.c\
		  ft_putstr_fd.c\
		  ft_putendl_fd.c\
		  ft_putnbr_fd.c\
		  ft_lstnewS.c\
		  ft_lstadd_frontS.c\
		  ft_lstsizeS.c\
		  ft_lstlastS.c\
		  ft_lstadd_backS.c\
		  ft_lstdeloneS.c\
		  ft_lstclearS.c\
		  ft_lstiterS.c\
		  ft_lstmapS.c\
		  ft_lstnewD.c\
		  ft_lstadd_frontD.c\
		  ft_lstsizeD.c\
		  ft_lstlastD.c\
		  ft_lstadd_backD.c\
		  ft_lstdeloneD.c\
		  ft_lstclearD.c\
		  ft_lstiterD.c\
		  ft_lstmapD.c\
		  ft_lstfirstD.c\
		  ft_mergesort.c

OBJS	= $(SRCS:.c=.o)

HDRS	= libft.h

NAME	= libft.a

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
	@$(GCC) $(FLAGS) $< -o $@
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
