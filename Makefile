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
		  ft_strldup.c\
		  ft_calloc.c\
		  ft_substr.c\
		  ft_strjoin.c\
		  ft_strtrim.c\
		  ft_split.c\

OBJS	= $(SRCS:.c=.o)

HDRS	= libft.h

NAME	= libft.a

RM	= rm -rf

GCC	= gcc

AR	= ar -crs

FLAGS	= -Wall -Wextra -Werror

.c.o:
			$(GCC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(HDRS)
			$(AR) $(NAME) $(OBJS)

all:		$(NAME)

re:			clean fclean all		

clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)

.PHONY:	
			all clean fclean re
