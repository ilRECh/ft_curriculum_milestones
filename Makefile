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

BONUS_SRCS	= ft_lstnew.c\
			  ft_lstadd_front.c\
			  ft_lstsize.c\
			  ft_lstlast.c\
			  ft_lstadd_back.c\
			  ft_lstdelone.c\
			  ft_lstclear.c\
			  ft_lstiter.c\
			  ft_lstmap.c\

OBJS	= $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

HDRS	= libft.h

NAME	= libft.a

RM	= rm -rf

GCC	= gcc

AR	= ar -crs

FLAGS	= -Wall -Wextra -Werror

%.o : %.c   $(HDRS)
			$(GCC) $(FLAGS) -I includes -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

all:		$(NAME)

bonus:		$(NAME) $(OBJS) $(BONUS_OBJS)
			$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)

re:			clean fclean all

clean:
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean: 	clean
			$(RM) $(NAME)

.PHONY:	
			all clean fclean re bonus
