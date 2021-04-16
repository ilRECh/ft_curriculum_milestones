SRCS	= ft_memset.c ft_bzero.c

HDRS	= libft.h

OBJS	= $(SRCS:.c=.o)

NAME	= libft.a

RM		= rm -rf

GCC		= gcc

AR		= ar -crs

FLAGS	= -Wall -Wextra -Werror

.c.o:
			$(GCC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(HEADERS)
			$(AR) $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean clean all


.PHONY:		all clean fclean re
